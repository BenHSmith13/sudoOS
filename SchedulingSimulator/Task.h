#include "Event.h"
#include<vector>

class Task
{
public:
	void createEvents();
private:
	std::vector<Event*> events;
};