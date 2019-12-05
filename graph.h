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
#include "set.h"

using namespace std;

class Graph {
public:

  Graph(string filename);

  Graph(const Graph &g);

  void dfs();

  void topologicalSort();

  string Kruskal();

private:


  map<int, vector<int> > adjacencyList;
  vector<vector<int> > adjacencyMatrix;

  void dfsHelper(int node, vector<bool> &coloring);
};

class CycleError
{
	public:
		std::string message = "CYCLE DETECTED";
};

#endif
