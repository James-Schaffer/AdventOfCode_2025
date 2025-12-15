// Solution to day4.1 : https://adventofcode.com/2025/day/4
// Created by James Schaffer on 11/12/2025.

#ifndef ADVENTOFCODE_2025_DAY4_1_H
#define ADVENTOFCODE_2025_DAY4_1_H
#include <string>
#include <fstream>

class Day4_1 {
public:
	static int numbValid(const std::string last, const std::string current, const std::string next);
	static std::string run(const std::string &inputFile_dir);
};


#endif //ADVENTOFCODE_2025_DAY4_1_H