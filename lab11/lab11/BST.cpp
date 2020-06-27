#include "BST.h"
static int y = 0;
BST::BST() {
	root = 0;
}
bool BST::isEmpty() {
	return root == 0;
}
void BST::addNode(int v) {
	addNode(root, v);
	
}
void BST::addNode(Node*& root, int v) {
	
	if (root == 0) {
		Node* p = new Node;
		p->key = v;
		p->left = 0;
		p->right = 0;
		root = p;
		return;
	}
	if (root->key > v) {
		return addNode(root->left, v);
	}
	else
		return addNode(root->right, v);
}
bool BST::searchNode(int v) {

	Node* p=searchNode(root, v);
	if (p == 0)
		return 0;
	else {
		return 1;
	}
}
Node* BST::searchNode(Node*& root, int v) {
	if (root->key==v) {
		return root;
	}
	if (root == 0) {
		return 0;
	}
	if (root->key > v) {
		return searchNode(root->left, v);
	}
	else
		return searchNode(root->right, v);
}
void BST::printAllNode() {
	printAllNode(root);
}
void BST::printAllNode(Node* r) {
	if (r == 0) {
		return;
	}
	cout << r->key << endl;
	printAllNode(r->left);
	
	printAllNode(r->right);
	
}

int	BST::nodesCount() {
	nodesCount(root);
	return y;
}
void BST::nodesCount(Node* r) {
	
	if (r->left == 0 && r->right == 0) {
		return ;
	}
	y++;
	if(r->left!=0)
	nodesCount(r->left);
	if(r->right!=0)
	nodesCount(r->right);
}
void BST::deleteNode(int v) {
	deleteNode(root,v);
}
void BST::deleteNode(Node*& p, int v) {
	
	//p = p->left;
	if (p->key==v) {
		if (p->right == 0 && p->left == 0) {
			//case 0
			delete p;
			p = 0;
		}
		else if (p->left == 0 || p->right == 0) {
			//case 1
			Node* q = p;
			if (p->left == 0) {
				p = p->right;
			}
			else {
				p = p->left;
			}
			delete q;
		}
		else {
			//case 2
			Node* q = p;
			Node* s=Min(p->right);
			s->left = p->left;
			p = p->right;
			
			delete q;
		}
		return;
	}
	if (p->key > v) {
		return deleteNode(p->left, v);
	}
	else {
		return deleteNode(p->right, v);
	}
}
Node* BST::Min(Node*& r) {
	Node* p;
	for ( p = r; p->left != 0; p = p->left);
	return p;
}
BST::~BST() {
	while (!isEmpty()) {
		deleteNode(root->key);
	}
}