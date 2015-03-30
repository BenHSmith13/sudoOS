#include"Task.h"

void Task::createEvents(int p, float start)
{
	std::random_device rd;		//Produces random int
	std::mt19937 mt(rd());		//Comments are for squares

	std::uniform_real_distribution<float> die(1, 15);

	Event firstEvent;
	firstEvent.setType(0);
	events.push_back(firstEvent);

	while (die(mt) < 14)
	{
		if (die(mt) <= (15*p/100))
		{
			Event CPUevent;
			CPUevent.setType(0);
			//CPUevent.setRunTime(CPUevent.getRunTime() + events[events.size() - 1].getRunTime());  //I need to set Runtime and event start time
			events.push_back(CPUevent);
		}
		if (die(mt) > (15*p/100))
		{
			Event IOevent;
			IOevent.setType(1);
			//IOevent.setRunTime(IOevent.getRunTime() + events[events.size() - 1].getRunTime());
			events.push_back(IOevent);
		}	
	}

	Event finalEvent;
	finalEvent.setRunTime(1000);
	events.push_back(finalEvent);
}