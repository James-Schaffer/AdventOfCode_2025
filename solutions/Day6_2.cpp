// Solution to day6.2 : https://adventofcode.com/2025/day/6#part2
// Created by James Schaffer on 02/01/2026.

#include "Day6_2.h"

std::string Day6_2::run(const std::string &inputFile_dir) {
	std::ifstream inputFile(inputFile_dir);
	std::string line;

	// Array of columns
	std::vector<int> grid;

	// Read numbers into grid array
	while (std::getline(inputFile, line)) {
		if (line[0] == '+' || line[0] == '*') break;

		for (int i = 0; i < line.size(); i++) {
			if (grid.size() < i+1) grid.resize(i+1);

			if (line[i] == ' ') continue;
			grid[i] = (grid[i]*10) + line[i] - '0';
		}
	}

	bool addTmultF = true;

	long long total = 0;
	long long subTotal = 0;

	// Perform operations
	for (int i = 0; i < grid.size(); i++) {
		char tmpChar = i < line.size() ? line[i] : ' ';
		char nextChar = i+1 < line.size() ? line[i+1] : ' ';

		if (i+2 < grid.size() && nextChar != ' ') {
			continue;
		}

		if (tmpChar == '+') {
			addTmultF = true;
			total += subTotal;
			subTotal = 0;
		} else if (tmpChar == '*') {
			addTmultF = false;
			total += subTotal;
			subTotal = 1;
		}

		if (addTmultF) {
			subTotal += grid[i];
		} else {
			subTotal *= grid[i];
		}
	}

	total += subTotal;

	inputFile.close();

	return std::to_string(total);
}