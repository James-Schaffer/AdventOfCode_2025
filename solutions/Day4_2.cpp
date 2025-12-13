// Solution to day4.2 : https://adventofcode.com/2025/day/4#part2
// Created by James Schaffer on 12/12/2025.

#include "Day4_2.h"

#include <iostream>
#include <vector>

int Day4_2::numbValid(const std::string& last, const std::string& current, const std::string& next, std::string& newLine) {
	int count = 0;

	bool up = !last.empty(), down = !next.empty();

	for (int i=0; i < current.length(); i++) {
		if (current[i] == '.') {
			newLine += ".";
			continue;
		} // Skip non-rolls

		int i_count = 0;
		const bool left = i!=0, right = i!=current.length()-1;

		// Top row
		if (up) {
			if (left && last[i-1]=='@')		i_count++;
			if (last[i]=='@')				i_count++;
			if (right && last[i+1]=='@')	i_count++;
		}
		// Middle row
		if (left && current[i-1]=='@')		i_count++;
		if (right && current[i+1]=='@')		i_count++;

		// Bottom row
		if (down) {
			if (left && next[i-1]=='@')		i_count++;
			if (next[i]=='@')				i_count++;
			if (right && next[i+1]=='@')	i_count++;
		}

		if (i_count < 4) {
			count++;
			newLine += '.';
		} else {
			newLine += current[i];
		}
	}

	return count;
}

std::string Day4_2::run(const std::string &inputFile_dir) {
	std::ifstream inputFile(inputFile_dir);

	std::vector<std::string> grid;
	std::vector<std::string> next_grid;

	std::string line;
	while (std::getline(inputFile, line)) {
		grid.push_back(line);
	}

	inputFile.close();


	int result = 0, roundResult = 0;

	do {
		bool running = true; // allows for 1 more iteration at end
		std::string prev, current, next, newLine;
		roundResult = 0;

		for (int i=0; i <= grid.size(); i++) {
			// Update prev, current, next
			prev=current, current=next;
			if (i!=grid.size()) next=grid[i];
			else next="";

			newLine = ""; // Clear newLine

			if (current.empty()) continue; // skip first iteration (but update values correctly)

			roundResult += numbValid(prev, current, next, newLine);
			next_grid.push_back(newLine);
		}

		// update grid vars
		grid = next_grid;
		next_grid.clear();

		// update result vars
		result += roundResult;
	} while (roundResult != 0); // Keep going till no change

	return std::to_string(result);
}

