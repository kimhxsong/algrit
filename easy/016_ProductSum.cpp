// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #Recursion

#include "solved.h"

#include <any>
#include <typeinfo>
#include <vector>

using namespace std;

// Sol-1 T=O(n) | S=O(d) - where n is the total number of elements
// in the array, including sub-elements, and d is the greatest depth
// of "special" arrays in the array
int productSum(vector<any> array, int depth = 1) {
  int sum = 0;
  for (auto elem : array) {
    if (elem.type() == typeid(vector<any>)) {
      sum += productSum(any_cast<vector<any>>(elem), depth + 1);
    } else {
      sum += any_cast<int>(elem);
    }
  }
  return depth * sum;
}
