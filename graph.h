// Philipp & Austin
// 13.11.2019
// Filename: graph.h
// Description: This file implements a graph using an adjacency list
// to store the graph and an adjacency matrix to store its weights

#ifndef _Graph_h
#define _Graph_h

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <stack>
#include <string>
#include <utility>
#include <queue>
#include <sstream>
#include "disjoint.h"
#include "pqueue.h"
#include "node.h"

using namespace std;

class Graph {
public:
  struct Edge {
    int u;
    int v;
    int weight;
  };

  Graph(string filename);

  Graph(const Graph &g);

  void dfs();

  void topologicalSort();

  string Kruskals();

  string Prims(int source);

  string Dijkstras(int source);

private:




  map<int, vector<int> > adjacencyList;
  vector<vector<int> > adjacencyMatrix;

  void dfsHelper(int node, vector<bool> &coloring);
  vector<Edge> kruskalHelper();
  void sortEdges(vector<typename Graph::Edge> &edges);
  void merge(vector<typename Graph::Edge> &edges, vector<typename Graph::Edge> &half, vector<typename Graph::Edge> &otherHalf);
};

class CycleError
{
	public:
		std::string message = "CYCLE DETECTED";
};

class EmptyError {
public:
  std::string message = "Graph is Empty!";
};

#endif
