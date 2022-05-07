// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #Strings
#include "solved.h"

#include <vector>

using namespace std;

// Sol-1.0 T=O(n) | S=O(n) - where n is the number of str.length()
static int getSequenceLength(const string& str, int* currentIndex) {
	int index = *currentIndex;
	int len = 0;
	char ch = str[index];

	while (ch == str[index] && len < 9) {
		index++;
		len++;
	}
	
	*currentIndex = index;

	return len;
}

string runLengthEncoding(string str) {
	vector<char> code;
	int	currentIndex = 0;

	while (currentIndex < static_cast<int>(str.size())) {
		char alpha = str[currentIndex];
		char num = '0' + getSequenceLength(str, &currentIndex);

		code.push_back(num);
		code.push_back(alpha);
	}

  return string(code.begin(), code.end());
}

