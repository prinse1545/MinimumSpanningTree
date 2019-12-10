/*
  Philipp Moura Srivastava & Allistair Suh
  Filename: pqueue.h
  Description: The header file of the MinPriorityQueue class
  30.09.2019
*/

#ifndef MinPriorityQueue_h
#define MinPriorityQueue_h
#include <iostream>
#include <string>
#include <exception>
#include "MinHeap.h"

using namespace std;

template <class T>
class MinPriorityQueue : public MinHeap<T>{
public:

  // Constructor: default, constructs a MinHeap Inherited from the
  // MinHeap class
  //

  MinPriorityQueue() : MinHeap<T>() {  };

  // Constructor: default, constructs a MinHeap Inherited from the
  // MinHeap class with capacity n
  //

  MinPriorityQueue(int n) : MinHeap<T>() { capacity = n; size = 0;};

  // Constructor: copy, constructs a MinHeap Inherited from the
  // MinHeap class
  //

  MinPriorityQueue(const MinPriorityQueue<T> &pq);

  // Function: minimum, returns the smallest value,
  //
  // Parameter(s):
  //
  //   None
  //
  // Return Value(s):
  //
  //   T* - a pointer to the object

  T* minimum() const;

  // Function: extractMin, deletes the smallest element
  // and returns it
  //
  // Parameter(s):
  //
  //   None
  //
  // Return Value(s):
  //
  //   T* a pointer to the smallest object

  T* extractMin();

  // Function: decreaseKey, used to decrease a priority
  //
  // Parameter(s):
  //
  //   int index - index to decrease
  //   T* key - a new smaller key
  //
  // Return value(s):
  //
  //   None

  void decreaseKey(int index, T* key);

  // Function: insert, insert an element into priority Queue
  //
  // Parameter(s):
  //
  //   T* key - the key
  //
  // Return Value(s):
  //
  //   None

  void insert(T* key);

  // Function: empty, checks if PriorityQueue is empty
  //
  // Parameter(s):
  //
  //   None
  //
  // Return Value(s):
  //
  //   bool, whether or not PriorityQueue is empty

  bool empty() const;

  // Function: length, returns length of PriorityQueue
  //
  // Parameter(s):
  //
  //   none
  //
  // Return Value(s):
  //
  //   int - length of priority queue

  int length() const;

  // Function: toString, converts PriorityQueue into string
  //
  // Parameter(s):
  //
  //   None
  //
  // Return Value(s):
  //
  //   string - a string version of the PriorityQueue

  string toString() const;

  // Operator: <<
  //
  // outstream overloaded operator

  // Function: setT
  //
  // allows manual item designation for testing purpose

  int index(T* item) const;

  T* operator[](int index);

  friend ostream& operator<<(ostream &o, MinPriorityQueue<T> &prQ){
      //this friend function enables osteam operator.
      o << prQ.toString();
      return o;
  }

  // inheriting from MinHeap

  using MinHeap<T>::operator=;
  using MinHeap<T>::toString;
  using MinHeap<T>::arr;
  using MinHeap<T>::size;
  using MinHeap<T>::capacity;
  using MinHeap<T>::parent;
  using MinHeap<T>::swap;
  using MinHeap<T>::heapify;
  using MinHeap<T>::expandCapacity;
  using MinHeap<T>::deepCopy;
};

class FullQueueException : public exception {
public:
  string what(){
    return "The Queue is full";
  }
};
class EmptyQueueException : public exception {
public:
  string what() {
    return "The Queue is empty";
  }
};
class KeyException : public exception {
public:
  string what() {
    return "The key was larger!";
  }
};
#include "pqueue.cc"
#endif
