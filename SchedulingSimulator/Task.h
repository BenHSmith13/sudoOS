#ifndef TASK_H
#define TASK_H

#include "Event.h"
#include<vector>

class Task
{
public:
	void createEvents(int percent, float start);\

	void setStartTime(float f)
	{
		startTime = f;
	}
	void setEndTime(float f)
	{
		endTime = f;
	}

	float getStartTime()
	{
		return startTime;
	}
	float getEndTime()
	{
		return endTime;
	}

private:
	std::vector<Event> events;
	float startTime = 0;
	float endTime = 0;
};

#endif