// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #BinaryTrees

#include "solved.h"

using namespace std;

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

using namespace std;

// Average case: when the tree is balanced
// Sol-1.0 Time=O(n) | Space=O(h) - where n is the number of nodes in binary
// trees and h is the height of the binary tree.
static void nodeDepthHelper(BinaryTree *node, int& sum, int currentDepth) {
  if (node == nullptr) { return; }
  
  sum += currentDepth++;
  nodeDepthHelper(node->left, sum, currentDepth);
  nodeDepthHelper(node->right, sum, currentDepth);
}

int nodeDepths(BinaryTree *root) {
  if (root == nullptr)
    return -1;
  int sum = 0;
  nodeDepthHelper(root, sum, 0);
  return sum;
}
