#include"Event.h"

float Event::randRunTime(){
	std::random_device rd;		//Produces random int
	std::mt19937 mt(rd());		//Comments are for squares

	std::uniform_real_distribution<float> die(1, 50);

	return die(mt);
}

void Event::setRunTime(float time)
{
	runTime = time;
}

void Event::setType(int t)
{
	if (t == 0) type = "CPU";
	else type = "I/O";
}