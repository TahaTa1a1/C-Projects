#include "Queue.h"
Queue::Queue() {
	head = tail = 0;
}
void Queue::enqueue(int v) {
	QNode* p = new QNode;
	p->info = v;
	if (tail == 0) {
		tail = head = p;
		p->next = 0;
	}
	else {
		tail->next = p;
		p->next = 0;
		tail = p;
	}
}
void Queue::dequeue() {
	QNode* p = head;
	if (head != tail) {
		head = head->next;
		
	}
	else {
		head = tail = 0;
	}
	delete p;
}
QNode* Queue::getHead() {
	return head;
}
int Queue::getTop() {
	return head->info;
}
Queue::~Queue() {
	while (head!=0)
	{
		dequeue();
	}
}