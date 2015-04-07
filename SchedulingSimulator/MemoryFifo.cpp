#include "MemoryFifo.h"

void MemoryFifo::run()
{
	initializeMemorySize();
	runSimulation();
	doMath();
}

void MemoryFifo::initializeMemorySize()
{
	mem2.resize(2);
	mem4.resize(4);
	mem8.resize(8);
}

void MemoryFifo::runSimulation()
{
	auto tempTasks = getTaskVect();
	for (auto && t : tempTasks)
	{
		for (auto && e : t.getEvents())
		{
			auto tempLocation = e.getMemLocation();

			if (std::find(mem2.begin(), mem2.end(), tempLocation) == mem2.end())	//if locatin isn't in memory
			{
				cacheMiss2++;
				mem2.pop_front();
				mem2.push_back(tempLocation);
			}
			if (std::find(mem4.begin(), mem4.end(), tempLocation) == mem4.end())	//if locatin isn't in memory
			{
				cacheMiss4++;
				mem4.pop_front();
				mem4.push_back(tempLocation);
			}
			if (std::find(mem8.begin(), mem8.end(), tempLocation) == mem8.end())	//if locatin isn't in memory
			{
				cacheMiss8++;
				mem8.pop_front();
				mem8.push_back(tempLocation);
			}
		}
	}
}

void MemoryFifo::doMath()
{
	std::cout << "Page Faults for Memory size 2: " << cacheMiss2 << std::endl;
	std::cout << "Page Faults for Memory size 4: " << cacheMiss4 << std::endl;
	std::cout << "Page Faults for Memory size 8: " << cacheMiss8 << std::endl;
}