#include"Event.h"

void Event::setRunTime(float time)
{
	runTime = time;
}

void Event::setType(int t)
{
	if (t == 0) type = "CPU";
	else type = "IO";
}

int Event::randLocation()
{
	std::random_device rd;		//Produces random int
	std::mt19937 mt(rd());		//Comments are for squares

	std::uniform_real_distribution<float> die(0, 10);

	return static_cast<int>(die(mt));
}