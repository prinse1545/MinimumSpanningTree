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

  Node();

  Node(int distance, T predecessor, T vertex);

  int getDistance();

  T getPredecessor();

  T getVertex();

  void setPredecessor(T pred);

  void setDistance(int dist);

  bool operator<=(Node<T> &n);

  bool operator>=(Node<T> &n);

  bool operator<(Node<T> &n);

  bool operator>(Node<T> &n);

  bool operator==(Node<T> &n);



private:
  int distance;
  T predecessor;
  T vertex;
};

#include "node.cc"

#endif
