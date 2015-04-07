#include "SudoOS.h"
#include "MemoryFifo.h"

int main(){
	MemoryFifo testOS;
	testOS.createTasks();
	testOS.run();

	return 0;
}