#include<random>
#include<iostream>

class Event
{
public:
	float randRunTime();
	void setRunTime(float time);
private:
	float runTime = randRunTime();
};