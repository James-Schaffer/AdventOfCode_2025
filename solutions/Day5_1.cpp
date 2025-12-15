// Solution to day5.1 : https://adventofcode.com/2025/day/5
// Created by James Schaffer on 13/12/2025.

#include "Day5_1.h"

void Day5_1::addDat(std::vector<std::array<long long, 2>>& target, long long newVals[2]) {
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
std::vector<long long> Day5_1::reduceRanges(const std::vector<std::array<long long, 2>>& target) {
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

std::string Day5_1::run(const std::string &inputFile_dir) {
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

	std::vector<long long> ranges = reduceRanges(dat);

	int fresh = 0;

	// Check if values in ranges
	while (std::getline(inputFile, line)) {
		__int64 val = std::stoll(line);

		for (int i=0; i < ranges.size(); ++i) {
			// if outside range
			if (i%2==0 && val < ranges[i]) {
				break;
			}
			// if inside range
			else if (i%2==1 && val <= ranges[i]) {
				fresh++;
				break;
			}
		}
	}

	inputFile.close();
	return std::to_string(fresh);
}
