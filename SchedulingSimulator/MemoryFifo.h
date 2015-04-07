#ifndef MEMORYFIFO_H
#define MEMORYFIFO_H

#include "SudoOS.h"

class MemoryFifo : public scheduler
{
public:
	void run();
	void initializeMemorySize();
	void runSimulation();
	void doMath();
	void setMissPenalty(float n)
	{
		missPenalty = n;
	}
	void setMemSize(int x)
	{
		memSize = x;
	}
	
	void menu();

private:
	std::deque<int> mem2;
	std::deque<int> mem4;
	std::deque<int> mem8;

	float missPenalty = 0;
	int memSize = 2;

	int cacheMiss2 = 0;
	int cacheMiss4 = 0;
	int cacheMiss8 = 0;

};


#endif