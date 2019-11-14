/*
 * Computation.cpp
 *
 *  Created on: Nov 11, 2019
 *      Author: joseph
 */

#include "Computation.h"

Computation::Computation(int loopOneStart, int loopOneEnd, int loopTwoStart, int loopTwoEnd, QueueHandle_t &refParamQueue) {
	this->loopOneStart = loopOneStart;
	this->loopOneEnd = loopOneEnd;
	this->loopTwoStart = loopTwoStart;
	this->loopTwoEnd = loopTwoEnd;

	queue = new QueueHandle_t();
	*queue = refParamQueue;
}

Computation::~Computation() {
	// TODO Auto-generated destructor stub
}

int Computation::getLoopOneEnd() {
	return loopOneEnd;
}

int Computation::getLoopOneStart() {
	return loopOneStart;
}

int Computation::getLoopTwoEnd() {
	return loopTwoEnd;
}

int Computation::getLoopTwoStart() {
	return loopTwoStart;
}

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

