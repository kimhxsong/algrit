// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #GreedyAlgorithms

#include <algorithm>
#include <vector>

using namespace std;

// Sol-1.0 Time=O(nlogn) | Space=O(1) - where n is the number of queries
int minimumWaitingTime(vector<int> queries) {
  sort(queries.begin(), queries.end());

  int currentWaiting = queries[0];
  int totalWaiting = 0;
  for (size_t i = 1; i < queries.size(); i++) {
    totalWaiting += currentWaiting;
    currentWaiting += queries[i];
  }

  return totalWaiting;
}

