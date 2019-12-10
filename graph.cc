// Philipp & Austin
// 13.11.2019
// Filename: graph.cc
// Description: This file implements a graph as described in graph.h

#include "graph.h"


Graph::Graph(string filename) {

  ifstream f;

  f.open(filename);

  if(f.is_open()) {
    string line;
    getline(f, line);

    int size = int(line[0]) - 48;

    for(int i = 0; i < size; i++) {

      vector<int> edges;

      adjacencyList.insert(pair<int, vector<int> >(i, edges));
    }

    int count = 0;


    while(!f.eof()) {
      getline(f, line);

      vector<int> vec;

      for(int i = 0; i < line.length(); i++) {
        int val = int(line[i]) - 48;
        //Making adjacency list
        if(val > 0) {

          adjacencyList[count].push_back(i);
        }
        //Making matrix
        vec.push_back(val);
      }

      adjacencyMatrix.push_back(vec);

      count ++;
    }
  }

  f.close();


}

Graph::Graph(const Graph &g) {
  adjacencyList = g.adjacencyList;
  adjacencyMatrix = g.adjacencyMatrix;
}

void Graph::dfs() {

  vector<bool> coloring;

  for(int i = 0 ; i < adjacencyList.size(); i++) {
    coloring.push_back(false);
  }

  for(pair<int, vector<int>>p : adjacencyList) {

    if(coloring[p.first] != true) {
      cout << "Starting at: " << p.first << endl;
      dfsHelper(p.first, coloring);
    }

    cout << endl;
  }

}

void Graph::dfsHelper(int node, vector<bool> &coloring) {




  coloring[node] = true;

  stack<int> s;
  s.push(node);



  while(!s.empty()) {
    int u = s.top();
    s.pop();

    for(int i = 0; i < adjacencyList[u].size(); i++) {

      if(coloring[adjacencyList[u][i]] == false) {
        coloring[adjacencyList[u][i]] = true;
        s.push(adjacencyList[u][i]);
      }
    }

    cout << "Visited: " << u << endl;
  }
}

void Graph::topologicalSort()
{
  stringstream ss;
  queue<int> Q;

  map<int, int> inDegrees;

  for (auto const& x : adjacencyList)
  {
    int inDegree = 0;
    for (auto const& y : adjacencyList)
    {
      for (int i = 0; i < y.second.size(); i++)
      {
        if (y.second[i] == x.first)
        {
          inDegree++;
        }
      }
    }

    inDegrees[x.first] = inDegree;

    if (inDegree == 0)
    {
      Q.push(x.first);
    }
  }

  if (Q.size() == 0) throw CycleError();

  while (Q.size() != 0)
  {
    bool outputHappened = false;
    int u = Q.front();
    Q.pop();
    ss << u << " ";
    outputHappened = true;

    for (int i = 0; i < adjacencyList[u].size(); i++)
    {
      inDegrees[adjacencyList[u][i]] = inDegrees[adjacencyList[u][i]] - 1;

      if (inDegrees[adjacencyList[u][i]] == 0)
      {
        Q.push(adjacencyList[u][i]);
      }
    }
  }

  cout << ss.str() << endl;
}

string Graph::Kruskals() {

  if(adjacencyList.size() == 0 || adjacencyMatrix.size() == 0) throw new EmptyError;

  stringstream ss;
  Disjoint<int> A;

  for(auto const &vertex : adjacencyList) {

    A.makeSet(vertex.first);
  }

  vector<Edge> sorted = kruskalHelper();

  for(Edge edge : sorted) {
    int u = edge.u;
    int v = edge.v;

    if(A.findSet(u) != A.findSet(v)) {
      A.makeUnion(u, v);
      ss << "(" << u << ", " << v << "), ";
    }
  }

  return ss.str();




}

