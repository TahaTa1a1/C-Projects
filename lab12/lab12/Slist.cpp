#include "Slist.h"
Slist::Slist() {
	head = 0;
}
void Slist::insert(int v) {
	Node* p = new Node;
	p->info = v;
	if (head == 0) {
		head = p;
		p->next = 0;
	}
	else {
		p->next = head;
		head = p;
	}
}
void Slist::del(int v) {

	if (head != 0) {
		Node* p;
		for (p = head; p->info != v; p = p->next);
		if (p != head) {
			Node* g;
			for (g = head; g->next != p; g = g->next);
			g->next = p->next;
			delete p;
		}
		else {
			head = head->next;
			delete p;
		}
	}
}
void Slist::del() {
	if (head != 0) {
		Node* p = head;
		head = head->next;
		delete p;
	}
}
Node* Slist::getHead() {
	return head;
}
int Slist::At(int index) {
	//
	int size = 0;
	for (Node* p = head; p != 0; p = p->next)size++;
	if (index >= size) {
		assert(1);
	}
	else {
		size = 0;
		Node* p = head;
		for (; size != index; p = p->next, size++);
		return  p->info;
	}
}
Slist::~Slist() {
	while (head != 0)del();
}