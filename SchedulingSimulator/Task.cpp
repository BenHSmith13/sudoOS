#include"Task.h"

void Task::createEvents()
{
	std::random_device rd;		//Produces random int
	std::mt19937 mt(rd());		//Comments are for squares

	std::uniform_real_distribution<float> die(1, 15);

	auto* firstEvent = new Event();
	events.push_back(firstEvent);

	while (die(mt) < 14)
	{
		auto* CPUevent = new Event();
		auto* IOevent = new Event();
		events.push_back(CPUevent);
		events.push_back(IOevent);
	}

	auto* finalEvent = new Event();
	finalEvent->setRunTime(1000);
	events.push_back(finalEvent);


}