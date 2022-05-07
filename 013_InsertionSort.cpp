// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #Sorting

#include <algorithm>
#include <vector>

using namespace std;

// Sol-1.0
// Best: T=O(n) | S=O(1)
// Average: T=O(n^2) | S=O(1)
// Worst: T=O(n^2) | S=O(1)
vector<int> insertionSort(vector<int> array) {
  if (array.empty()) {
    return {};
  }

  for (int i = 1; i < static_cast<int>(array.size()); i++) {
    int j = i;
    while (j > 0 && array[j] < array[j - 1]) {
      swap(array[j], array[j - 1]);
      j--;
    }
  }

  return array;
}
