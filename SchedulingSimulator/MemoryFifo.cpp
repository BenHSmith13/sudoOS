#include "MemoryFifo.h"

void MemoryFifo::run()
{
	createTasks();
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

void MemoryFifo::menu()
{
	char zard = 'a';  //cause he's a pokemon
	while (zard != 'R' && zard != 'r')
	{
		std::cout << "C:   Set Number of CPU's (default 2)" << std::endl;
		std::cout << "I:   Set Number of I/O Devices (default 2)" << std::endl;
		std::cout << "S:   Set Cost of Context Switch (default 4)" << std::endl;
		std::cout << "T:   Set Task Mix (default 50)" << std::endl;
		std::cout << "F:   Frequency of Job Creation (default 20)" << std::endl;
		std::cout << "J:   Set Number of Tasks (default 3)" << std::endl;
		std::cout << "M:   Set Time Penalty for Cahce Miss" << std::endl;
		std::cout << "P:   Set Memory Size in Terms of Pages" << std::endl;
		std::cout << "R:   Run" << std::endl;
		std::cin >> zard;

		switch (zard)
		{
		case 'C':
		case 'c':
			int i;
			std::cin >> i;
			setCPUs(i);
			break;
		case 'I':
		case 'i':
			int j;
			std::cin >> j;
			setIOdevices(i);
			break;
		case 'S':
		case 's':
			float f;
			std::cin >> f;
			setContextSwitch(f);
			break;
		case 'T':
		case 't':
			std::cout << "Enter Mix of CPU Bound Tasks (0-100): ";
			int k;
			std::cin >> k;
			setTaskMix(k);
			break;
		case 'F':
		case 'f':
			int l;
			std::cin >> l;
			setFreq(l);
			break;
		case 'J':
		case 'j':
			int m;
			std::cin >> m;
			setNumTasks(m);
			break;
		case 'M':
		case 'm':
			float n;
			std::cin >> n;
			setMissPenalty(n);
			break;
		case 'P':
		case 'p':
			int o;
			std::cin >> o;
			setMemSize(o);
			break;
//		case 'R':
//		case 'r':
//			run();
//			break;
		}
	}
	if (zard == 'r' || zard == 'R')
	{
		run();
	}


}