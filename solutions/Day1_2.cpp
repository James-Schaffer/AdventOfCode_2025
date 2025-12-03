// Solution to day1.2 : https://adventofcode.com/2025/day/1#part2
// By James Schaffer 02/12/2025

#include "Day1_2.h"

#include <iostream>

std::string Day1_2::run(const std::string &inputFile_dir) {
	std::ifstream inputFile(inputFile_dir);

	int p = 50;
	int count = 0;

	for (std::string line; std::getline(inputFile, line);) {
		const int mult = (line.at(0) == 'R' ? 1 : -1);
		const int val = std::stoi(line.substr(1, line.size()-1));

		int t = p + mult * val;
		t %= 100;
		if (t < 0) t += 100;

		if (val > 99) {
			count += val / 100;
		}
		if (p!=0 && (t==0 || (mult==1 && p>t) || (mult==-1 && p<t))) {
			count++;
		}

		p=t;
	}

	inputFile.close();
	return std::to_string(count);
};
