// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #Sorting

#include <algorithm>
#include <vector>

using namespace std;

#ifdef 1

// Sol-1.1
// Best: T=O(n) | S=O(1)
// Average: T=O(n^2) | S=O(1)
// Worst: T=O(n^2) | S=O(1)
vector<int> bubbleSort(vector<int> array) {
  if (array.empty()) {
    return {};
  }
  
  bool bIsSorted = false;
  int counter = 0;
  while (!bIsSorted) {
    bIsSorted = true;
    for (int idx = 0; idx < array.size() - 1 - counter; idx++) {
      if (array[idx] > array[idx + 1]) {
        swap(array[idx], array[idx + 1]);
        bIsSorted = false;
      }
    }
    counter++;
  }
  return array;
}

#else

// Sol-1.0
// Best: T=O(n) | S=O(1)
// Average: T=O(n^2) | S=O(1)
// Worst: T=O(n^2) | S=O(1)
vector<int> bubbleSort(vector<int> array) {
  for (int end = array.size() - 1; end > 0; end--) {
    for (int idx = 0; idx < end; idx++) {
      if (array[idx] > array[idx + 1]) {
        swap(array[idx], array[idx + 1]);
      }
    }
  }
  return array;
}

#endif
