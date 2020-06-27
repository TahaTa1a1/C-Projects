#ifndef SLLIST
#define SLLIST
#include <iostream>
#include <assert.h>
using namespace std;
struct Node
{
	int info;
	Node* next;
};
class Slist
{
public:
	Slist();
	void insert(int);
	void del();
	void del(int);
	Node* getHead();
	int At(int);
	~Slist();
private:
	Node* head;
};
#endif
