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
/*














		int splitIndex=0;
		int colNumb = 0;

		int i=0;

		while (i < line.size()) {
			// If at end
			if (i == line.size()-1) {
				if (line[i] == ' ') {
					// end
				} else {
					// add and stop
				}
			}

			if (line[i] == ' ') {

			}
		}


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

	for (auto col : grid) {
		for (int i : col) {
			std::cout << i << ", ";
		}
		std::cout << std::endl;
	}

	// Read last row (operators) and perform math operations
	int colNumb = 0;
	int i = 0;
	long long ret = 0;

	std::cout << line << std::endl;
	std::cout << line.size() << std::endl;

	while (i < line.size()) {
		std::cout << "_" << i << std::endl;

		// skips if a space
		if (line[i] == ' ') {i++; continue;}

		std::cout << line[i] << "(" << i << "," << colNumb << ")" << std::endl;

		long long lineRet;

		if (line[i] == '+') lineRet = 0;
		else if (line[i] == '*') lineRet = 1;

		// do maths
		for (long long val : grid[colNumb]) {
			std::cout << "  " << val << line[i] << std::endl;
			if (line[i] == '+') lineRet += val;
			else if (line[i] == '*') lineRet *= val;
		}

		std::cout << lineRet << std::endl;

		colNumb++;
		ret += lineRet;
		i++;
	}

	inputFile.close();

	return std::to_string(ret);
}
*/