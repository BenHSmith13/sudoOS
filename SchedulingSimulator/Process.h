#include "Event.h"
#include<vector>

class Process
{
public:
	void createEvents();

private:
	std::vector<Event> events;
};