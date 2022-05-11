// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #BinaryTrees

#include "solved.h"

#include <vector>

using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

// Sol-1.0 Time=O(n) | Space=O(n) - where n is the number of nodes
void branchSumsHelper(BinaryTree *node, vector<int>& sums, int sum = 0);

vector<int> branchSums(BinaryTree *root) {
  if (root == nullptr)
    return {};

  vector<int> sums{};
  branchSumsHelper(root, sums);
  return sums;
}

void branchSumsHelper(BinaryTree *node, vector<int>& sums, int sum) {
  if (!node->left && !node->right)
    sums.push_back(sum + node->value);

  if (node->left)
    branchSumsHelper(node->left, sums, sum + node->value);
  if (node->right)
    branchSumsHelper(node->right, sums, sum + node->value);
}
