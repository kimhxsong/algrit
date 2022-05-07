#ifndef SOLVED_H_
#define SOLVED_H_

#include <string>
#include <vector>

using std::string;
using std::vector;


# define BEST

// 0507
vector<int> selectionSort(vector<int> array);

// 0507
vector<int> insertionSort(vector<int> array);

// 0507
vector<int> bubbleSort(vector<int> array);

// 0507
int firstNonRepeatingCharacter(string string);

// 0503
bool generateDocument(string characters, string document);

// 0503
string runLengthEncoding(string str);

// 0502
string caesarCypherEncryptor(string str, int key);

// 0502
class LinkedList;
LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList);

// 0501 0502
int nonConstructibleChange(vector<int> coins);

// 0501 0502
string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results);
// Similar Question 1561. Maximum Number of Coins You Can Get
// https://leetcode.com/problems/maximum-number-of-coins-you-can-get/

// 0430
vector<int> sortedSquaredArray(vector<int> array);

// 0430
bool isPalindrome(string str);

// 0429
bool isValidSubsequence(vector<int> array, vector<int> sequence);

// 0426, 0429
vector<int> twoNumberSum(vector<int> array, int targetSum);

#endif  // SOLVED_H_
