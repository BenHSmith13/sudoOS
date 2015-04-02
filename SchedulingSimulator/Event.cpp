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