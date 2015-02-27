#include "SudoOS.h"

int main(){

	std::random_device rd;		//Produces random int
	std::mt19937 mt(rd());		//Comments are for squares

	std::uniform_real_distribution<float> die(1, 6);

	std::cout << die(mt) << std::endl;


	return 0;
}