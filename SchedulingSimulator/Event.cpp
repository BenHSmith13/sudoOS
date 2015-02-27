#include"Event.h"

float Event::randRunTime(){
	std::random_device rd;		//Produces random int
	std::mt19937 mt(rd());		//Comments are for squares

	std::uniform_real_distribution<float> die(1, 6);

	return die(mt);
}