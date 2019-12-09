
CPPOPTIONS = -c -g -Wall -std=c++0x

all: test_disjoint

//==============================================================================

test_graph: graph.o test_graph.o disjoint.o pqueue.o
	g++ graph.o test_graph.o disjoint.o -o test_graph

test_graph.o: test_graph.cc graph.h graph.cc disjoint.cc disjoint.h pqueue.cc pqueue.h
	g++ -c test_graph.cc

graph.o: graph.cc graph.h
	g++ -c graph.cc

disjoint.o: disjoint.cc disjoint.h
	g++ -c disjoint.h

pqueue.o: pqueue.cc pqueue.h MinHeap.cc MinHeap.h
	g++ -c pqueue.h

test_disjoint.o: test_disjoint.cc disjoint.h disjoint.cc
	g++ -c test_disjoint.cc


test_disjoint: test_disjoint.o disjoint.o
	g++ test_disjoint.o disjoint.o -o test_disjoint

//==============================================================================
//==============================================================================
tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a all
