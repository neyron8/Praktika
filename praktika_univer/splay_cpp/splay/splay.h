#ifndef SPLAY_H
#define SPLAY_H

struct node {
	node *left;
	node *right;
	node *parent;
	int value;
};

class splay_tree{
public:
	splay_tree();
	~splay_tree();
    void Insert(int value);
    void show_it();
    node* lookup(int v);
    int delete_it(int v);
private:
    void leftRotate(node *P);
	void rightRotate(node *P);
    void Splay(node *T);
    void show_it(node *R);
	node *root;
};

#endif

