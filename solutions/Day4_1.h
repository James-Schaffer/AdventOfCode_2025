// FILE INFOMATION HERE
// Created by James Schaffer on 11/12/2025.

#ifndef ADVENTOFCODE_2025_DAY4_1_H
#define ADVENTOFCODE_2025_DAY4_1_H
#include <string>
#include <fstream>

class Day4_1 {
public:
	static constexpr int ADJ_MATRIX[8][2] = {{0,1}, {1,1}, {1,0}, {1,-1}, {0, -1}, {-1,-1}, {-1,0}, {-1,1}};
	static constexpr int TMP_MATRIX[3] = {-1, 0, 1};
	static int numbValid(const std::string last, const std::string current, const std::string next);
	static std::string run(const std::string &inputFile_dir);
};


#endif //ADVENTOFCODE_2025_DAY4_1_H