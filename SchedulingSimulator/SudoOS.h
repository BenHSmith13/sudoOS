#include<iostream>
#include<queue>
#include<vector>
#include"Process.h"

class scheduler
{
public:


private:
	std::priority_queue<Event> eventQ;
	int freeCPUs;
	std::queue<Event> readyQ;
	std::queue<Event> waitQ;
};
