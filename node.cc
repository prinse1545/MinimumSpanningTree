template <class T>

Node<T>* Node<T>::getParent() {
  return parent;
}

template <class T>

int Node<T>::getRank() {
  return rank;
}

template <class T>

void Node<T>::increaseRank() {
  rank++;
}

template <class T>

T Node<T>::getItem() {
  return item;
}

template <class T>

void Node<T>::setRank(int item) {
  rank = item;
}

template <class T>

void Node<T>::setParent(Node<T>* parent) {
  parent = parent;
}

template <class T>

void Node<T>::setItem(T item) {
  item = item;
}
