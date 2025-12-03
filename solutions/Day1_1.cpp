// Solution to day1.1 : https://adventofcode.com/2025/day/1
// By James Schaffer 02/12/2025

#include "Day1_1.h"

std::string Day1_1::run(const std::string &inputFile_dir) {
	std::ifstream inputFile(inputFile_dir);

	int p = 50;
	int count = 0;

	for (std::string line; std::getline(inputFile, line);) {
		p += (line.at(0) == 'R' ? 1 : -1) *
			std::stoi(line.substr(1, line.size()-1));

		p = p%100;
		if (p < 0) p += 100;
		if (p==0) count++;
	}

	inputFile.close();
	return std::to_string(count);
};
