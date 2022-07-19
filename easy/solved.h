#ifndef SOLVED_H_
#define SOLVED_H_

#include <string>
#include <vector>
#include <any>

using namespace std;


# define BEST

// 0514
int tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds,
                  bool fastest);

// 0514
bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights);

// 0513
int minimumWaitingTime(vector<int> queries);

// 0512
#include "022_DepthFirstSearch.hpp"  // class Node {...};

// 0512
class BST;
int findClosestValueInBst(BST *tree, int target);

// 0511
class BinaryTree;
int nodeDepths(BinaryTree *root);

// 0511
class BinaryTree;
vector<int> branchSums(BinaryTree *root);

// 0510
vector<int> findThreeLargestNumbers(vector<int> array);

// 0510
int binarySearch(vector<int> array, int target);

// 0509
int productSum(vector<any> array, int depth);

// 0509
int getNthFib(int n);

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
