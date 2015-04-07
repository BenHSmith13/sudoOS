#ifndef EVENT_H
#define EVENT_H

#include<random>
#include<iostream>

class Event
{
public:
	void setRunTime(float time);
	void setType(int t);
	float getRunTime()
	{
		return runTime;
	}
	void setMemLocation(int l)
	{
		memLocation = l;
	}
	int getMemLocation()
	{
		return memLocation;
	}

	int randLocation();

private:
	float runTime = 0;
	std::string type;
	int memLocation = randLocation();
};

#endif