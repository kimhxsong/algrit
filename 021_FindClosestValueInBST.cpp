// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #BinarySearchTrees

#include <cmath>

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

// Sol-1.0
// Average: Time=O(log(n)) | Space=O(n)
// Worst: O(n) time | Space=O(n)
static void findClosestValueHelper(const BST *node,
                                   const int target,
                                   int& closestVal,
                                   int& closestDist) {
  if (node == nullptr) { return; }

  int currentVal = node->value;
  int currentDist = abs(currentVal - target);
  if (currentDist < closestDist) {
    closestVal = currentVal;
    closestDist = currentDist;
  }

  findClosestValueHelper(node->left, target, closestVal, closestDist);
  findClosestValueHelper(node->right, target, closestVal, closestDist);
}
  
int findClosestValueInBst(BST *tree, int target) {
  int closestVal = tree->value;
  int closestDist = abs(tree->value - target);

  findClosestValueHelper(tree, target, closestVal, closestDist);
  return closestVal;
}

// TODO: Add Sol-2