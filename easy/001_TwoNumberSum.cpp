// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #Array
#include "solved.h"

#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

#ifdef BEST

// Sol-2 T=O(n), S=O(n)
vector<int> twoNumberSum(vector<int> array, int targetSum) {
  unordered_set<int>	nums;
  for (int num : array) {
    int otherNum = targetSum - num;
    if (nums.find(otherNum) != nums.end())
      return vector<int>{otherNum, num};
    nums.insert(num);
  }
  return {};
}

#else

// Sol-1 T=O(n^2), S=O(1)
vector<int> twoNumberSum(vector<int> array, int targetSum) {
  const size_t size = array.size();
  for (size_t i = 0; i < size - 1; ++i) {
    int otherNum = targetSum - array[i];
    for (size_t j = i + 1; j < size; ++j) {
      if (otherNum == array[j]) {
        return vector<int>{array[i], array[j]};
      }
    }
  }
  return {};
}

// Sol-3 T=O(nlonn), S=O(1)
vector<int> twoNumberSum(vector<int> array, int targetSum) {
  const size_t size = array.size();
  for (size_t i = 0; i < size; ++i) {
    size_t otherNum = targetSum - array[i];
    for (size_t j = i + 1; j < size; ++j) {
      if (array[j] == otherNum) {
        return vector<int>{array[i], array[j]};
      }
    }
  }
  return {};
}

#endif  // BEST
