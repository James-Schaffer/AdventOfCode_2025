// Solution to day4.1 : https://adventofcode.com/2025/day/4
// Created by James Schaffer on 11/12/2025.

#include "Day4_1.h"

#include <iostream>

int Day4_1::numbValid(const std::string last, const std::string current, const std::string next) {
	int count = 0;

	bool up = !last.empty(), down = !next.empty();

	for (int i=0; i < current.length(); i++) {
		if (current[i] == '.') continue; // Skip non-rolls

		int i_count = 0;
		bool left = !i==0, right = !(i==current.length()-1);

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

		if (i_count < 4) count++;

	}

	return count;
}

std::string Day4_1::run(const std::string &inputFile_dir) {
	std::ifstream inputFile(inputFile_dir);

	int result = 0;

	bool running = true; // allows for 1 more iteration at end
	std::string prev, current, next;

	do { prev=current, current=next;
		if (!std::getline(inputFile, next)) {
			next = "";
			running=false; // If at end update counter
		}
		if (current.empty()) continue; // skip first iteration

		result += numbValid(prev, current, next);

	} while (running);


	inputFile.close();
	return std::to_string(result);
}
