// Philipp & Austin
// 6.12.2019
//Filename: test_set.cc
// Description: tests disjoint set class methods with ints and strings

#include "set.h"
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

int main()
{
  // test with ints

  // make forest
  Forest<int> s1;
  // case of running findSet on a set that doesn't contain your item
  Set<int> empty = s1.findSet(35);
  assert(empty.rep == 0); // shouldn't exist so returns 0/NULL
  // add set with rep = 1
  s1.makeSet(1);
  // findSet - should be 1
  Set<int> findVal = s1.findSet(1);
  // make set with rep = 2
  s1.makeSet(2);
  // union the two sets together - ranks are equal so 2 should be the
  // new rep
  s1.Union(1, 2);
  // both of these things should = 2
  Set<int> findVal2 = s1.findSet(2);
  Set<int> findVal3 = s1.findSet(1);
  // one more set to union together
  s1.makeSet(33);

  s1.Union(33, 1);
  // should also = 2
  Set<int> findVal4 = s1.findSet(33);

  assert(findVal.rep == 1);
  assert(findVal2.rep == 2);
  assert(findVal3.rep == 2);
  assert(findVal4.rep == 2);

  // methods all work with ints

  //test with strings

  Forest<string> s2;
  // add set with rep = "a"
  s2.makeSet("a");
  // add another set with rep = "ab"
  s2.makeSet("ab");
  // union - "ab" should be rep
  s2.Union("a","ab");

  assert(s2.findSet("a").rep == "ab");
  assert(s2.findSet("ab").rep == "ab");

  // tests passed

  return 0;
}
