/*
 * esp32-BasicParallelProcessing.ino
 *
 *  Created on: 	Nov 11, 2019
 *  				M. Belean, F.J. Pal
 *  
 *  description:	basic mathematical computation performed on single and dual core
 *  				using parallel processing and multi-threading; as a programming model, we choosed the
 *  				Message Passing model (every created thread will calculate the sub result and send his result
 *  				to the main running thread, where the results are collected to sum them up).
 *
 *  				On the ESP32, communication between threads are realized through a QueueHandle_t object (queue handle send/receive; see src [3]).
 *  				TO send a result back, we have to call xQueueSend(*queue, &count, portMAX_DELAY)[see Computation.cpp line 54];
 *  				to receive a message, the function xQueueReceive(*queue, &partResult, portMAX_DELAY) will be called [see Benchmark.cpp line 125].
 *  				This is a blocking method, so the current thread will wait until he receive a message. Due to the fact that we know how many messages
 *  				we should receive (durations -> numberOfThreads), we can call xQueueReceive(...) in a for loop to collect all sub results.
 *  
 *  version:		0.3
 *  
 *  notifications:
 *  
 *  src:	[1] http://exploreembedded.com/wiki/Read_Task_Info_%3A_vTaskList()
 *  		[2] https://techtutorialsx.com/2017/05/06/esp32-arduino-creating-a-task/
 *  		[3] https://techtutorialsx.com/2017/09/13/esp32-arduino-communication-between-tasks-using-freertos-queues/
 *  		[4] https://forum.arduino.cc/index.php?topic=503368.0
 *  		[5] https://arduino.stackexchange.com/questions/49337/call-by-reference
 *  		[6] https://esp32.com/viewtopic.php?t=10411
 */

#include "Benchmark.h"

void setup() {
    Serial.begin(115200);   // serial communication
    delay(1000);

    Serial.println("---------------------------------------------------------------------- benchmark -----------------------------------------------------------------------");

    /*
     * 	definition of how many threads should be created to solve the problem,
     * 	usually maximal as many cores: numOfThreads <= NUM_CORES
     * 	2x -> one thread per core
     *
     * 	for testing:
     * 	4x -> 2 threads per core
     *
     * 	...
     *
     * 	duration -> number of maximal threads
     *
     *	tested with: 8, 16, 32, 64 threads successfully (on ESP32 DEV and TTGO LORA SX1278 ESP32 module)
     *	-> for possible ESP32 crashes, decrease the heap size being allocated for creating the tasks
     *	-> note: could be optimized (calculate the size in words of a computation object)
     */
    int numOfRunningThreads = 64;

    /*
     *  results[]: array filled with the different execution times
     *  speedup[]: array filled with the calculated speedup factor
     */
    float *results[numOfRunningThreads];
    float *speedup[numOfRunningThreads];

    /*
     *  initializing the benchmark class:
     *  Benchmark(a, b)
     *  -> a: number of cycles per calculation (to average the result)
     *  -> b: cool down timer after one execution in ms
     *  -> setMaxNumOfThreads is currently limited to the total number of dedicated cores.
     *     To allow multiple threads on each core, you have to set the threshold higher
     */
    Benchmark bench(1, 1500, numOfRunningThreads);
    bench.setMaxNumOfThreads(numOfRunningThreads);

    for (int i = 0; i < numOfRunningThreads; ++i) {
        Serial.print("[main] Performing benchmark number ");
        Serial.print(i + 1);
        Serial.println(" started ...");

        Serial.print("[main] Number of threads: ");
        Serial.println(i + 1);

        /*
         *  performing the benchmark execution with the total number of threads, which will be created
         *  return value is the execution time, which was needed to perform the computation
         */
        results[i] = new float(bench.performBenchmark(i + 1));

        Serial.print("[main] Performing benchmark number ");
        Serial.print(i + 1);
        Serial.println(" finished.\n");
	}

    Serial.println("---------------------------------------------------------------------- evaluation ----------------------------------------------------------------------");

    /*
     *  display the number of threads as an array:
     *  -> number of threads:	[	1	2	3	....	]
     */
    Serial.print("number of threads:\t[\t");

    for (int j = 0; j < numOfRunningThreads; ++j) {
		Serial.print( j + 1 );
  		Serial.print("\t\t");
	}

    Serial.println("]");

    /*
	 *  display the different execution time as an array:
	 *  -> execution time:	[	423		121		....	]
	 */
    Serial.print("execution time:\t\t[\t");

	for (int k = 0; k < numOfRunningThreads; ++k) {
		Serial.print( (int)*results[k] );
		Serial.print("\t");
	}

	Serial.println("]");

	/*
	 *  calculate the total speedup in comparison to single execution
	 *  -> S = t_1 / t_p with
	 *     t_1: time for computing the result on a single core
	 *     t_p: time for computing the problem on p processors / threads
	 */
    Serial.print("total speedup:\t\t[\t");

    for (int l = 0; l < numOfRunningThreads; ++l) {
    	speedup[l] = new float(*results[0] / *results[l]);
		Serial.print( *speedup[l] );
		Serial.print("\t");
	}

    Serial.println("]");

    /*
     *  in fact, we only have two real cores on the esp32, but each core can handle several own threads under the restrictions
     *  of hardware resources such as heap size, clock frequency, scheduler performance ...
     *  so each thread will be asigned to one dedicated core [0/1]
     */
    Serial.print("core number:\t\t[\t");

	for (int m = 0; m < numOfRunningThreads; ++m) {
		Serial.print( (m+1)%2 );
		Serial.print("\t\t");
	}

	Serial.println("]");
}

void loop() {
	/*
	 * delete main loop task to disable watchdog core panic errors
	 * other possibilities:
	 * 		// main loop in idle task
	 * 		vTaskDelay(portMAX_DELAY);
	 * 		delay(1000);
	 */

	vTaskDelete(NULL);
}
