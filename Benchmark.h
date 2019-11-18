/*
 * Benchmark.h
 *
 *  Created on: Nov 11, 2019
 *      Author: joseph
 */

#ifndef BENCHMARK_H_
#define BENCHMARK_H_

#include "Arduino.h"
#include "Computation.h"

class Benchmark {
public:
	/** Overloaded constructor; durationCycles, coolDownTimer and queue size will be set on @param
     *
     *  @param	set the amount of cycles @durationCycles per computation to average the result
     *  @param	set a specific delay @coolDownTimer in ms between multiple calls of the benchmark
     *  @param  determine the size of the queue object for message passing between the threads
     *  @return ---
    */
	Benchmark(int durationCycles, int coolDownTimer, int queueSize);
	~Benchmark();

	/** start the computation benchmark and set the number of threads, which will be created to solve the problem
	 *  with the help of parallel processing
	 *
	 *  @param	specify the number @numOfThreads of threads; in general, this number can not be higher than the
	 *  		total number of dedicated cores on the ESP32 (cores: 2x) -> setMaxNumOfThreads()
	 *  @return	as a return value, we will expect the needed the total execution time in ms needed for the computation
	*/
	float performBenchmark(int numOfThreads);


	/**	The main computation which will be calculated is a generic sum based on two for loops inside each other. The inner for-
	 *  loop consists of two thresholds, an upper and lower limit. The lower limit is by default 0 [see Benchmark.cpp line 101]. The upper
	 *  limitMul can be set through this function and this will result in different performance/execution time results due to the fact
	 *  that the ESP32 now has more to calculate.
	 *
	 *  @param	specify the upperLimitMul property through @upperLimitMul of the inner for loop in the calculation task;
	 *  		by default, upperLimitMul will be set to 10000 in the constructor.
	 *  @return ---
	*/
	void setUpperLimitMul(int upperLimitMul);

	/** To get the stored upper limit threshold for the inner computation for-loop, this function can be called.
	 *
	 *  @return @upperLimitMul property
	*/
	int getUpperLimitMul();


	/** The main computation which will be calculated is a generic sum based on two for-loops inside each other. The outer
	 *  one can be separated in different sub sums to perform in parallel. Therefore the upperLimit has to be split too. The upper
	 *  limitSum can be set through this function and this will result in different performance/execution time results due to the fact
	 *  that the ESP32 now has more to calculate.
	 *
	 *  @param	specify the upperLimitSum property through @upperLimitSum of the outer for loop in the calculation task;
	 *  		by default, upperLimitSum will be set to 50000 in the constructor.
	 *  @return ---
	*/
	void setUpperLimitSum(int upperLimitSum);

	/** To get the stored upper limit threshold for the outer computation for-loop, this function can be called.
	 *
	 *  @return @upperLimitSum property
	*/
	int getUpperLimitSum();

	/** The maximum number of threads, which will be created to solve the computation [see Computation.h line 18], can be
	 *  specified through this function.
	 *
	 *  @param	specify the maxNumOfThreads property with @maxNumOfThreads
	 *  @return ---
	*/
	void setMaxNumOfThreads(int maxNumOfThreads);

private:
	/** will be called form the performBenchmark() function, specify the number of created threads and the
	 *
	 *  @param	specify the number @numOfThreads of threads; in general, this number can not be higher than the
	 *  		total number of dedicated cores on the ESP32 (cores: 2x) -> setMaxNumOfThreads()
	 *  @param	set the amount of cycles @numOfCycles per computation to average the result; in general,
	 *  		the private variable @durationCycles will be used for that
	 *  @return will return the needed execution time
	*/
	float runWith(int numOfThreads, int numOfCycles);

	/*
	 *  durationCycles	amount of durations per computation to average the result
	 *  coolDownTimer	delay in ms between different computations / performBenchmark() calls
	 *  upperLimitSum	outer upper for-loop limit (summation)
	 *  upperLimitMul	inner upper for-loop limit (multiplication)
	 */
	int durationCycles, coolDownTimer;
	int upperLimitSum, upperLimitMul;

	/*
	 * 	queue		pointer to QueueHandle_t object to pass messages between the producerTask (compute sub results)
	 * 				and the main thread, which will collect the sub results to sum them up.
	 * 				QueueHandle_t is based on a FIFO concept, every passed message will be copied to memory rather than only store a reference and
	 * 				is used for inner task communication.
	 * 				The function xQueueCreate( a, b ) is used to create the queue. where
	 * 				-> a: stands for the maximum queueSize (message objects, which will be stored until the queue is full) and
	 * 				-> b: for the passed message value (allocate the necessary memory with sizeof(b).
	 * 				Keep in mind, that the function xQueueSend(*queue, &count, portMAX_DELAY) and xQueueReceive(*queue, &partResult, portMAX_DELAY);
	 * 				is used for send and receive message objects. The queue in this case should be registered/passed to every subscriber (e.g. as a pointer).
	 * 				Nevertheless however xQueueReceive(...) is a blocking call; therefore the current thread will wait until he receive a new message
	 * 				or the queue is full!
	 *
	 * 	queueSize	maximum amount of message objects, which will be stored until the queue is full
	 */
	QueueHandle_t *queue;
	int queueSize;

	/*
	 * 	maxNumOfThreads	specify the maximum amount of created threads. In general, this number is set to the total number of
	 * 	dedicated cores of the ESP32 (cores: 2x).
	 */
	int maxNumOfThreads;
};

#endif /* BENCHMARK_H_ */
