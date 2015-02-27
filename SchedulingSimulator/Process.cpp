#include"Process.h"

void Process::createEvents(){
	std::random_device rd;		//Produces random int
	std::mt19937 mt(rd());		//Comments are for squares

	std::uniform_real_distribution<int> die(1, 15);

	while (die(mt) != 15){
		Event *CPUevent = new Event();
		events.push_back(CPUevent);
	}


}