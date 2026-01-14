// Solution to day7.2 : https://adventofcode.com/2025/day/7#part2
// Created by James Schaffer on 13/01/2026.

#include "Day7_2.h"

std::string Day7_2::run(const std::string &inputFile_dir) {
	std::ifstream inputFile(inputFile_dir);
	std::string line;

	// All lines without empty lines
	std::vector<long long> working = {};
	std::vector<bool> tachyons = {};
	int lineCount = 0;
	int lineWidth = 0;

	// Read text file, it ignores last line but doesn't make a difference
	while (std::getline(inputFile, line)) {
		// Skip every other line as blank, increment line count after check
		if ((lineCount++)%2 == 1) continue;

		std::vector<long long> newWorking = {};
		newWorking.resize(lineWidth); // Will be wrong size (0) on first itteration but not an issue as skipped

		// For each char in line
		for (int i=0; i < line.size(); i++) {
			// If the start, setup and go to next
			if (line[i]=='S') {
				lineWidth = line.size();

				working.resize(lineWidth, 0);
				tachyons.resize(lineWidth, false);
				newWorking.resize(lineWidth);

				newWorking[i] = 1;
				tachyons[i] = true;
				break;
			}

			// If on first line and not S, continue
			if (working.size() == 0) continue;

			// If no tachyon here continue
			if (working[i] == 0) continue;

			// If empty below, move down
			if (line[i] == '.') {
				newWorking[i] += working[i];
				continue;
			}

			// If splitter, split
			newWorking[i-1] += working[i];
			newWorking[i+1] += working[i];
		}

		working = newWorking;
	}

	inputFile.close();

	long long count = 0;
	for (long long i : working) {
		count += i;
	}
	return std::to_string(count);
}