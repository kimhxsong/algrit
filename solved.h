#ifndef SOLVED_H_
#define SOLVED_H_

#include <string>
#include <vector>

using std::string;
using std::vector;


# define BEST

// 0502
string caesarCypherEncryptor(string str, int key);

// 0502
class LinkedList;
LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList);

// 0501
int nonConstructibleChange(vector<int> coins);

// 0501
string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results);

// 0430
vector<int> sortedSquaredArray(vector<int> array);

// 0430
bool isPalindrome(string str);

// 0429
bool isValidSubsequence(vector<int> array, vector<int> sequence);

// 0426, 0429
vector<int> twoNumberSum(vector<int> array, int targetSum);

#endif  // SOLVED_H_
