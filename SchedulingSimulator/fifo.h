#ifndef FIFO_H
#define FIFO_H

#include "SudoOS.h"

class FIFO : public scheduler
{
public:
	void run();
	void addEventToCPU();

private:
	std::queue<Event> fifoQ;
};

#endif