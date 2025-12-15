// Solution to day5.1 : https://adventofcode.com/2025/day/5
// Created by James Schaffer on 13/12/2025.

#ifndef ADVENTOFCODE_2025_DAY5_1_H
#define ADVENTOFCODE_2025_DAY5_1_H
#include <string>
#include <fstream> // file read write
#include <vector>
#include <array>
#include <iostream> // console io

class Day5_1 {
public:
	static void addDat(std::vector<std::array<long long, 2>>& target, long long newVals[2]);
	static std::vector<long long> reduceRanges(const std::vector<std::array<long long, 2>>& target);
	static std::string run(const std::string &inputFile_dir);
};



#endif //ADVENTOFCODE_2025_DAY5_1_H