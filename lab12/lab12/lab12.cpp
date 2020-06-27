#include <iostream>
#include "Slist.h"
#include "Graph.h"
#include "Queue.h"
using namespace std;
int main()
{/*
	Slist x;
	x.insert(5);
	cout << x.At(0);
	*/
	
	Graph x(7);
	x.AddEdge(1, 2);
	x.AddEdge(1, 4);
	x.AddEdge(2, 5);
	x.AddEdge(2, 3);
	x.AddEdge(3, 6);
	x.AddEdge(3, 5);
	x.AddEdge(4, 5);
	x.depthFirstSearch(1);
	//x.breadthFirstSearch(0);
	/*int s; cin >> s;
	cout << x.findCycle(s) << endl;
	/*
	Queue x;
	x.enqueue(5);
	cout << x.getTop();
	*/
}
