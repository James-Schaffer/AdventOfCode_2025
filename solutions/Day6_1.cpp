// Solution to day6.1 : https://adventofcode.com/2025/day/6
// Created by James Schaffer on 15/12/2025.

#include "Day6_1.h"

std::string Day6_1::run(const std::string &inputFile_dir) {
	std::ifstream inputFile(inputFile_dir);
	std::string line;

	// Array of columns
	std::vector<std::vector<long long>> grid;

	// Read numbers into grid array
	while (std::getline(inputFile, line)) {
		if (line[0] == '+' || line[0] == '*') break;

		int splitIndex=0;
		int colNumb = 0;

		while (splitIndex != std::string::npos) {
			splitIndex = line.find(' ');
			auto tmp = line.substr(0, splitIndex);
			line = line.substr(splitIndex+1, line.size() -1);

			// skips if a double/more space
			if (tmp.empty()) continue;

			// Add each cell
			if (grid.size() <= colNumb) grid.emplace_back();
			grid[colNumb++].push_back(std::stoll(tmp));
		}
	}

	// Read last row (operators) and perform math operations
	int colNumb = 0;
	int i = 0;
	long long ret = 0;

	while (i < line.size()) {
		// skips if a space
		if (line[i] == ' ') {i++; continue;}

		long long lineRet;

		if (line[i] == '+') lineRet = 0;
		else if (line[i] == '*') lineRet = 1;

		// do maths
		for (long long val : grid[colNumb]) {
			if (line[i] == '+') lineRet += val;
			else if (line[i] == '*') lineRet *= val;
		}

		colNumb++;
		ret += lineRet;
		i++;
	}

	inputFile.close();

	return std::to_string(ret);
}
