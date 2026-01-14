// Solution to day7.2 : https://adventofcode.com/2025/day/7#part2
// Created by James Schaffer on 13/01/2026.

#ifndef ADVENTOFCODE_2025_DAY7_2_H
#define ADVENTOFCODE_2025_DAY7_2_H
#include <string>
#include <vector>
#include <fstream> // file read write
#include <iostream> // console io

class Day7_2 {
public:
	static int branchTimeline(int pos, int line, std::vector<bool> tachyons, std::vector<std::string> reducedLines, std::string debug);
	static std::string run(const std::string &inputFile_dir);
};

#endif //ADVENTOFCODE_2025_DAY7_2_H