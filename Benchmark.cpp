/*
 * Benchmark.cpp
 *
 *  Created on: Nov 11, 2019
 *      Author: joseph
 */

#include "Benchmark.h"

void producerTask(void * params) {

	Computation *comp = (Computation*) params;

	comp->compute();
	yield();

	delete comp;

	vTaskDelete( NULL );
}

Benchmark::Benchmark(int durationCycles, int coolDownTimer, int queueSize) {
	this->durationCycles = durationCycles > 0 ? durationCycles : 4;
	this->coolDownTimer = coolDownTimer > 0 ? coolDownTimer : 1500;

	this->upperLimitSum = 50000;
	this->upperLimitMul = 10000;

	queue = new QueueHandle_t();
	this->queueSize = queueSize;

	*queue = xQueueCreate( queueSize, sizeof( long ) );

	maxNumOfThreads = queueSize;
}

Benchmark::~Benchmark() {
	Serial.println();

	delete queue;
}

int Benchmark::getUpperLimitMul() {
	return upperLimitMul;
}

void Benchmark::setUpperLimitMul(int upperLimitMul) {
	this->upperLimitMul = upperLimitMul;
}

int Benchmark::getUpperLimitSum() {
	return upperLimitSum;
}

void Benchmark::setUpperLimitSum(int upperLimitSum) {
	this->upperLimitSum = upperLimitSum;
}

void Benchmark::setMaxNumOfThreads(int maxNumOfThreads) {
	this->maxNumOfThreads = maxNumOfThreads;
}

float Benchmark::performBenchmark(int numOfThreads) {
	delay(coolDownTimer);

	if (numOfThreads > maxNumOfThreads) {
		Serial.println("[bench] error: Number of maximal threads reached!");
		Serial.print("[bench] error: running with maxNumOfThreads => ");
		Serial.println(maxNumOfThreads);
		return runComputationWith(maxNumOfThreads, durationCycles);
	} else {
		return runComputationWith(numOfThreads, durationCycles);
	}
}

float Benchmark::runComputationWith(int numOfThreads, int numOfCycles) {
	long average = 0;
	long result = 0;

	for (int i = 0; i < numOfCycles; i++) {

		// declarations
		Computation *c[numOfThreads];

		/*
		 * =============================================================================
		 * =================================
		 */

		long start = millis();

		for (int j = 0; j < numOfThreads; j++) {

			int lowLimSum = (getUpperLimitSum() / numOfThreads) * j;
			int uppLimSum = (getUpperLimitSum() / numOfThreads) * (j + 1);
			int uppLimMul = getUpperLimitMul();

			if(getUpperLimitSum() % numOfThreads != 0 && j == numOfThreads - 1) {
				uppLimSum += (getUpperLimitSum() % numOfThreads);
			}

			c[j] = new Computation(lowLimSum, uppLimSum, 0, uppLimMul, *queue);

			Serial.print("[task] Thread ");
			Serial.print(j);
			Serial.print(" on core [");
			Serial.print((j+2)%2);
			Serial.print("] -> ");
			Serial.print(c[j]->getLoopOneStart());
			Serial.print(";");
			Serial.println(c[j]->getLoopOneEnd());

			// Serial.print(" -> stack size allocation : ");
			// Serial.println(sizeof(c[j]) * 32 * 8);				/* https://github.com/espressif/arduino-esp32/issues/1745 */
																	/* https://www.arduino.cc/en/pmwiki.php?n=Reference/Sizeof */
																	/* https://www.freertos.org/vTaskGetInfo.html */
																	/* https://www.esp32.com/viewtopic.php?t=4295 */
																	/* Serial.println(uxTaskGetStackHighWaterMark(NULL)); in task for left stack size */

			xTaskCreatePinnedToCore(
						producerTask,     							/* Function to implement the task */
						(j+2)%2 ==  0 ? "calcTask0" : "calcTask1",  /* Name of the task */
						sizeof(c[j]) * 32 * 8,            			/* Stack size in words: */
						 	 	 	 	 	 	 	 	 	 	 	/* -> size in words of the computation object: sizeof(c[j]) * 32 */
																	/* -> multiple by 8 for secure issues (used stack size will increase during runtime) */
																	/* => total allocated stack size: 1024 */
						c[j],             							/* Task input parameter */
						0,                							/* Priority of the task */
						NULL,             							/* Task handle. */
						(j+2)%2);         							/* Core where the task should run -> toggle between 0,1 if user try */
																	/* to run multiple threads on a dual core processor */
		}

		for (int k = 0; k < numOfThreads; k++) {
			long partResult;

			/*
			 * 	regarding to src [3]: "For the last argument, the value is specified in ticks, and we will
			 * 						   pass the value portMAX_DELAY, meaning that we will wait indefinitely
			 * 						   in case the queue is fullor we receive an message object."
			 *
			 * 	So this function call is a blocking call and the current (main) thread will wait until he received a new message
			 * 	from the queue. In this case, we can add the current part result to the main result:
			 * 	-> result += partResult
			 */
			xQueueReceive(*queue, &partResult, portMAX_DELAY);

			Serial.print("[bench] Received (part) result from thread ");
			Serial.print(k);
			Serial.print(" on core ");
			Serial.println((k+2)%2);

			result += partResult;
		}


		long end = millis();

		average += end - start;

		/*
		 * =============================================================================
		 * =================================
		 */
	}

	Serial.print("[bench] Number of threads: ");
	Serial.print(numOfThreads);
	Serial.print("; total time: ");
	Serial.print(average / numOfCycles);
	Serial.println(" ms.");

	Serial.print("[bench] => Result: ");
	Serial.println(result / numOfCycles);

	return average / numOfCycles;
}
