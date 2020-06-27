#include "HashT.h"
HashT::HashT() {
	Table = new Pair*[__SIZE_l]();
	marked = new bool[__SIZE_l]();
}
int HashT::h(int k) {
	return k % (__SIZE_l);
}
/*int HashT::getBypos(int i) {
	return Table[i]->value;
}*/
void HashT::put(int k, int v) {
	
	int index;
	int c= h(k);
	for (int i = 0;;) {
		/*
		}*/
		index= h(k + (i)* i) ;
		i++;
		if (i != 1 && c == index) {
			cout << "value cant be inserted.\n";
			break;
		}
		if (index > __SIZE_l) {
			break;
		}
		if (!marked[index]) {
			//
			if(Table[index]==NULL)
			Table[index] = new Pair;
			Table[index]->key = k;
			Table[index]->value = v;
			marked[index] = 1;
			break;
		}
	}
}
int HashT::get(int k) {
	int index;
	index = h(k);
	/*if (marked[index]) {
		if (Table[index]->key == k) {
			return Table[index]->value;
		}
	}*/
	int c = h(k);
	for (int i = 0;;) {
		index = h(k+(i)*i);
		i++;
		if (i != 1 && c == index) {
			break;
		}
		if (index > __SIZE_l) {
			break;
		}
		if (marked[index]) {
			if (Table[index] != NULL) {
				if (Table[index]->key == k) {
					return Table[index]->value;
				}
			}
		}
		
	}
	return -1;
}
void HashT::remove(int k) {
	int index;
	
	int c = h(k);
	for (int i = 0;;) {
		index = h(k + (i)* i);
		i++;
		if (i != 1 && c == index) {
			break;
		}if (index > __SIZE_l) {
			break;
		}
		if (marked[index]) {
			if (Table[index]->key == k) {
				marked[index] = 0;
				break;
			}
		}
		
		
	}
}