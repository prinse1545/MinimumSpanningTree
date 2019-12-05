
CPPOPTIONS = -c -g -Wall -std=c++0x

all: test_disjoint

//==============================================================================

test_graph: graph.o test_graph.o
	g++ graph.o test_graph.o -o test_graph

test_graph.o: test_graph.cc graph.h graph.cc
	g++ -c test_graph.cc

graph.o: graph.cc graph.h
	g++ -c graph.cc

disjoint.o: disjoint.cc disjoint.h
	g++ -c disjoint.cc

test_disjoint.o: test_disjoint.cc disjoint.h disjoint.cc
	g++ -c test_disjoint.cc

node.o: node.h node.cc
	g++ -c node.cc

test_disjoint: test_disjoint.o disjoint.o node.o
	g++ test_disjoint.o disjoint.o node.o -o test_disjoint

//==============================================================================
//==============================================================================
tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a all
