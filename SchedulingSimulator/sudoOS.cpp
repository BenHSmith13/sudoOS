#include "SudoOS.h"

void scheduler::setCPUs(int n)
{
	CPUs = n;
	CPUtimes.resize(n);
}

void scheduler::menu()
{
	char zard;  //cause he's a pokemon

	std::cout << "C:   Set Number of CPU's (default 2)" << std::endl;
	std::cout << "I:   Set Number of I/O Devices (default 2)" << std::endl;
	std::cout << "S:   Set Cost of Context Switch (default 4)" << std::endl;
	std::cout << "T:   Set Task Mix (default 50)" << std::endl;
	std::cout << "F:   Frequency of Job Creation (default idfk)" << std::endl;
	std::cout << "J:   Set Number of Tasks (default 3)" << std::endl;
	std::cout << "R:   Run" << std::endl;
	std::cin >> zard;

	while (zard != 'R' || zard != 'r')
	{
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
		case 'R':
		case 'r':
			run();
			break;
		}
	}

}

void scheduler::createTasks(int n)
{
	auto ratio = n*getTaskMix() / 100;

	for (auto i = 0; i < n; i++)
	{
		Task newTask;
		newTask.setStartTime(i*getFreq());
		if (i > ratio) newTask.makeIOBound();
		newTask.createEvents();
		taskVect.push_back(newTask);
	}
}
