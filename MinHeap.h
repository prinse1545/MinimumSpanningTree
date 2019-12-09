/*
  Philipp Moura Srivastava
  23.09.2019
  Filename: MinHeap.h
  Description: This file implements the MinHeap ADT as described
  by Dr. Lall
*/

#ifndef MinHeap_h
#define MinHeap_h
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class MinHeap {
public:
/*
   Constructor: default
   Parameter(s):
   None
*/
  MinHeap();

/*
   Constructor: array
   Parameter(s):
     initA[]: an array of values to put into heap
     n: type, int, the length of the array
*/
  MinHeap(T initA[], int n);

/*
   Constructor: copy
   Parameter(s):
     A heap
*/
  MinHeap(const MinHeap<T> &heap);

// Destructor
  ~MinHeap();

/*
  Method: heapSort, sorts the heap
  Parameter(s):
     sorted[]: an array that the sorted values are put in
  Return Value(s):
     None
*/
  void heapSort(T* sorted[]);

/*
  Method: toString, returns a string of the heap
  Parameter(s):
     None
  Return Value(s):
     None
*/
  string toString() const;

// Operator: assignmenet operator for heap
  MinHeap<T> & operator=(const MinHeap<T> &heap);

protected:
  static const int INITIAL_CAPACITY = 10;
  static const int DEFAULT_SIZE = 7;

  T **arr;
  int size;
  int capacity;

  void heapify(int index);
  void buildMinHeap();

  int leftChild(int index) { return 2 * index + 1; }  // return index of left child
  int rightChild(int index) { return 2 * index + 2; } // return index of right child
  int parent(int index) { return (index - 1) / 2; }   // return index of parent
  void swap(int index1, int index2) {
    T* temp = this->arr[index1];
    this->arr[index1] = this->arr[index2];
    this->arr[index2] = temp;
  }
  // swap elements in A

  void deepCopy(const MinHeap<T>& heap);  // copy heap to this heap
  void destroy();                           // deallocate heap
  void expandCapacity();
};

#include "MinHeap.cc"
#endif
