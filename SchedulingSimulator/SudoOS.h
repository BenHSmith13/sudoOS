#ifndef SUDOOS_H
#define SUDOOS_H

#include<iostream>
#include<queue>
#include<vector>
#include"Event.h"
#include "Task.h"
#include <algorithm>

class scheduler
{
public:
	int getNumTasks()
	{
		return numTasks;
	}
	int getCPUs()
	{
		return CPUs;
	}
	float getContextSwitch()
	{
		return contextSwitch;
	}
	int getIOdevices()
	{
		return IOdevices;
	}
	int getTaskPercent()
	{
		return taskPercent;
	}
	float getFreq()
	{
		return freq;
	}
	float getSysclock()
	{
		return sysClock;
	}
	
	void setNumTasks(int n)
	{
		numTasks = n;
	}

	void setCPUs(int n);

	void setContextSwitch(float f)
	{
		contextSwitch = f;
	}	
	void setIOdevices(int n)
	{
		IOdevices = n;
	}
	void setTaskPercent(int n)
	{
		taskPercent = n;
	}
	void setFreq(int n)
	{
		freq = n;
	}
	void setSysClock(float f)
	{
		sysClock = f;
	}

	bool freeCPU()
	{
		if (getCPUs() > 0) return true;
	}
	
	void createTasks()
	{
		createTasks(numTasks);
	}
	void menu();
	void run();  //This is empty

private:
	std::vector<Task> taskVect;
	int numTasks = 3;
	std::priority_queue<Event> eventQ;
	int CPUs = 2; 
	int freeCPUs = 2;
	std::queue<Event> readyQ;
	std::queue<Event> waitQ;
	float contextSwitch = 4;
	int IOdevices = 2;
	int taskPercent = 50;
	float freq = 5;			//I am guessing at what this is.
	float sysClock = 0;

	std::vector<float> CPUtimes;

	void createTasks(int n);

};


#endif