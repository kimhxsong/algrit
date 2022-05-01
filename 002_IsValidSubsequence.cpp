// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #Array
#include "solved.h"

#include <vector>

using std::vector;

#ifdef BEST

// Sol-2 T=O(n), S=O(1), Range-based for loop(since C++11)
bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  size_t seq_idx = 0;
  for (auto value : array) {
    if (sequence[seq_idx] == static_cast<int>(seq_idx)) {
      break;
    }
    if (value == sequence[seq_idx]) {
      seq_idx++;
    }
  }
  return seq_idx == sequence.size();
}

#else

// Sol-1 T=O(n), S=O(1)
bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  size_t arr_idx = 0;
  size_t seq_idx = 0;
  while (arr_idx < array.size() && seq_idx < sequence.size()) {
    if (array[arr_idx] == sequence[seq_idx]) {
      seq_idx++;
    }
    arr_idx++;
  }
  return seq_idx == sequnce.size();
}

#endif  // BEST
