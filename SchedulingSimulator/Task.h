#ifndef TASK_H
#define TASK_H

#include "Event.h"
#include<vector>

class Task
{
public:
	void createEvents();
	void createEvent(float CPUt, float IOt);

	void setStartTime(float f)
	{
		startTime = f;
	}
	void setEndTime(float f)
	{
		endTime = f;
	}
	void makeIOBound()
	{
		bound = "IO";
	}

	float getStartTime()
	{
		return startTime;
	}
	float getEndTime()
	{
		return endTime;
	}
	float randRunTime(int top);
	std::string getBound()
	{
		return bound;
	}
	std::vector<Event> getEvents()
	{
		return events;
	}

private:
	std::vector<Event> events;
	float startTime = 0;
	float endTime = 0;
	std::string bound = "CPU";
};

#endif