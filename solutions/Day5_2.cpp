// Solution to day5.2 : https://adventofcode.com/2025/day/5#part2
// Created by James Schaffer on 14/12/2025.

#include "Day5_2.h"

void Day5_2::addDat(std::vector<std::array<long long, 2>>& target, long long newVals[2]) {
	// Sort them into dat, l=dat : r=newVals (always size=2)
	auto it = target.begin();
	int p = 0;
	while (p<2 && it != target.end()) {
		long long val = (*it)[1];

		// open before close
		if (val > newVals[p] || (val == newVals[p] && (*it)[0] < (p ? -1 : 1))) {
			// 0-> 1, 1-> -1
			it = target.insert(it, { p ? -1 : 1, newVals[p]});
			++p;
		} else {
			++it;
		}
	}
	while (p < 2) {
		target.push_back({ p ? -1 : 1, newVals[p]});
		++p;
	}
}

// target must be sorted
std::vector<long long> Day5_2::reduceRanges(const std::vector<std::array<long long, 2>>& target) {
	int c = 0;
	std::vector<long long> ranges;

	for (const auto& e : target) {
		const long long prev = c;
		c += e[0];

		if (prev == 0 && c > 0 || prev > 0 && c == 0) {
			ranges.push_back(e[1]);
		}
	}

	return ranges;
}

std::string Day5_2::run(const std::string &inputFile_dir) {
	std::ifstream inputFile(inputFile_dir);
	std::vector<std::array<long long, 2>> dat;
	std::string line;

	for (std::getline(inputFile, line);!line.empty();std::getline(inputFile, line)) {
		std::string l_s, r_s;
		const int splitIndex = line.find('-');

		l_s = line.substr(0, splitIndex);
		r_s = line.substr(splitIndex+1, line.size() -1);

		long long newVals[2] = {
			std::stoll(l_s),
			std::stoll(r_s)
		};

		addDat(dat, newVals);
	}

	inputFile.close();

	std::vector<long long> ranges = reduceRanges(dat);

	unsigned long long fresh = 0;
	// Count numb fresh
	for (int i=0; i<ranges.size(); i+=2) {
		fresh += (ranges[i+1] - ranges[i]) +1;
	}

	return std::to_string(fresh);
}