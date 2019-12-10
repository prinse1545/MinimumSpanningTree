template <class T>

Node<T>::Node() {  }

template <class T>

Node<T>::Node(int distance, T predecessor, T vertex) {
  distance = distance;
  predecessor = predecessor;
  vertex = vertex;
}

template <class T>

int Node<T>::getDistance() {
  return distance;
}

template <class T>

T Node<T>::getPredecessor() {
  return predecessor;
}

template <class T>

T Node<T>::getVertex() {
  return vertex;
}

template <class T>

void Node<T>::setPredecessor(T pred) {
  predecessor = pred;
}

template <class T>

void Node<T>::setDistance(int dist) {
  distance = dist;
}

template <class T>

void Node<T>::setVertex(T vert) {
  vertex = vert;
}

template <class T>

bool Node<T>::operator<=(Node<T> &n) {
  return distance <= n.getDistance();
}

template <class T>

bool Node<T>::operator>=(Node<T> &n) {
  return distance >= n.getDistance();
}

template <class T>

bool Node<T>::operator<(Node<T> &n) {
  return distance < n.getDistance();
}

template <class T>

bool Node<T>::operator>(Node<T> &n) {
  return distance > n.getDistance();
}

template <class T>

bool Node<T>::operator==(Node<T> &n) {
  return (vertex == n.getVertex());
}
