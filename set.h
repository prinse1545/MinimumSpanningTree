// Philipp & Austin
// 13.11.2019
// Filename: set.h
// Description: This file implements a disjoint set class for use with
// Kruskal's algorithm

#ifndef _SET_H
#define _SET_H

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <stack>
#include <string>
#include <utility>
#include <queue>
#include <sstream>

using namespace std;

// Set struct
// Usage: representation of sets inside forest
template <typename T>
struct Set
{
  int rank;
  T rep;
  Set<T>* next;
};

// Forest class
template <typename T>
class Forest
{
public:
  Forest();           // constructor

  void makeSet(T x);  // makeSet - makes new singleton set

  Set<T> findSet(T x);  // findSet - finds set that contains x

  void Union(T x, T y); // Union - unions two sets together


private:
  map<T, Set<T>> sets;  // keeps track of all existing sets
  map<T, T> parents;    // keeps track of each set item's parent for all sets
  T findSetRecur(T x);  // findSetRecur - recursive helper function for findSet
  void Link(Set<T> x, Set<T> y); // Link - helper function for union
};

// default constructor -- nothing needs to be done, maps initialize themselves
template <typename T>
Forest<T>::Forest()
{

}

// makeSet
// Preconditions: x is of type T
// Postcondition: a new singleton set with rep = x
template <typename T>
void Forest<T>::makeSet(T x)
{
  Set<T> newSet;
  newSet.rank = 0;  // singleton set
  newSet.rep = x;
  newSet.next = NULL;
  parents[x] = x;   // own parent since singleton set
  sets[newSet.rep] = newSet;  // keep track of newly created set
}

// findSet
// Preconditions: x is in a set already
// If x is in a set, the set containing it will be returned
// otherwise 0/NULL will be returned
template <typename T>
Set<T> Forest<T>::findSet(T x)
{
  // if x is not its own parent -- rep hasn't been found yet
  if (x != parents[x])
  {
    parents[x] = findSetRecur(parents[x]);  // find rep recursively
  }
  return sets[parents[x]];  // return set containing rep
}

// findSetRecur
// identical to findSet except this returns the rep itself rather than
// the set containing it
template <typename T>
T Forest<T>::findSetRecur(T x)
{
  if (x != parents[x])
  {
    parents[x] = findSetRecur(parents[x]);
  }
  return parents[x];
}

// Union
// Preconditions: x and y must be items in a set
// Postcondition: a unioned set containing both x and y's sets
template <typename T>
void Forest<T>::Union(T x, T y)
{
  // find parents/reps and link those together
  Link(findSet(x), findSet(y));
}

// Link
// Does the "unioning" step for Union
// Preconditions: x and y must be sets containing x and y from Union
// Postcondition: a linked set containing both sets
template <typename T>
void Forest<T>::Link(Set<T> x, Set<T> y)
{
  if (x.rank > y.rank)  // if x has more items
  {
    Set<T>* yptr = &y;
    Set<T>* original = yptr;  // for appending
    while (yptr != NULL)
    {
      // make everything in y's set parented to x's rep
      parents[yptr->rep] = parents[x.rep];
      yptr = yptr->next;
    }
    Set<T>* xptr1 = &x;
    while (xptr1->next != NULL)
    {
      // append the set y to the end of set x, similar to linked list append
      xptr1 = xptr1->next;
    }
    xptr1->next = original;
    sets.erase(y.rep);
  }
  else  // if y has equal to or more than x items
  {
    // same thing as the first case, except opposite
    Set<T>* xptr = &x;
    Set<T>* original2 = xptr;
    while (xptr != NULL)
    {
      parents[xptr->rep] = parents[y.rep];
      xptr = xptr->next;
    }
    Set<T>* yptr1 = &y;
    while (yptr1->next != NULL)
    {
      yptr1 = yptr1->next;
    }
    yptr1->next = original2;
    sets.erase(x.rep);
  }
  // if ranks or equal y's must increment by 1 to account for new item
  if (x.rank == y.rank)
    y.rank = y.rank + 1;
}

#endif
