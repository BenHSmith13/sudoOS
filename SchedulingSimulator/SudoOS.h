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
	void setCPUs(int n)
	{
		CPUs = n;
	}
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
	
	void createTasks()
	{
		createTasks(numTasks);
	}
	void menu();

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
	float freq = 5;			//I don't know what this is, or what its supposed to do.
	float sysClock = 0;

	void createTasks(int n);

};


#endif