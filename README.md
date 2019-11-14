# esp32-BasicParallelProcessing

The [ESP32]() is a dual core microcontroller with a maximum clock speed of 240MHz. If offers the possibility to run and create threads on each core to increase execution time during a complicated computation in case the problem can be split into sub tasks.  Realtime parallel executuion can only be achieved on dedicated cores, for sure. 

But due to the fact that we only have two cores, there  would be only two possible results available. So i decided to increase the number of threads each core has to handle, too; with interesting results. 

## Definition of the mathematical problem

The main aim of this little project is to focus on a basic computation, which can be splitted into sub tasks.

<p align="center"><img width="50%" src="documentation/mathProblem.png"></p>

This mathematical problem is implemented in the class [Computation.h]() and can be executed with calling the function `compute()`.

```
void Computation::compute() {
	long count = 0;

	for (int i = getLoopOneStart(); i < getLoopOneEnd(); i++) {
		for (int j = getLoopTwoStart(); j < getLoopTwoEnd(); j++) {
			count += i * j;
		}
	}

	/*
	 *  push back the result to the receiver of the queue
	 *  "he" is actually waiting for the result until its transmitted
	 */

	xQueueSend(*queue, &count, portMAX_DELAY);
}
```

## Benchmark setup

...

## Evaluation

...

<p align="left"><img width="45%" src="documentation/execution-time-table-2.png"></p>

<p align="left"><img width="70%" src="documentation/graph-table-1.png"></p>

