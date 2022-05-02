// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #LinkedLists
#include "solved.h"

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

// T=O(n) | S=O(1) - where n is the number of nodes in the Linked List 
LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList) {
  LinkedList *current_node = linkedList;

  while (current_node != nullptr) {
    LinkedList *distinct_node = current_node->next;

    while (distinct_node != nullptr &&
           distinct_node->value == current_node->value) {
      distinct_node = distinct_node->next;
    }

    current_node->next = distinct_node;
    current_node = current_node->next;
  }

  return linkedList;
}
