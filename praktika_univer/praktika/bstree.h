#ifndef BSTREE_C
#define BSTREE_C

struct node{
	int value;
	node *left;
	node *right;
};

class btree{
public:

	btree();
	~btree();

	int create(int key);
	int insert(int key);
	node *search(int key);
	void delete_tree();
	void inorder_print();
	node *min();
	node *max();

private:
	void delete_tree(node *leaf);
	void insert(int key, node *leaf);
	node *search(int key, node *leaf);
	void inorder_print(node *leaf);

	node *root;
};

#endif
