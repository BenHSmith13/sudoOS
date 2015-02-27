#include<random>
#include<iostream>

class Event
{
public:
	float randRunTime();
private:
	float runTime = randRunTime();
	float startTime;
	float endTime;

};