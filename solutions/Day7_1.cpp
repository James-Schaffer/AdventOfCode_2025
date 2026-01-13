// Solution to day7.1 : https://adventofcode.com/2025/day/7
// Created by James Schaffer on 13/01/2026.

#include "Day7_1.h"

std::string Day7_1::run(const std::string &inputFile_dir) {
	std::ifstream inputFile(inputFile_dir);
	std::string line;

	std::vector<bool> tachyons = {};
	int count = 0;
	int lineCount = 0;

	// Read text file, it ignores last line but doesn't make a difference
	while (std::getline(inputFile, line)) {
		// Skip every other line as blank, increment line count after check
		if ((lineCount++)%2 == 1) continue;

		// For each char in line
		for (int i=0; i < line.size(); i++) {
			// If the start, setup and go to next
			if (line[i]=='S') {
				tachyons.resize(line.size(), false);
				tachyons[i] = true;
				break;
			}

			// If empty continue
			if (line[i]=='.') continue;

			// If location not currently a beam continue
			if (!tachyons[i]) continue;

			// Split tachyon
			if (i > 0 && !tachyons[i-1]) {
				tachyons[i-1] = true;
			}
			if (i < tachyons.size()-1 && !tachyons[i+1]) {
				tachyons[i+1] = true;
			}

			tachyons[i] = false;
			count++;
		}
	}

	inputFile.close();
	return std::to_string(count);
}
