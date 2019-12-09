


template <typename T>
MinHeap<T>::MinHeap() {

  this->capacity = INITIAL_CAPACITY;
  this->size = 0;
  this->arr = new T*[this->capacity];
}

template <typename T>
MinHeap<T>::MinHeap(T initA[], int n) {

  this->capacity = INITIAL_CAPACITY;
  this->size = 0;
  this->arr = new T*[this->capacity];

  while(n > this->capacity) {
    expandCapacity();
  }

  for(int i = 0; i < n; i++) {
    this->arr[i] = initA[i];
    this->size++;
  }


  buildMinHeap();

}

template <typename T>
MinHeap<T>::MinHeap(const MinHeap<T> &heap) {
  deepCopy(heap);
}

template <typename T>
MinHeap<T>::~MinHeap() {
  delete[] this->arr;
}

template <typename T>
void MinHeap<T>::heapSort(T* sorted[]) {

  int heapLength = this->size;

  for(int i = heapLength - 1; i >= 0; i--) {
    swap(0, i);
    this->size--;
    heapify(0);
  }

  this->size = heapLength;

  for(int i = 0; i < heapLength; i++) {
    sorted[i] = this->arr[i];
  }
}


template <typename T>
string MinHeap<T>::toString() const {
  //this is toString for general type
  string str = "[";
  for (int i = 0; i < size; i++){
    cout << (*arr)[i] << endl;
    str += to_string(*(*arr)[i]);
    if (i != size - 1)
      str += ", ";
  }
  str += "]";
  return str;
}

template <typename T>
MinHeap<T> & MinHeap<T>::operator=(const MinHeap<T> &heap) {
  delete[] this->arr;
  deepCopy(heap);

  return *this;
}

template <typename T>
void MinHeap<T>::buildMinHeap() {

  int marker = this->size / 2;

  for(int i = marker; i >= 0; i--) {
    heapify(i);
  }
}

template <typename T>
void MinHeap<T>::heapify(int index) {
  int left = leftChild(index);
  int right = rightChild(index);

  int smallest;
  if(left < this->size && *(this->arr[left]) <= *(this->arr[index])) {
    smallest = left;
  }
  else {
    smallest = index;
  }

  if(right < this->size && *(this->arr[right]) <= *(this->arr[smallest])) {
    smallest = right;
  }

  if (smallest != index) {
    swap(index, smallest);
    heapify(smallest);
  }
}

template <typename T>
void MinHeap<T>::expandCapacity() {

  T **oldArray = this->arr;
  this->capacity *= 2;
  this->arr = new T*[this->capacity];
  for(int i = 0; i < this->size; i++) {
    this->arr[i] = oldArray[i];
  }
  delete[] oldArray;
}

template <typename T>
void MinHeap<T>::deepCopy(const MinHeap<T>& heap) {

  this->size = heap.size;
  this->capacity = heap.capacity;
  this->arr = new T*[this->capacity];

  for(int i = 0; i < heap.size; i++) {
    this->arr[i] = heap.arr[i];
  }

  buildMinHeap();

}
