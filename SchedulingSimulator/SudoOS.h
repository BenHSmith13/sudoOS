#include<iostream>
#include<queue>
#include<vector>
#include"Event.h"
#include "Task.h"

class scheduler
{
public:


private:
	std::vector<Task> Tasks;

	std::priority_queue<Event> eventQ;
	int CPUs; 
	int freeCPUs;
	std::queue<Event> readyQ;
	std::queue<Event> waitQ;

	/*
	Number of IO devices
	Cost of Context switch = 4
	Task Mix
	Frequency of Job Creation
	*/

};
