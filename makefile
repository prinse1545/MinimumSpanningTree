
CPPOPTIONS = -c -g -Wall -std=c++0x

all: test_set

//==============================================================================

test_graph: graph.o test_graph.o
	g++ graph.o test_graph.o -o test_graph

test_graph.o: test_graph.cc graph.h graph.cc
	g++ -c test_graph.cc

graph.o: graph.cc graph.h
	g++ -c graph.cc

#set.o: set.cc set.h
#	g++ -c set.cc

test_set.o: test_set.cc set.cc set.h
	g++ -c test_set.cc

test_set: test_set.o
	g++ test_set.o set.o -o test_set

//==============================================================================
//==============================================================================
tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a all
