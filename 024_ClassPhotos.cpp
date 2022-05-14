// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #GreedyAlgorithms

#include <algorithm>
#include <vector>

using namespace std;

// Time=O(nlog(n)) | Space=O(1) - where n is the number of students
bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) {
  sort(redShirtHeights.begin(), redShirtHeights.end());
  sort(blueShirtHeights.begin(), blueShirtHeights.end());
  
  int numberOfStudents = redShirtHeights.size();
  if (redShirtHeights[0] < blueShirtHeights[0]) {
    for (int i = 0; i < numberOfStudents; i++) {
      if (redShirtHeights[i] >= blueShirtHeights[i])
      return false;
    }
  } else {
    for (int i = 0; i < numberOfStudents; i++) {
      if (blueShirtHeights[i] >= redShirtHeights[i])
      return false;
    }
  }

  return true;
}
