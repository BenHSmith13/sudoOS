#ifndef EVENT_H
#define EVENT_H

#include<random>
#include<iostream>

class Event
{
public:
	float randRunTime();
	void setRunTime(float time);
	void setType(int t);
	float getRunTime()
	{
		return runTime;
	}
private:
	float runTime = randRunTime();
	std::string type;
};

#endif