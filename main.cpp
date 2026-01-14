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
#include "solutions/Day5_1.h"
#include "solutions/Day5_2.h"
#include "solutions/Day6_1.h"
#include "solutions/Day6_2.h"
#include "solutions/Day7_1.h"
#include "solutions/Day7_2.h"

int main() {
	int DAY = 7;

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
		case 5:
			// Day 5
			std::cout << "Day 5 : " << std::endl;
			std::cout << Day5_1::run("./inputData/Day5.txt") << std::endl;
			std::cout << Day5_2::run("./inputData/Day5.txt") << std::endl;
			break;
		case 6:
			// Day 6
			std::cout << "Day 6 : " << std::endl;
			std::cout << Day6_1::run("./inputData/Day6.txt") << std::endl;
			std::cout << Day6_2::run("./inputData/Day6.txt") << std::endl;
			break;
		case 7:
			// Day 7
			std::cout << "Day 7 : " << std::endl;
			std::cout << Day7_1::run("./inputData/Day7.txt") << std::endl;
			std::cout << Day7_2::run("./inputData/Day7.txt") << std::endl;
			break;
		default:
			std::cout << "Day " << DAY << " not implemented";
			break;
	}

	return 0;
}
