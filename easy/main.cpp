#include "solved.h"

#include <algorithm>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

#include <gtest/gtest.h>

TEST(TEST_006, NORMAL) {
  vector<int> input = {5, 7, 1, 1, 2, 3, 22};
  int expected = 20;
  auto actual = nonConstructibleChange(input);
  EXPECT_EQ(expected, actual);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
