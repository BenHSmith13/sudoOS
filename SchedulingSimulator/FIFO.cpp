#include "fifo.h"

void FIFO::run()
{
	createTasks();

	for (auto && t : getTaskVect())
	{
		for (auto && e : t.getEvents())
		{
			fifoQ.push(e);
		}
	}

	for (auto && i : CPUtimes)		//initializes CPU's with context switch
	{
		i += getContextSwitch();
	}
	//Add Event to CPU
	addEventToCPU();

	//Add Event Time to CPU time
	//Find min CPU Time
	//Repeat
}

void FIFO::addEventToCPU()
{
	if (isCPUfree())
	{
		auto temp = fifoQ.front();
		if (temp.getRunTime() > 999)
		{
			
		}
		std::min_element(CPUtimes.begin(), CPUtimes.end()) += temp.getRunTime();
		fifoQ.pop();
	}
}