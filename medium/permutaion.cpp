#include <vector>
#include <set>
using namespace std;

void permutationsHelper(vector<int> permutation, vector<vector<int>>& permutations, set<int> arrayset) {

  arrayset.erase(permutation.back());
  if (arrayset.empty())
  {
    permutations.push_back(permutation);
    return;
  }

  vector<int> nextPermutation(permutation);
  for (auto it = arrayset.begin(); it != arrayset.end(); it++)
  {
    nextPermutation.push_back(*it);
    permutationsHelper(nextPermutation, permutations, arrayset);
    nextPermutation.pop_back();
  }
}

vector<vector<int>> getPermutations(vector<int> array) {
  if (array.empty()) return {};

  set<int> arrayset(array.begin(), array.end());
  vector<vector<int>> permutations;
  vector<int> permutation;

  for (auto it = arrayset.begin(); it != arrayset.end(); it++)
  {
    permutation.push_back(*it);
    permutationsHelper(permutation, permutations, arrayset);
    permutation.pop_back();
  }

  return permutations;
}
