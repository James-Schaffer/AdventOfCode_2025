#include <iostream>
#include <fstream>

// Solutions
#include "solutions/Day1_1.h"
#include "solutions/Day1_2.h"
#include "solutions/Day2_1.h"

int main() {
	// Day 1
	/*
	std::cout << Day1_1::run("./inputData/Day1_input.txt") << std::endl;
	std::cout << Day1_2::run("./inputData/Day1_input.txt") << std::endl;
	*/

	// Day 1
	std::cout << Day2_1::run("./inputData/Day2_example_input.txt") << std::endl;
	std::cout << Day2_1::run("./inputData/Day2_input.txt") << std::endl;

	return 0;
}
