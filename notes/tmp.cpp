// Solution to day5.2 : https://adventofcode.com/2025/day/5#part2
// Created by James Schaffer on 14/12/2025.

#include "Day5_2.h"

int Day5_2::findIndex(const std::vector<__int64>& t, __int64 v) {
	for (int i = 0; i < t.size(); ++i) {
		if (t[i] > v) return i - 1;
	}
	return t.size() - 1;
}


void Day5_2::combineRanges(std::vector<__int64>& target, __int64* newRange) {
	int siTarget=-2, eiTarget=-2;

	// Set si and ei target to first index of which target[i] is larger than them (-1)
	// i.e. find the biggest value smaller than them
	for (int i = 0; i < target.size(); ++i) {
		if (siTarget == -2 && target[i] > newRange[0]) siTarget = i-1;
		if (eiTarget == -2 && target[i] > newRange[1]) eiTarget = i-1;
	}

	// If newRange after last range just add both
	if (siTarget == -2) {
		target.push_back(newRange[0]);
		target.push_back(newRange[1]);
		return removeTouching(target);
	}

	// If newRange before first range just add both
	if (eiTarget == -1) {
		target.insert(target.begin(), newRange[1]);
		target.insert(target.begin(), newRange[0]);
		return removeTouching(target);
	}

	// If eiTarget is the biggest set it to last index # check
	if (eiTarget == -2) {
		eiTarget = target.size() -1;
	}

	// Conditions for if both in same target range
	if (siTarget == eiTarget) {
		// If both in same range do nothing
		if (siTarget%2 == 0) return;

		// If both outside range in same gap just add both
		target.insert(
			target.begin() + siTarget +1,
			{ newRange[0], newRange[1] }
		);

		return removeTouching(target);
	}

	// If targets are in/out different ranges

	// Remove all between :
	const auto it = target.erase(
		target.begin() + siTarget +1,
		target.begin() + eiTarget +1
	);

	// If end is outside a range, add end
	if (eiTarget%2 != 0) {
		target.insert(it, newRange[1]);
	}

	// If start is outside a range, add start
	if (siTarget%2 != 0) {
		target.insert(it, newRange[0]);
	}

	return removeTouching(target);
}

void combineRanges_2(std::vector<__int64>& target, __int64* newRange) {
	std::cout << " Pre : " << std::endl;
	for (int i: target) {
		std::cout << i << ", ";
	}
	std::cout << std::endl;

	std::cout << newRange[0] << ", " << newRange[1];

	std::cout << std::endl;
	std::cout << std::endl;

	// If target empty or new range before all others add it
	if (target.empty() || newRange[1] < target[0] -1) {
		target.insert(
			target.begin(),
			{newRange[0], newRange[1]}
		);

		return;
	}

	std::vector<__int64> newVals = {};

	int it = 0;

	// When next val is less than first range val
	while (it < target.size() && target[it] < newRange[0]) {
		newVals.push_back(target[it]);
		++it;
	}

	std::cout << it << " A(" << target[it] << ")" << std::endl;
	for (int i: newVals) {
		std::cout << i << ", ";
	}
	std::cout << std::endl;

	// If last value added closes a range then :
	if (it%2 == 0) {
		// If it's one less than new range merge them
		if (newVals[newVals.size() -1]+1 == newRange[0]) newVals.pop_back();
		// Otherwise add new range opening
		else newVals.push_back(newRange[0]);
	}

	// If last value opened a range ignore it

	std::cout << it << " B(" << target[it] << ")" << std::endl;
	for (int i: newVals) {
		std::cout << i << ", ";
	}
	std::cout << std::endl;

	// Ignore all between
	while (it < target.size() && target[it] < newRange[1]) {
		++it;
	}

	std::cout << it << " C(" << target[it] << ")" << std::endl;
	for (int i: newVals) {
		std::cout << i << ", ";
	}
	std::cout << std::endl;

	// If last value opened a range then ignore it and add self
	if (it%2 == 1) {
		newVals.push_back(newRange[1]);
	}

	// If the last value closes a range then :
	else {
		// If next value is one more than new range merge them (and then increment it)
		if (target[it]-1 == newRange[1]) newVals.push_back(target[it++]);
		// Otherwise ignore
		else;
	}

	while (it < target.size()) {
		newVals.push_back(target[it]);
		++it;
	}

	std::cout << it << " D(" << "NA" << ")" << std::endl;
	for (int i: newVals) {
		std::cout << i << ", ";
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void Day5_2::removeTouching(std::vector<__int64>& target) {
	// Ensure no touching ranges ( e.g. 1-2 3-4 ) , not best but not sure how to fix right now
	std::vector<int> toRemove;

	for (int i = 1; i < target.size() -1; i+=2) {
		if (target[i]+1 == target[i+1]) {
			toRemove.push_back(i);
		}
	}

	int j =0;
	for (int i: toRemove) {
		target.erase(target.begin() + i - j);
		target.erase(target.begin() + i - (j++));
	}
}

// target must be sorted
std::vector<long long> reduceRanges(const std::vector<std::array<long long, 2>>& target) {
	int c = 0;
	std::vector<long long> ranges;

	for (auto i: target) {

		if (c == 0 && i[0] == 1) {
			ranges.push_back(i[1]);
			++c;
		}
		else if (c == 1 && i[0] == -1) {
			ranges.push_back(i[1]);
			--c;
		} else {
			c += i[0];
		}

		// std::cout << c << " : " << i[0] << "_" << i[1] << ", ";
	}

	// std::cout << std::endl;

	return ranges;
}

std::string Day5_2::run(const std::string &inputFile_dir) {
	std::ifstream inputFile(inputFile_dir);
	std::vector<std::array<long long, 2>> dat;
	std::string line;

	for (std::getline(inputFile, line);!line.empty();std::getline(inputFile, line)) {
		std::string l_s, r_s;
		const int splitIndex = line.find('-');

		// std::cout << line << " - ";

		l_s = line.substr(0, splitIndex);
		r_s = line.substr(splitIndex+1, line.size() -1);

		long long newVals[2] = {
			std::stoll(l_s),
			std::stoll(r_s)
		};

		// Sort them into dat, l=dat : r=newVals (always size=2)
		auto it = dat.begin();
		int p = 0;
		while (p<2 && it != dat.end()) {
			long long val = (*it)[1];

			if (val > newVals[p]) {
				// 0-> 1, 1-> -1
				it = dat.insert(it, { p ? -1 : 1, newVals[p]});
				++p;
			} else {
				++it;
			}
		}
		while (p < 2) {
			dat.push_back({ p ? -1 : 1, newVals[p]});
			++p;
		}
	}

	inputFile.close();

	std::vector<long long> ranges = reduceRanges(dat);
	removeTouching(ranges);

	unsigned long long fresh = 0;

	// Count numb fresh
	for (int i=0; i<ranges.size(); i+=2) {
		fresh += (ranges[i+1] - ranges[i]) +1;
	}

	return fresh;
}
