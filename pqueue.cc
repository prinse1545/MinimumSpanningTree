/*
  Philipp Moura Srivastava & Allistair Suh
  Filename: pqueue.cc
  Description: This file implements the MinPriorityQueue class
  30.09.2019
*/


template <typename T>
MinPriorityQueue<T>::MinPriorityQueue(const MinPriorityQueue<T> &pq){
  *this = pq;
}

template <typename T>
T* MinPriorityQueue<T>::minimum() const {
  if(size < 1)
    throw new EmptyQueueException;

  return arr[0];
}


template <typename T>
T* MinPriorityQueue<T>::extractMin() {
  if(size < 1)
    throw new EmptyQueueException;

  T* min = arr[0];
  arr[0] = arr[size - 1];
  heapify(0);
  size--;
  return min;
}

template <typename T>
void MinPriorityQueue<T>::decreaseKey(int index, T* key) {
  if(*key > *arr[index])
    throw new KeyException;

  arr[index] = key;
  while(index >= 0 && *arr[parent(index)] > *arr[index]) {
    swap(index, parent(index));
    index = parent(index);
  }

}

template <typename T>
void MinPriorityQueue<T>::insert(T* key) {

  if(size == capacity) expandCapacity();
  arr[size] = key;
  decreaseKey(size,key);
  size++;
}

template <typename T>
bool MinPriorityQueue<T>::empty() const {
  return size == 0;
}

template <typename T>
int MinPriorityQueue<T>::length() const {
  return size;
}

template <typename T>
string MinPriorityQueue<T>::toString() const {
  //this is toString for HuffNode type
  string str = MinHeap<T>::toString();
}

template <typename T>
int MinPriorityQueue<T>::index(T* item) const {

  for(int i = 0; i < size; i++) {
    if(*arr[i] == *item) return i;
  }

  return NULL;
}

template <typename T>
T* MinPriorityQueue<T>::operator[](int index) {
  return arr[index];
}
