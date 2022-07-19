// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #GreedyAlgorithms

#include <algorithm>
#include <vector>

using namespace std;

// Sol-1 Time=O(nlog(n)) | Space=O(1) - where n is the number of tandem bicycles
int tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds,
                  bool fastest) {
  sort(redShirtSpeeds.begin(), redShirtSpeeds.end());	
  if (fastest == true) {
    sort(blueShirtSpeeds.rbegin(), blueShirtSpeeds.rend());	
  } else {
    sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());
  }

  int totalTandemSpeed = 0;
  int numberOfPeople = redShirtSpeeds.size();
  for (int i = 0; i < numberOfPeople; i++) {
    int riderA = redShirtSpeeds[i];
    int riderB = blueShirtSpeeds[i];
    totalTandemSpeed += max(riderA, riderB);
  }

  return totalTandemSpeed;
}
