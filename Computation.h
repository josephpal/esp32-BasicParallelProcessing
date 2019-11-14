/*
 * Computation.h
 *
 *  Created on: Nov 11, 2019
 *      Author: joseph
 */

#ifndef COMPUTATION_H_
#define COMPUTATION_H_

#include "Arduino.h"

class Computation {
public:
	/** The main computation which will be calculated is a generic sum based on two for-loops inside each other. The outer
	 *  one can be separated in different sub sums to perform in parallel. Therefore the loopOneStart and loopOneEnd has to be split too.
	 *  The loopOneStart or loopOneEnd can be set through this constructor and will result in different performance/execution time results due to the fact
	 *  that the ESP32 now has more to calculate.
	 *
	 *  @param	specify the loopOneStart property of the outer for-loop in void compute(). For a single core execution, this value will be 0.
	 *  		For parallel processing, this threshold has to be evaluated and will be a set of different limits regarding to Benchmark.cpp line 93-95. This limits
	 *  		will represent the sub sums, which now can be calculated in different threads.
	 *  @param	specify the loopOneEnd property of the outer for-loop in void compute() through @upperLimitSum from Benchmark.h;
	 *  		by default, upperLimitSum will be set to 50000 in the constructor of Benchmark.h.
	 *  @param	deprecated value loopTwoStart of the inner for-loop; this one should never be changed and is by default 0.
	 *  @param	specify the loopTwoEnd property of the inner for-loop in void compute() through @upperLimitMul from Benchmark.h;
	 *  		by default, upperLimitMul will be set to 10000 in the constructor of Benchmark.h.
	 *  @param	&refParamQueue is necessary for the inner task communication and contains the pointer to the current queue object.
	 *  @return ---
	*/
	Computation(int loopOneStart, int loopOneEnd, int loopTwoStart,int loopTwoEnd, QueueHandle_t &refParamQueue);
	~Computation();

	/** ...
	 *
	 *  @param
	 *  @return ---
	*/
	void compute();


	/** ...
	 *
	 *  @param
	 *  @return ---
	*/
	int getLoopOneEnd();

	/** ...
	 *
	 *  @param
	 *  @return ---
	*/
	int getLoopOneStart();

	/** ...
	 *
	 *  @param
	 *  @return ---
	*/
	int getLoopTwoEnd();

	/** ...
	 *
	 *  @param
	 *  @return ---
	*/
	int getLoopTwoStart();

private:
	int loopOneStart;
	int loopOneEnd;
	int loopTwoStart;
	int loopTwoEnd;

	QueueHandle_t *queue;
};

#endif /* COMPUTATION_H_ */
