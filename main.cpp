#include <iostream>
#include <fstream>

// Solutions
#include "solutions/Day1_1.h"
#include "solutions/Day1_2.h"
#include "solutions/Day2_1.h"
#include "solutions/Day2_2.h"
#include "solutions/Day3_1.h"
#include "solutions/Day3_2.h"
#include "solutions/Day4_1.h"
#include "solutions/Day4_2.h"


int main() {
	int DAY = 4;

	switch (DAY) {
		case 1:
			// Day 1
			std::cout << "Day 1 : " << std::endl;
			std::cout << Day1_1::run("./inputData/Day1.txt") << std::endl;
			std::cout << Day1_2::run("./inputData/Day1.txt") << std::endl;
			std::cout << std::endl;
			break;
		case 2:
			// Day 2
			std::cout << "Day 2 : " << std::endl;
			std::cout << Day2_1::run("./inputData/Day2.txt") << std::endl;
			std::cout << Day2_2::run("./inputData/Day2.txt") << std::endl;
			std::cout << std::endl;
			break;
		case 3:
			// Day 3
			std::cout << "Day 3 : " << std::endl;
			std::cout << Day3_1::run("./inputData/Day3.txt") << std::endl;
			std::cout << Day3_2::run("./inputData/Day3.txt") << std::endl;
			std::cout << std::endl;
			break;
		case 4:
			// Day 4
			std::cout << "Day 4 : " << std::endl;
			std::cout << Day4_1::run("./inputData/Day4.txt") << std::endl;
			std::cout << Day4_2::run("./inputData/Day4.txt") << std::endl;
			break;
		default:
			std::cout << "Day " << DAY << " not implemented";
			break;
	}

	return 0;
}