string Graph::Prims(int source) {

  if(adjacencyList.size() == 0 || adjacencyMatrix.size() == 0) throw new EmptyError;

  vector<Edge> edges;

  MinPriorityQueue<Node<int>> PQ;

  for(auto const &vertex : adjacencyList) {
    Node<int>* n;
    if(vertex.first == source) {
      n = new Node<int>(0, NULL, vertex.first);
    }
    else {
      n = new Node<int>(INT8_MAX, NULL, vertex.first);
    }


    PQ.insert(n);
  }

  while(!PQ.empty()) {
    Node<int>* u = PQ.extractMin();

    int minEdge = NULL;

    for(int i = 0; i < adjacencyList[u->getVertex()].size(); i++) {
      Node<int> n(0, NULL, adjacencyList[u->getVertex()][i]);
      if(PQ.index(&n) != NULL && adjacencyMatrix[u->getVertex()][adjacencyList[u->getVertex()][i]] < PQ[PQ.index(&n)]->getDistance()) {
        Node<int>* v = PQ[PQ.index(&n)];

        v->setPredecessor(u->getVertex());
        v->setDistance(adjacencyMatrix[u->getVertex()][adjacencyList[u->getVertex()][i]]);

      }
    }

  }




}

string Graph::Dijkstras(int source) {

  if(adjacencyList.size() == 0 || adjacencyMatrix.size() == 0) throw new EmptyError;

  MinPriorityQueue<Node<int>> PQ;
  vector<Node<int>> A;

  for(auto const &vertex : adjacencyList) {
    Node<int>* n = new Node<int>;

    if(vertex.first != source) {

      n->setVertex(vertex.first);
      n->setPredecessor(NULL);
      n->setDistance(INT8_MAX);

    }
    else {
      n->setVertex(vertex.first);
      n->setPredecessor(NULL);
      n->setDistance(0);

    }

    PQ.insert(n);
  }





  while(!PQ.empty()) {
    Node<int>* u = PQ.extractMin();

    A.push_back(*u);
    for(int i = 0; i < adjacencyList[u->getVertex()].size(); i++) {

      int newDist = u->getDistance() + adjacencyMatrix[u->getVertex()][adjacencyList[u->getVertex()][i]];
      Node<int> n(0, NULL, adjacencyList[u->getVertex()][i]);
      if (newDist <  PQ[PQ.index(&n)]->getDistance()){

        Node<int>* v = PQ[PQ.index(&n)];
        v->setDistance(newDist);
        v->setPredecessor(u->getVertex());
      }
    }
  }

    stringstream ss;

    for(int i = 0; i < A.size(); i++) {
      ss << "(" << A[i].getVertex() << " : "<<  A[i].getDistance() << ")";
    }


    return ss.str();


}

vector<typename Graph::Edge> Graph::kruskalHelper() {

  vector<Edge> edges;

  for(int i = 0; i < adjacencyMatrix.size(); i++) {

    for(int j = 0; j < adjacencyMatrix[i].size(); j++) {

      if(adjacencyMatrix[i][j] > 0) {
        Edge temp;
        temp.u = i;
        temp.v = j;
        temp.weight = adjacencyMatrix[i][j];

        edges.push_back(temp);
      }
    }
  }

  sortEdges(edges);

  return edges;
}

void Graph::sortEdges(vector<typename Graph::Edge> &edges) {

  int size = edges.size();

  if(size <= 1) return;

  vector<Edge> half;
  vector<Edge> otherHalf;

  for(int i = 0; i < size; i++) {
    if(i < size / 2) {
      half.push_back(edges[i]);
    }
    else {
      otherHalf.push_back(edges[i]);
    }
  }

  sortEdges(half);
  sortEdges(otherHalf);
  edges.clear();
  merge(edges, half, otherHalf);
}

void Graph::merge(vector<typename Graph::Edge> &edges, vector<typename Graph::Edge> &half, vector<typename Graph::Edge> &otherHalf) {

  int halfSize = half.size();
  int otherSize = otherHalf.size();
  int check1 = 0;
  int check2 = 0;

  while(check1 < halfSize && check2 < otherSize) {

    if(half[check1].weight < otherHalf[check2].weight) {
      edges.push_back(half[check1++]);
    }
    else {
      edges.push_back(otherHalf[check2++]);
    }
  }

  while(check1 < halfSize) edges.push_back(half[check1++]);
  while(check2 < otherSize) edges.push_back(otherHalf[check2++]);
}
