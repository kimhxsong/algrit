// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #Strings
#include "solved.h"

#include <string>

using std::string;

#ifdef BEST

// Sol-1.1
bool isPalindrome(string str) {
  int	left_idx = str.size();
  int	right_idx = str.size() - 1;
  while (left_idx < right_idx) {
    if (str[left_idx] != str[right_idx]) {
      return false;
    }
    left_idx++;
    right_idx++;
  }
  return true;
}

#else

// Sol-1 T=O(n), S=O(1)
bool isPalindrome(string str) {
  string::iterator it = str.begin();
  string::reverse_iterator rit = str.rbegin();
  while (it < rit) {
    if (*it != *rit) {
      return false;
    }
    it++;
    rit++;
  }
  return true;
}

// Sol-2 T=O(n), S=O(n)
bool isPalindrome(string str) {
  vector<char> reverse_chars;
  for (int i = str.length() - 1; i >= 0; i--) {
    reverse_chars.push_back(str[i]);
  }
  return str == string(reverse_chars.begin(), reverse_chars.end());
}

// Sol-3 T=O(n), S=O(n)
static bool helper_recursive(string str, int i) {
  int j = str.length() - 1 - i;
  return i >= j ? true : str[i] == str[j] && helper_recursive(str, i + 1);
}

bool isPalindrome(string str) {
  return helper_recursive(str, 0);
}

#endif  // BEST
