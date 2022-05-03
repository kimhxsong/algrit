// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #Strings
#include "solved.h"

#include <map>
#include <unordered_map>

using namespace std;

#if 1

// Sol-2.0
// T=O(n + m) | S=O(c) - where n is the number of characters, m is the length
// of the document, and c is the number of unique characters in the characters
// string
bool generateDocument(string characters, string document) {
	unordered_map<char, int> countTable;
	
	for (auto currentCharacter : characters) {
		if (countTable.find(currentCharacter) == countTable.end()) {
			countTable[currentCharacter] = 0;
		}
		countTable[currentCharacter]++;
	}

	for (auto currentCharacter : document) {
		if (countTable.find(currentCharacter) == countTable.end() ||
			 	countTable[currentCharacter] == 0) {
			return false;
		}

		countTable[currentCharacter]--;
	}

  return true;
}

#else

// Sol-1.1
// T=O(n + m) | S=O(c) - where n is the number of characters, m is the length
// of the document, and c is the number of unique characters in the characters
// string
bool generateDocument(string characters, string document) {
	unordered_map<char, int> countTable;
	
	for (auto currentCharacter : document) {
		if (countTable.find(currentCharacter) == countTable.end()) {
			countTable[currentCharacter] = 0;
		}
		countTable[currentCharacter]++;
	}
	
	for (auto currentCharacter : characters) {
		if (countTable.find(currentCharacter) != countTable.end()) {
			countTable[currentCharacter]--;
		}
	}

	int remains = 0;
	for (auto it : countTable) {
		if (it.second > 0) {
			return false;
		}
	}

  return true;
}

// Sol-1.0
// T=O(n + m) | S=O(c) - where n is the number of characters, m is the length
// of the document, and c is the number of unique characters in the characters
// string

bool generateDocument(string characters, string document) {
	map<char, int> countTable;
	
	for (size_t i = 0; i < document.size(); i++) {
		char currentCharacter = document[i];
		if (countTable.find(currentCharacter) == countTable.end()) {
			countTable[currentCharacter] = 0;
		}
		countTable[currentCharacter] += 1;
	}
	
	for (size_t i = 0; i < characters.size(); i++) {
		char currentCharacter = characters[i];
		if (countTable.find(currentCharacter) != countTable.end()) {
			countTable[currentCharacter] -= 1;
		}
	}

	int remains = 0;
	for (map<char, int>::iterator it = countTable.begin(); it != countTable.end(); ++it) {
		cout << it->first << ":" << it->second << endl;
		if (it->second > 0) {
			return false;
		}
	}

  return true;
}

#endif
