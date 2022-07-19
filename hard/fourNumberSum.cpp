#include <algorithm>
#include <vector>

using namespace std;

// O(n^3) time | O(n^2) space
vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
  if (array.size() < 4) {
    return {};
  }
  sort(array.begin(), array.end());
  vector<vector<int> > quadruplets{};
  for (int indexOne = 0; indexOne < array.size() - 3; indexOne++) {
    for (int indexTwo = indexOne + 1; indexTwo < array.size() - 2; indexTwo++) {
      int left = indexTwo + 1;
      int right = array.size() - 1;
      while (left < right) {
        int potentialSum = array[indexOne] + array[indexTwo] + array[left] + array[right];
        if (potentialSum == targetSum) {
          vector<int> quadruplet{array[indexOne], array[indexTwo], array[left], array[right]};
          quadruplets.push_back(quadruplet);
          left++;
          right--;
        } else if (potentialSum < targetSum) {
          left++;
        } else {
          right--;
        }
      }
    }
  }
  return quadruplets;
}
