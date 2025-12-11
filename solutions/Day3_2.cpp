// Solution to day3.2 : https://adventofcode.com/2025/day/3#part2
// Created by James Schaffer on 10/12/2025.
#include "Day3_2.h"

#include <cmath>
#include <iostream>

bool Day3_2::update_ret(int* ret, int& val, int& lp, int& rp) {
	for (int i=lp; i<(rp+1); ++i) {
		if (val > ret[i]) {
			ret[i] = val;
			rp = i;
			return false;
		}
	}
	return true;
}

__int64 Day3_2::maxInBank(std::string bank) {
	int ret[12] = {};

	std::string::iterator bp = bank.begin(); // bank pointer
	std::string::iterator ep = bank.end() - 12; // target pointer

	int lp = 0; // index of the most left pointer which can be moved
	int rp = 0; // index of last added number

	ret[0] = -1;

	if (bank.size() < 12) return 0;

	for (; bp!=bank.end(); ++bp) {
		int val = *bp - '0';

		bool tmp = update_ret(ret, val, lp, rp);

		if (tmp && rp < 11) ret[++rp] = val;

		if (bp == ep) {
			++ep;
			++lp;
		}
	}

	//int p = 11;
	__int64 r = 0;
	for (int i : ret) {
		//r += i * pow(10, p--); less efficient
		r = r*10 + i;
	}

	return r;
}

std::string Day3_2::run(const std::string &inputFile_dir) {
	std::ifstream inputFile(inputFile_dir);

	__int64 result = 0;

	for (std::string line; std::getline(inputFile, line);) {
		result += Day3_2::maxInBank(line);
	}

	inputFile.close();
	return std::to_string(result);
}
