// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #Array

#include <vector>

using namespace std;

// Sol-1
vector<int> twoNumberSum(vector<int> array, int targetSum) {
	const int size = array.size();
	for (int i = 0; i < size - 1; ++i) {
		int otherNum = targetSum - array[i];
		for (size_t j = i + 1; j < size; ++j) {
			if (otherNum == array[j]) {
				return vector<int>{array[i], array[j]};
			}
		}
	}
	return {};
}

