// Solution to day2.1 : https://adventofcode.com/2025/day/2
// Created by James Schaffer on 03/12/2025

#include "Day2_1.h"

constexpr __int64 LLpow10[] = {
	1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000, 1000000000000000, 10000000000000000, 100000000000000000, 1000000000000000000
};

// finds indexes for getIDs
int simpleSI(__int64 i, int digits) {
	return (i/(1+ LLpow10[static_cast<int>(floor(digits / 2.0f))]));
}

// returns all invalid ids between 2 values
std::vector<__int64> getIDs(__int64 l_int, __int64 r_int, int l_dig, int r_dig) {
	int l_index = simpleSI(l_int, l_dig);
	int r_index = simpleSI(r_int, r_dig);

	std::vector<__int64> result = {};

	for (int i = l_index; i <= r_index; ++i) {
		__int64 x = i * (1 + LLpow10[static_cast<int>(ceil(log10(i + 0.01f)))]);

		if (l_int <= x && x <= r_int) {
			result.push_back(x);
		}
	}
	return result;
}

std::string Day2_1::run(const std::string &inputFile_dir) {
	std::ifstream inputFile(inputFile_dir);

	__int64 invalidSum = 0;
	char data_buffer[40]; // int64 max is 19. (2 ints, comma, dash) -> 40

	for (;inputFile.get(data_buffer, 40, ','); inputFile.get()) {
		std::string l = strtok(data_buffer, "-");
		std::string r = strtok(NULL, "-");

		__int64 l_i = atoll(l.c_str());
		__int64 r_i = atoll(r.c_str());

		int l_digs = l.length();
		int r_digs = r.length();

		// if no even digit numbers in bounds continue
		if ( l_digs==r_digs && (l_digs%2 == 1)) {
			continue;
		}

		// enforces target value is even digit value
		if ( l_digs%2 == 1 ) {
			l_i = LLpow10[l_digs];
			l_digs++;
		}
		if ( r_digs%2 == 1 ) {
			r_i = LLpow10[r_digs];
			r_digs++;
		}

		std::vector<__int64> ids = getIDs(l_i, r_i, l_digs, r_digs);

		for (__int64 i: ids) {
			invalidSum += i;
		}
	}

	inputFile.close();
	return std::to_string(invalidSum);
}
