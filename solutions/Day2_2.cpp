// Solution to day2.2 : https://adventofcode.com/2025/day/2
// Created by James Schaffer on 04/12/2025.

#include "Day2_2.h"

#include <algorithm>
#include <set>

// finds indexes for getIDs, I dont remember why its called this
int Day2_2::simpleSI(__int64 x, int digits, int repeats) {
	if (x==0) return 0;

	__int64 ret = 0;

	for (int i=0; i<repeats; i++) {
		//std::cout << floor(i * ceil(floor(log10(x)) / repeats)) << ", ";
		ret += LLpow10[
			// log of ll ????? log10 is for double not long long
			static_cast<int>(floor(i * ceil(floor(log10(x)) / repeats)))
		];
	}

	//std::cout << ret << " ~ ";

	return (x / ret);
}

// returns all invalid ids between 2 values
std::vector<__int64> Day2_2::getIDs(__int64 l_int, __int64 r_int, int l_dig, int r_dig) {
	// set max number of repetitions to r (r>l so r will have the most digits)
	int max_n = r_dig;

	std::set<__int64> result = {};

	// n=2 as there must be more than one occurrence of a sub int for it to repeat (repetition is multiple occurrences of the same thing)
	for (int n = 2; n <= max_n; ++n) {
		// Blocks invalid ranges
		if ( l_dig==r_dig && (l_dig%n != 0)) {
			// std::cout << std::endl << "   n=" << n << " , canceled";
			continue;
		}

		__int64 lc_int = l_int;
		__int64 rc_int = r_int;

		int lc_dig = l_dig;
		int rc_dig = r_dig;

		// Maps number&digits to next value which is a multiple of n (numb of repeats) , ceil vs floor should make no difference
		if ( lc_dig%n != 0 ) {
			lc_dig += n - lc_dig%n;
			lc_int = LLpow10[lc_dig -1];
		}
		if ( rc_dig%n != 0 ) {
			rc_dig += n - rc_dig%n;
			rc_int = LLpow10[rc_dig -1];
		}

		// find index bounds for the id gen to generate
		int l_index = simpleSI(lc_int, lc_dig, n);
		int r_index = simpleSI(rc_int, rc_dig, n);

		// std::cout << std::endl << "   n=" << n << " , Value bounds:" << lc_int << "," << rc_int << " , Value digs:" << lc_dig << "," << rc_dig << " , Index bounds:" << l_index << "," << r_index<< " : [";

		for (int i = l_index; i <= r_index; ++i) {
			__int64 x = 0;

			for (int pow = 0; pow < n; ++pow) {
				x += i * LLpow10[pow * static_cast<int>(ceil(log10(i + 0.01f)))];
			}

			// std::cout << x << ", ";

			if (l_int <= x && x <= r_int) {
				result.insert(x);
			}
		}

		// std::cout << "] ";
	}

	std::vector<__int64> ret_vec(result.begin(), result.end());
	return ret_vec;
}

std::string Day2_2::run(const std::string &inputFile_dir) {
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

		// std::cout << "_" << l << "_ vs _" << l_i << "_ (" << l_digs << ")" << std::endl;
		// std::cout << "_" << r << "_ vs _" << r_i << "_ (" << r_digs << ")" << std::endl;

		// std::cout << l_i << "(" << l_digs << ")-" << r_i << "(" << r_digs << ") = ";

		std::vector<__int64> ids = getIDs(l_i, r_i, l_digs, r_digs);

		// std::cout << std::endl << " ~~~~~~~~~~~ " << std::endl;

		for (__int64 i: ids) {
			invalidSum += i;
			// std::cout << i << ", ";
		}
		// std::cout << std::endl;

		// std::cout << invalidSum << std::endl;
	}

	inputFile.close();
	return std::to_string(invalidSum);
}
