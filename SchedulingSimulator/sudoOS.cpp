#include "SudoOS.h"

void scheduler::menu()
{
	char zard;  //cause he's a pokemon

	std::cout << "C:   Set Number of CPU's (default 2)" << std::endl;
	std::cout << "I:   Set Number of I/O Devices (default 2)" << std::endl;
	std::cout << "S:   Set Cost of Context Switch (default 4)" << std::endl;
	std::cout << "T:   Set Task Mix (default 50)" << std::endl;
	std::cout << "F:   Frequency of Job Creation (default idfk)" << std::endl;
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
			std::cout << "Enter percent of CPU events (0-100): ";
			int k;
			std::cin >> k;
			setTaskPercent(k);
			break;
		case 'F':
		case 'f':
			int l;
			std::cin >> l;
			setFreq(l);
			break;
		case 'R':
		case 'r':
			break;
		}
	}

}

void scheduler::createTasks(int n)
{
	for (auto i = 0; i < n; i++)
	{
		Task newTask;
		newTask.setStartTime(i*getFreq());
		newTask.createEvents(getTaskPercent(), getFreq());
		taskVect.push_back(newTask);
	}
}
