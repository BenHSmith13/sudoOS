#include "SudoOS.h"

int main(){

	std::random_device rd;		//Produces random int
	std::mt19937 mt(rd());		//Comments are for squares

	std::uniform_real_distribution<float> die(1, 6);

	std::cout << die(mt) << std::endl;
	auto x = 0;
	while (die(mt) < 5){
		std::cout << die(mt) << " " <<  x++ << std::endl;
	}


	return 0;
}