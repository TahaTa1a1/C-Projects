#ifndef Q
#define Q
#include <iostream>
using namespace std;
struct QNode
{
	int info;
	QNode* next;
};
class Queue
{
public:
	Queue();
	void enqueue(int);
	int getTop();
	QNode* getHead();
	void dequeue();
	~Queue();
private:
	QNode* head,* tail;
};
#endif

