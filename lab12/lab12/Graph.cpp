#include "Graph.h"
Queue Qu;
bool f = false;
Graph::Graph(int V) {
	ver = new Slist[V];
	size = V;
}
void Graph::AddEdge(int V, int E) {
	ver[V].insert(E);
	ver[E].insert(V);
}
void Graph::deleteEdge(int V, int E) {
	ver[V].del(E);
	ver[E].del(V);
}
bool Graph::findCycle(int s) {

	int* flag = new int[size]();
	findCycle(s, flag);
	/*for (int i = 0; i < size; i++) {
		if (!flag[i]) {
			findCycle(i, flag);
		}
	}*/
	return f;
}
void Graph::findCycle(int s, int flag[]) {
	if (!flag[s]) {
		flag[s] = 1;
		for (Node* p = ver[s].getHead(); p != NULL; p = p->next) {
			if (!flag[p->info]) {
				findCycle(p->info, flag);
			}
			else if (flag[p->info] == 1) {
				f = 1;
				//cout << p->info << endl;
			}
		}
		flag[s] = 2;
	}
}

void Graph::depthFirstSearch(int s) {
	bool* flag = new bool[size]();
	depthFirstSearch(s, flag);
	//
	for (int i = 0; i < size; i++) {
		if (!flag[i]) {
			depthFirstSearch(i, flag);
		}
	}
}
void Graph::depthFirstSearch(int s, bool flag[]) {
	flag[s] = 1;
	cout << s << endl;
	for (Node* p = ver[s].getHead(); p != NULL; p = p->next) {
		if (!flag[p->info]) {
			depthFirstSearch(p->info, flag);
		}
	}
}
void Graph::breadthFirstSearch(int s) {
	bool* visted = new bool[size]();

	breadthFirstSearch(s, visted);
	for (int i = 0; i < size; i++) {
		if (!visted[i]) {

			breadthFirstSearch(i, visted);
		}
	}
}

void Graph::breadthFirstSearch(int s, bool flag[]) {
	Node* p = ver[s].getHead();
	if (!flag[s]) {
		flag[s] = 1;
		
		cout << s << endl;
		Qu.enqueue(s);
	}
	for (; p != 0; p = p->next) {
		if (!flag[p->info]) {
			Qu.enqueue(p->info);
			flag[p->info] = 1;
			cout << p->info << endl;
			//breadthFirstSearch(p->info, flag);
		}
	}
	Qu.dequeue();
	if (Qu.getHead() != 0) {
		breadthFirstSearch(Qu.getHead()->info, flag);
	}
	
}