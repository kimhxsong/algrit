// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #Searching

#include "solved.h"

#include <vector>

using namespace std;

#if 1

// Sol-1.1 Time=O(log(n)) | Space=O(1)
static int binarySearchHelper(vector<int> array,
                              int target,
                              int left,
                              int right) {
  while (left <= right) {
    int middle = (left + right) / 2;
    int potentialMatch = array[middle];
    if (target == potentialMatch)  {
      return middle;
    } else if (target < potentialMatch) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }
  return -1;
}

int binarySearch(vector<int> array, int target) {
  return binarySearchHelper(array, target, 0, array.size() - 1);
}

#else 

// Sol-2 Time=O(n) | Space=O(log(n))
static int binarySearchHelper(const vector<int>& array, int target, int left, int right) {
  if (left > right) {
    return -1;
  }

  int middle = (left + right) / 2;
  int potentialMatch = array[middle];
  if (target == potentialMatch) {
    return middle;
  } else if (target < potentialMatch) {
    return binarySearchHelper(array, target, left, middle -1);
  } else {
    return binarySearchHelper(array, target, middle + 1, right);
  }
}

int binarySearch(vector<int> array, int target) {
  return binarySearchHelper(array, target, 0, array.size() - 1);
}

// Sol-1.0 Time=O(log(n)) | Space=O(1)
int binarySearch(vector<int> array, int target) {
  int left = 0;
  int right = array.size() - 1;

  while (left <= right) {
    int index = (left + right) / 2;
    int value = array[index];

    if (value == target)
      return index;

    if (value > target) {
      right = index;
    } else if (value < target) {
      left = index + 1;
    }
  }

  return -1;
}

#endif 
