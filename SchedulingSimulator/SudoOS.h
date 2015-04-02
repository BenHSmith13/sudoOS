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
	int getTaskMix()
	{
		return taskMix;
	}
	float getFreq()
	{
		return freq;
	}
	float getSysclock()
	{
		return sysClock;
	}
	std::vector<Task> getTaskVect()
	{
		return taskVect;
	}
	std::vector<float> getCPUtimes()
	{
		return CPUtimes;
	}
	
	void setNumTasks(int n)
	{
		numTasks = n;
	}

	void setCPUs(int n);
	void incrementFreeCPUs()
	{
		CPUs += 1;
	}
	void decrementFreeCPUs()
	{
		CPUs -= 1;
	}

	void setContextSwitch(float f)
	{
		contextSwitch = f;
	}	
	void setIOdevices(int n)
	{
		IOdevices = n;
	}
	void setTaskMix(int n)
	{
		taskMix = n;
	}
	void setFreq(int n)
	{
		freq = n;
	}
	void setSysClock(float f)
	{
		sysClock = f;
	}


	bool isCPUfree()
	{
		if (freeCPUs > 0) return true;
	}
	
	void createTasks()
	{
		createTasks(numTasks);
	}
	void menu();

	void run()
	{
		createTasks();
	}
	
	std::vector<float> CPUtimes;

private:
	int numTasks = 3;
	std::priority_queue<Event> eventQ;
	int CPUs = 2; 
	int freeCPUs = 2;
	std::queue<Event> readyQ;
	std::queue<Event> waitQ;
	float contextSwitch = 4;
	int IOdevices = 2;
	int taskMix = 50;
	float freq = 5;			
	float sysClock = 0;
	std::vector<Task> taskVect;
	

	void createTasks(int n);

};


#endif