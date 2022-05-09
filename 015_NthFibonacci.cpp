// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #Recursion

#include "solved.h"

#if 1

// Sol-2 T=O(2^n) | S=O(n)
int getNthFib(int n) {
  if (n == 2) {
    return 1;
  } else if (n == 1) {
    return 0;
  } else {
    return getNthFib(n - 1) + getNthFib(n - 2);
  }
}

#else

// Sol-1 T=O(2^n) | S=O(n)
static int getFibRecursive(int current, int prev, int n) {
  if (n == 0) {
    return current;
  }

  return getFibRecursive(current + prev, current, n - 1);
}

int getNthFib(int n) {
  if (n == 0) {
    return 0;
  }

  return getFibRecursive(0, 1, n - 1);
}

#endif
