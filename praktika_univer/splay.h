#ifndef SPLAY_H
#define SPLAY_H

typedef struct Node {
	struct Node *left;
	struct Node *right;
	struct Node *parent;
	int value;
} Node;

Node *root;

#endif
