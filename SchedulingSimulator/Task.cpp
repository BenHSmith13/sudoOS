#include"Task.h"

void Task::createEvents()
{
	while (randRunTime(15) < 14)
	{
		if (getBound() == "CPU") createEvent(randRunTime(50), randRunTime(15));
		else createEvent(randRunTime(20), randRunTime(50));
	}
	createEvent(1000, 1000); //Final Event
}

void Task::createEvent(float CPUt, float IOt)
{
	Event CPUevent;
	CPUevent.setType(0);
	CPUevent.setRunTime(CPUt);
	events.push_back(CPUevent);
	
	Event IOevent;
	IOevent.setType(1);
	IOevent.setRunTime(IOt);
	events.push_back(IOevent);
}

float Task::randRunTime(int top)
{
	std::random_device rd;		//Produces random int
	std::mt19937 mt(rd());		//Comments are for squares

	std::uniform_real_distribution<float> die(1, top);

	return die(mt);
}
