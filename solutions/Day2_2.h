// Solution to day2.2 : https://adventofcode.com/2025/day/2
// Created by James Schaffer on 04/12/2025.

#ifndef ADVENTOFCODE_2025_DAY2_2_H
#define ADVENTOFCODE_2025_DAY2_2_H
#include <string>
#include <fstream>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

class Day2_2 {
public:
	static constexpr __int64 LLpow10[] = {
		1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000, 1000000000000000, 10000000000000000, 100000000000000000, 1000000000000000000
	};

	static int simpleSI(long long i, int digits, int repeats);

	static std::vector<long long> getIDs(long long l_int, long long r_int, int l_dig, int r_dig);
	static std::string run(const std::string &inputFile_dir);
};


#endif //ADVENTOFCODE_2025_DAY2_2_H