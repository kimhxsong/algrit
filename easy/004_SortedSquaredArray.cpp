// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #Array
#include "solved.h"

#include <algorithm>
#include <cmath>
#include <vector>

using std::vector;
using std::sort;
using std::abs;

#ifdef BEST

// Sol-2 T=O(n), S=O(n)
vector<int> sortedSquaredArray(vector<int> array) {
  vector<int>	sorted_squared_arr(array.size(), 0);
  int left_idx = 0;
  int right_idx = array.size() - 1;

  for (int i = array.size() - 1; i >=0; i--) {
    int left_value = array[left_idx];
    int right_value = array[right_idx];

    if (abs(left_value) > abs(right_value)) {
      sorted_squared_arr[i] = left_value * left_value;
      left_idx++;
    } else {
      sorted_squared_arr[i] = right_value * right_value;
      right_idx--;
    }
  }

  return sorted_squared_arr;
}

#else

// Sol-1 T=O(nlogn), S=O(n)
vector<int> sortedSquaredArray(vector<int> array) {
  vector<int>	sorted_squared_arr(array.size(), 0);

  for (int i = 0; i < array.size(); i++) {
    int value = array[i];
    sorted_squared_arr[i] = value * value;
  }

  sort(sorted_squared_arr.begin(), sorted_squared_arr.end());
  return sorted_squared_arr;
}

#endif  // BEST
