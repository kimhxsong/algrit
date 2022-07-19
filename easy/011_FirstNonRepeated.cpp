// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #Strings

#include <string>
#include <unordered_map>

using namespace std;

// Sol-1 T=O(n) | S=O(1) - where n is the length of the input string
// Because the input string only contains lowercase English letters,
// there is a constant space.
int firstNonRepeatingCharacter(string string) {
  unordered_map<char, int> table;

  for (auto ch : string) {
    if (table.find(ch) == table.end()) {
      table[ch] = 0;
    }
    table[ch]++;
  }

  for (size_t idx = 0; idx < string.size(); idx++)  {
    char ch = string[idx];
    if (table[ch] == 1) {
      return idx;
    }
  }
  
  return -1;
}
