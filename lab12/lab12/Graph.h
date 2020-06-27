#ifndef Graph_
#define Graph_
#include <iostream>
#include <assert.h>
#include "Slist.h"
#include "Queue.h"
using namespace std;
class Graph
{
public:
	Graph(int V);
	void AddEdge(int V, int E);
	void deleteEdge(int V, int E);
	//void depthFirstSearch();
	void breadthFirstSearch(int);
	void depthFirstSearch(int);
	bool findCycle(int);
	//~Graph();
private:
	Slist* ver;
	int size;
	void depthFirstSearch(int, bool[]);
	void findCycle(int s, int[]);
	void breadthFirstSearch(int, bool[]);
};
#endif

