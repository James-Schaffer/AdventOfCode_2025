// Solution to day8.2 : https://adventofcode.com/2025/day/8#part2
// Created by James Schaffer on 20/01/2026.

#include "Day8_2.h"

void Day8_2::copyArray(const std::vector<distNode>& source, std::vector<distNode> *target, int l_s, int r_s, int l_t, int r_t) {
	if (r_s-l_s != r_t-l_t) {
		return;
	}

	for (int i=0; i<r_s-l_s; i++) {
		(*target)[l_t+i] = source[l_s+i];
	}
}

void Day8_2::merge(std::vector<distNode> *arr, int lp, int rp, int re) {
	const int lb = lp, s = re-lp;
	std::vector<distNode> newArr;

	const int le = rp;
	while (lp < le || rp < re) {
		newArr.push_back( ( (rp >= re) || ((lp < le) && ((*arr)[lp].dist < (*arr)[rp].dist)) ) ? (*arr)[lp++] : (*arr)[rp++] );
	}

	copyArray(newArr, arr, 0, s, lb, lb+s);
}

void Day8_2::mergeSortHelper(std::vector<distNode> *arr, int l, int r) {
	if (r-1 <2) {
		return;
	}

	int m = l + (r-l)/2;

	int ls = m-l;
	int rs = r-m;

	if (ls > 1) {
		mergeSortHelper(arr, l, m);
	}
	if (rs > 1) {
		mergeSortHelper(arr, m, r);
	}

	merge(arr, l, m, r);
}

void Day8_2::mergeSort(std::vector<distNode> *source) {
	mergeSortHelper(source, 0, source->size());
}


double Day8_2::distBetween3D(const std::array<long long, 4>& a, const std::array<long long, 4>& b) {
	const long long displacement[3] = {
		(a[0] - b[0]),
		(a[1] - b[1]),
		(a[2] - b[2])
	};

	return std::sqrt(
		(displacement[0] * displacement[0]) +
		(displacement[1] * displacement[1]) +
		(displacement[2] * displacement[2])
	);
}

std::string Day8_2::run(const std::string &inputFile_dir) {
	std::ifstream inputFile(inputFile_dir);
	std::string line;

	std::vector<distNode> distances; // [dist, fromIndex, toIndex]
	std::vector<std::array<long long, 4>> points; // [x, y, z, networkID]

	int MAX_NUMDISTANCES = 10;

	bool running = true;

	while (std::getline(inputFile, line)) {
		const int s1 = line.find(',');
		const int s2 = line.find(',', s1+1);

		std::array<long long, 4> newPoint = {
			std::stoll(line.substr(0, s1)),
			std::stoll(line.substr(s1+1, s2-s1-1)),
			std::stoll(line.substr(s2+1, line.size()-s2-1)),
			-1
		};

		// Check dist to each current point and add to array
		for (int i=0; i < points.size(); i++) {
			auto point = points[i];
			const double newDist = distBetween3D(newPoint, point);

			distances.push_back({
				newDist,
				i,
				static_cast<int>(points.size())
			});
		}

		// Add point to points
		points.push_back(newPoint);
	}

	inputFile.close();

	// Sort distances
	mergeSort(&distances);

	// For first MAX_NUMDISTANCES distances, add points to networks

	// [pointIndex, pointIndex]
	std::vector<std::vector<int>> networks;

	long long buffer[2] = {1, 1};

	networks.resize(1);

	for (int i=0; i < distances.size(); i++) {
		auto currentDist = distances[i];

		auto &pointA = points[currentDist.fromIndex];
		auto &pointB = points[currentDist.toIndex];

		// If neither, add both to a network
		if (pointA[3] == -1 && pointB[3] == -1) {
			networks.push_back({
				static_cast<int>(currentDist.fromIndex),
				static_cast<int>(currentDist.toIndex),
			});

			pointA[3] = networks.size() -1;
			pointB[3] = networks.size() -1;

			buffer[0] = pointA[0];
			buffer[1] = pointB[0];

			continue;
		}

		// If both in same network skip
		if (pointA[3] == pointB[3]) {
			continue;
		}

		// If just one, add other to one in a network
		// A
		if (pointA[3] != -1 && pointB[3] == -1) {
			networks[pointA[3]].push_back(currentDist.toIndex);
			pointB[3] = pointA[3];

			buffer[0] = pointA[0];
			buffer[1] = pointB[0];

			continue;
		}

		// B
		if (pointA[3] == -1 && pointB[3] != -1) {
			networks[pointB[3]].push_back(currentDist.fromIndex);
			pointA[3] = pointB[3];

			buffer[0] = pointA[0];
			buffer[1] = pointB[0];

			continue;
		}

		// If both, combine the networks (B -> A)
		if (pointA[3] != -1 && pointB[3] != -1) {
			int targetNetworkID = pointA[3];
			int sourceNetworkID = pointB[3];

			buffer[0] = pointA[0];
			buffer[1] = pointB[0];

			// For each point in B's network
			for (int j=0; j < networks[sourceNetworkID].size(); j++) {
				// Update networkID
				points[networks[sourceNetworkID][j]][3] = targetNetworkID;

				// Add to a network
				networks[targetNetworkID].push_back(networks[sourceNetworkID][j]);
			}

			// Remove B's network
			networks[sourceNetworkID] = {};
		}
	}

	return std::to_string(buffer[0] * buffer[1]);
}