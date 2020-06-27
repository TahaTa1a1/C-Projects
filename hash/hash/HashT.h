#ifndef HASH_
#define HASH_
#define __SIZE_l 11
#include <iostream>
using namespace std;
struct Pair
{
	int key;
	int value;
};
class HashT
{
public:
	HashT();
	void put(int k, int v);
	int get(int k);
	void remove(int k);
	//~HashT();
	//int getBypos(int);
private:
	Pair** Table;
	bool* marked;
	int h(int k);
};
#endif
