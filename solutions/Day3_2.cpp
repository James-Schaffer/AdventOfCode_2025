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

	//std::cout << bank << std::endl;

	for (; bp!=bank.end(); ++bp) {
		int val = *bp - '0';
		//std::cout << val;

		bool tmp = update_ret(ret, val, lp, rp);

		if (tmp) ret[++rp] = val;

		// std::cout << " : [";
		// for (int i : ret) {
		// 	std::cout << i << ",";
		// }
		// std::cout << "]";
		//std::cout << " : bp_" << *bp << ", ep_" << *ep << ", lp_" << lp << ", rp_" << rp << std::endl;


		if (bp == ep) {
			++ep;
			++lp;
			//std::cout << " : updated ep_lp";
		}
	}

	int p = 11;
	__int64 r = 0;
	for (int i : ret) {
		r += i * pow(10, p--);
	}

	//std::cout << std::fixed << r << std::endl;

	return r;

	// for (std::string::iterator r = ++++bank.begin(); r!=bank.end(); ++r) {
	//
	//
	// 	int val = *r - '0';
	//
	// 	if (maxR > maxL) {
	// 		maxL = maxR;
	// 		maxR = val -1; // forces r to move over
	// 	}
	//
	// 	if (val > maxR) {
	// 		maxR = val;
	// 	}
	// }
	//
	// return (maxL*10)+maxR;
}

std::string Day3_2::run(const std::string &inputFile_dir) {
	std::ifstream inputFile(inputFile_dir);

	__int64 result = 0;

	for (std::string line; std::getline(inputFile, line);) {
		result += maxInBank(line);
	}

	inputFile.close();
	return std::to_string(result);
}
