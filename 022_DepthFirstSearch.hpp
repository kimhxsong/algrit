// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #Graphs

#include <string>
#include <vector>

using namespace std;

// Do not edit the class below except
// for the depthFirstSearch method.
// Feel free to add new properties
// and methods to the class.

class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  vector<string> depthFirstSearch(vector<string> *array);

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};

// Sol-1 Time=O(v + e) time | Space=O(v) - v is the number of vertices and
// is the number of edges
vector<string> Node::depthFirstSearch(vector<string> *array) {
   array->push_back(this->name);
   for (size_t i = 0; i < this->children.size(); i++) {
     children[i]->depthFirstSearch(array);
   }

   return *array;
}



