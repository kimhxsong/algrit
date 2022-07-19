// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #Searching

#include <vector>
#include <climits>

using namespace std;

// Sol-1.1 Time=O(n) | Space=O(1)
void shiftAndUpdate(vector<int>& array, int num, int idx);
static void updateLargestNumbers(vector<int>& numbers, int number);

vector<int> findThreeLargestNumbers(vector<int> array) {
  if (array.size() < 3)
    return {};

  vector<int> numbers{INT_MIN, INT_MIN, INT_MIN};
  for (int number : array) {
    updateLargestNumbers(numbers, number);
  }
  return numbers;
}

void shiftAndUpdate(vector<int>& array, int num, int idx) {
  for (int i = 0; i <= idx; i++) {
    if (i == idx) {
      array[i] = num;
    } else {
      array[i] = array[i + 1];
    }
  }
}

void updateLargestNumbers(vector<int>& numbers, int number) {
  if (numbers[2] < number)	{
    shiftAndUpdate(numbers, number, 2);
  } else if (numbers[1] < number)	{
    shiftAndUpdate(numbers, number, 1);
  } else if (numbers[0] < number)	{
    shiftAndUpdate(numbers, number, 0);
  }
}

