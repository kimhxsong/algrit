#include <vector>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  if (array.size() < 3) {
    return {};
  }
  sort(array.begin(), array.end());
  vector<vector<int>> triplets;
  for (int index = 0; index < array.size() - 2; index++) {
    int left = index + 1;
    int right = array.size() - 1;
    while (left < right) {
      int potentialSum = array[index] + array[left] + array[right];
      if (potentialSum == targetSum) {
        vector<int> triplet{array[index], array[left], array[right]};
        triplets.push_back(triplet);
        left++;
        right--;
      }
      else if (potentialSum < targetSum) {
        left++;
      } else {
        right--;
      }
    }
  }
  return triplets;
}
