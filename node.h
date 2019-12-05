// Philipp Moura Srivastava
// 05 12 2019
// Filename: node.h
// Description: This file prototypes the node class

#ifndef _Node_h
#define _Node_h

#include <iostream>


using namespace std;

template <class T>

class Node
{
public:

  Node<T>* getParent();

  int getRank();

  void increaseRank();

  T getItem();

  void setRank(int item);

  void setParent(Node<T>* parent);

  void setItem(T item);

private:
  Node<T>* parent;
  int rank;
  T item;
};

#include "node.cc"

#endif
