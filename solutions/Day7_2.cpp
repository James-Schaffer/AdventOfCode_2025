// Solution to day7.2 : https://adventofcode.com/2025/day/7#part2
// Created by James Schaffer on 13/01/2026.

#include "Day7_2.h"

int Day7_2::branchTimeline(int pos, int line, std::vector<bool> tachyons, std::vector<std::string> reducedLines, std::string debug) {
	// If at end stop, end of timeline
	if (line >= reducedLines.size()) {
		std::cout << debug << std::endl;
		return 1;
	}

	// If empty move down a line
	if (reducedLines[line][pos] == '.') {
		return branchTimeline(pos, line+1, tachyons, reducedLines, debug + ".N");
	}

	// Simulate both timelines
	int ret = 0;

	ret += branchTimeline(pos-1, line+1, tachyons, reducedLines, debug + ".L");
	ret += branchTimeline(pos+1, line+1, tachyons, reducedLines, debug + ".R");

	return ret;
}


std::string Day7_2::run(const std::string &inputFile_dir) {
	std::ifstream inputFile(inputFile_dir);
	std::string line;

	// All lines without empty lines
	std::vector<std::string> reducedLines;
	int lineCount = 0;
	int sPos = -1;

	// Read text file, it ignores last line but doesn't make a difference
	while (std::getline(inputFile, line)) {
		// Find S pos
		if (lineCount == 0) {
			for (int i=0; i < line.size(); i++) {
				if (line[i]=='S') {
					sPos = i;
					break;
				}
			}
		}

		// Skip every other line as blank, increment line count after check
		if ((lineCount++)%2 == 1) continue;
		// Add line
		reducedLines.push_back(line);
	}

	inputFile.close();

	int count = branchTimeline(sPos, 1, {}, reducedLines, "S");

	return std::to_string(count);
}