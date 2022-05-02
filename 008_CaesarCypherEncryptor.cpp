// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #Strings

#include <string>
#include <vector>

using std::string;
using std::vector;

#if 1

// Sol-1 T=O(n) | S=O(n) - where n is the the number of str.length
inline static char getNewLetter(char offset, int key) {
  return 'a' + (offset + key) % 26;
}

string caesarCypherEncryptor(string str, int key) {
  string encrypted_str(str);
  
  for (size_t i = 0; i < encrypted_str.size(); i++) {
    encrypted_str[i] = getNewLetter(encrypted_str[i] - 'a', key);
  }

  return encrypted_str;
}

#else

// Sol-2 T=O(n) | S=O(n) - where n is the the number of str.length
inline static char getNewLetter(char offset, int key) {
  return 'a' + (offset + key) % 26;
}

string caesarCypherEncryptor(string str, int key) {
  vector<char> newLetters;

  for (size_t i = 0; i < str.length(); i++) {
    newLetters.push_back(getNewLetter(str[i] - 'a', key));
  }

  return string(newLetters.begin(), newLetters.end());
}

#endif
