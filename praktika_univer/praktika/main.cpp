#include "bstree.h"
#include <iostream>

using namespace std;

int main(){

	btree *tree = new btree();
	tree->insert(10);
	tree->create(20);
	tree->insert(6);
	tree->insert(14);
	tree->insert(5);
	tree->insert(8);
	tree->insert(11);
	tree->insert(18);

	node* find = new node();


	tree->inorder_print();

	tree->search(99);
	tree->search(6);
	find = tree->min();
	cout << find -> value;
	find = tree->max();
	cout << find -> value;

	tree -> delete_tree();

    find = tree->max();
}
