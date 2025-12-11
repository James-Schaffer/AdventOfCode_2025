// Solution to day3.2 : https://adventofcode.com/2025/day/3#part2
// Created by James Schaffer on 10/12/2025.

#ifndef ADVENTOFCODE_2025_DAY3_2_H
#define ADVENTOFCODE_2025_DAY3_2_H
#include <string>
#include <fstream>

class Day3_2 {
public:
	static bool update_ret(int* ret, int& val, int& lp, int& rp);
	static __int64 maxInBank(std::string bank);
	static std::string run(const std::string &inputFile_dir);
};


#endif //ADVENTOFCODE_2025_DAY3_2_H