// Solution to day3.1 : https://adventofcode.com/2025/day/3
// Created by James Schaffer on 10/12/2025.

#include "Day3_1.h"

#include <iostream>

// Iterative solution
int Day3_1::maxInBank_0(std::string bank) {
	int maxL=0, maxR=0;

	// char -> int : e.g. '1' -> 1, see
	maxL = *bank.begin() - '0';
	maxR = *++bank.begin() - '0';

	for (std::string::iterator r = ++++bank.begin(); r!=bank.end(); ++r) {
		//std::cout << *r << std::endl;

		int val = *r - '0';

		if (maxR > maxL) {
			maxL = maxR;
			maxR = val -1; // forces r to move over
		}

		if (val > maxR) {
			maxR = val;
		}
	}

	return (maxL*10)+maxR;
}

// Array reduction solution
int Day3_1::maxInBank_1(const std::string& bank) {
	int maxL=0, maxR=0;

	return 0;
}

std::string Day3_1::run(const std::string &inputFile_dir) {
	std::ifstream inputFile(inputFile_dir);

	int result = 0;

	for (std::string line; std::getline(inputFile, line);) {
		result += maxInBank_0(line);
	}

	inputFile.close();
	return std::to_string(result);
}
