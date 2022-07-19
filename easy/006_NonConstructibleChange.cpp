// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #Array
#include "solved.h"

#include <cmath>

#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

#ifdef BEST

// Sol-1.1 T=O(nlogn) | S=O(1) - where n is the number of coins
int nonConstructibleChange(vector<int> coins) {
  sort(coins.begin(), coins.end());

  int maximumChange = 0;
  for (int coin : coins) {
    if (coin > maximumChange + 1)
      break;

    maximumChange += coin;
  }  // Range-based for loop (since C++11)

  return maximumChange + 1;
}

#else

using std::pow;

// Sol-1.0 T=O(nlogn) | S=O(1) - where n is the number of coins
int nonConstructibleChange(vector<int> coins) {
  sort(coins.begin(), coins.end());

  int sumOfCoins = 0;
  for (size_t i = 0; i < coins.size(); i++) {
    if (coins[i] > sumOfCoins + 1)
      break;

    sumOfCoins += coins[i];
  }

  return sumOfCoins + 1;
}

// Sol-X T=O(2^n), S=O(2^n) - where n is the number of coins
// Worst Answer... Approaching too complicated.
// Another solution will be added tomorrow (May 2, 2022)
static void createConstructibleChanges(const vector<int>& coins,
                                       vector<int>& changes) {
  int num_of_cases = pow(2, coins.size());

  for (int i = 0; i < num_of_cases; i++) {
    int change = 0;
    for (int j = coins.size() - 1, case_num = i; j >= 0; j--) {
      change += (case_num % 2) * coins[j];
      case_num /= 2;
    }
    changes.push_back(change);
  }

  sort(changes.begin(), changes.end());
}

int nonConstructibleChange(vector<int> coins) {
  vector<int> changes;
  createConstructibleChanges(coins, changes);
  int prev_change = 0;
  for (size_t i = 0; i < changes.size(); i++) {
    if ((changes[i] - prev_change) > 1)
      break;
    prev_change = changes[i];
  }
  return prev_change + 1;
}

#endif  // BEST
