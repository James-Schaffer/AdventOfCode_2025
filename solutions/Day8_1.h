// Solution to day8.1 : https://adventofcode.com/2025/day/8
// Created by James Schaffer on 14/01/2026.

#ifndef ADVENTOFCODE_2025_DAY8_1_H
#define ADVENTOFCODE_2025_DAY8_1_H
#include <string>
#include <vector>
#include <array>
#include <cmath>
#include <fstream> // file read write
#include <iostream> // console io

class Day8_1 {
public:
	static std::string run(const std::string &inputFile_dir);
private:
	typedef struct {
		double dist;
		int fromIndex;
		int toIndex;
	} distNode;

	static void copyArray(const std::vector<distNode>& source, std::vector<distNode> *target, int l_s, int r_s, int l_t, int r_t);

	static void mergeSort(std::vector<distNode>* source);
	static void mergeSortHelper(std::vector<distNode>* source, int l, int r);
	static void merge(std::vector<distNode>* source, int lp, int rp, int re);

	static double distBetween3D(const std::array<long long, 4>& a, const std::array<long long, 4>& b);
};

#endif //ADVENTOFCODE_2025_DAY8_1_H