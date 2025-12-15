// Solution to day4.2 : https://adventofcode.com/2025/day/4#part2
// Created by James Schaffer on 12/12/2025.

#ifndef ADVENTOFCODE_2025_DAY4_2_H
#define ADVENTOFCODE_2025_DAY4_2_H
#include <string>
#include <fstream>

class Day4_2 {
public:
	static int numbValid(const std::string& last, const std::string& current, const std::string& next, std::string& newLine);
	static std::string run(const std::string &inputFile_dir);
};

#endif //ADVENTOFCODE_2025_DAY4_2_H