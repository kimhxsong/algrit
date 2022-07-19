// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #Sorting

#include <algorithm>
#include <vector>

using namespace std;

// Sol-1.0
// Best: T=O(n^2) | S=O(1)
// Average: T=O(n^2) | S=O(1)
// Worst: T=O(n^2) | S=O(1)
vector<int> selectionSort(vector<int> array) {
  if (array.empty()) {
    return {};
  }

  for (int i = 0; i < static_cast<int>(array.size()) - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < static_cast<int>(array.size()); j++) {
      if (array[minIndex] > array[j]) {
        minIndex = j;
      }
    }
    swap(array[i], array[minIndex]);
  }

  return array;
}
