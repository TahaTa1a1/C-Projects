#ifndef BST_CLASS
#define BST_CLASS
#include <iostream>
using namespace std;

struct Node
{
	int key;
	Node* left, * right;
};
class BST
{
public:
	BST();
	void addNode(int);
	void printAllNode();
	bool searchNode(int);
	int	nodesCount();
	bool isEmpty();
	void deleteNode(int);
	~BST();
private:
	Node* root;
	Node* searchNode(Node*&, int);
	void printAllNode(Node* r);
	void addNode(Node*&, int);
	void nodesCount(Node*);
	void deleteNode(Node*&, int);
	Node* Min(Node*& r);
};
#endif

