// Solution to day5.2 : https://adventofcode.com/2025/day/5#part2
// Created by James Schaffer on 14/12/2025.

#ifndef ADVENTOFCODE_2025_DAY5_2_H
#define ADVENTOFCODE_2025_DAY5_2_H
#include <string>
#include <fstream> // file read write
#include <vector>
#include <array>
#include <iostream> // console io


class Day5_2 {
public:
	static void addDat(std::vector<std::array<long long, 2>>& target, long long newVals[2]);
	static std::vector<long long> reduceRanges(const std::vector<std::array<long long, 2>>& target);
	static std::string run(const std::string &inputFile_dir);
};



#endif //ADVENTOFCODE_2025_DAY5_2_H