

template <class T>

Disjoint<T>::Disjoint(T item) {

  Node<T>* to_add = new Node<T>;

  to_add->setParent(to_add);
  to_add->setItem(item);
  to_add->setRank(0);

  container.insert({item, to_add});
}

template <class T>

void Disjoint<T>::makeSet(T item) {

  Node<T>* to_add = new Node<T>;

  to_add->setParent(to_add);
  to_add->setItem(item);
  to_add->setRank(0);

  container.insert({item, to_add});
}

template <class T>

T Disjoint<T>::findSet(T item) {
  Node<T>* ret = findSetHelper(item);

  return ret->getItem();
}

template <class T>

void Disjoint<T>::union(T x, T y) {

  x = findSet(x);
  y = findSet(y);

  if(container[x]->getRank() > container[y]->getRank()) {
    container[y]->getParent() = container[x];
  }
  else {
    container[x]->getParent() = container[y]

    if(container[x]->getRank() == container[y]->getRank()) {
      container[y]->increaseRank();
    }
  }

}

template <class T>

Node<T>* Disjoint<T>::findSetHelper(T item) {

  Node<T>* curr = container[item];

  while(curr->getParent() != curr) {
    curr = curr->getParent();
  }

  return curr;
}
