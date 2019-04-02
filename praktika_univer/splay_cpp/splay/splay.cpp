#include <iostream>
#include "splay.h"
#include <cstdlib>

using namespace std;

splay_tree :: splay_tree(){
	root = NULL;
}

splay_tree :: ~splay_tree(){}

void splay_tree :: rightRotate(node *P)
{
	node *T=P->left;
	node *B=T->right;
	node *D=P->parent;
	if(D)
	{
		if(D->right==P)
            D->right=T;
		else
            D->left=T;
	}
	if(B)
		B->parent=P;
	T->parent=D;
	T->right=P;

	P->parent=T;
	P->left=B;
}
void splay_tree :: leftRotate(node *P)
{
	node *T=P->right;
	node *B=T->left;
	node *D=P->parent;
	if(D)
	{
		if(D->right==P)
            D->right=T;
		else
            D->left=T;
	}
	if(B)
		B->parent=P;
	T->parent=D;
	T->left=P;

	P->parent=T;
	P->right=B;
}

void splay_tree :: Splay(node *T)
{
	while(1)
	{
		node *p=T->parent;
		if(!p)
            break;

		node *pp=p->parent;
		if(!pp)//Zig
		{
			if(p->left==T)
				rightRotate(p);
			else
				leftRotate(p);
			break;
		}
		if(pp->left==p)
		{
			if(p->left==T)
			{//ZigZig
				rightRotate(pp);
				rightRotate(p);
			}
			else
			{//ZigZag
				leftRotate(p);
				rightRotate(pp);
			}
		}
		else
		{
			if(p->left==T)
			{//ZigZag
				rightRotate(p);
				leftRotate(pp);
			}
			else
			{//ZigZig
				leftRotate(pp);
				leftRotate(p);
			}
		}
	}
	root=T;
}
void splay_tree :: Insert(int value)
{
	if(!root)
	{
		root= new node();
		root->left=NULL;
		root->right=NULL;
		root->parent=NULL;
		root->value=value;
		return;
	}
	node *P = root;
	while(1)
	{
		if(P->value==value)
            break;
		if(value < (P->value) )
		{
			if(P->left) P=P->left;
			else
			{
				P->left=new node();
				P->left->parent=P;
				P->left->right=NULL;
				P->left->left=NULL;
				P->left->value=value;
				P=P->left;
				break;
			}
		}
		else
		{
			if(P->right) P=P->right;
			else
			{
				P->right=new node();
				P->right->parent=P;
				P->right->right=NULL;
				P->right->left=NULL;
				P->right->value=value;
				P=P->right;
				break;
			}
		}
	}
	Splay(P);
}
void splay_tree :: show_it()
{
	show_it(root);
}

void splay_tree :: show_it(node *R)
{
	if(!R)
        return;
	show_it(R->left);
	cout <<"Value: "<< R->value << "|";
	if(R->left)
        cout <<"Left is: " << R->left->value << "|";
	if(R->right)
        cout <<"Right is: " << R->right->value << "|";
	cout <<"";
	show_it(R->right);
}

node* splay_tree :: lookup(int v)
{
	if(!root) return NULL;
	node *P=root;
	while(P)
	{
		if(P->value==v)
			break;
		if(v<(P->value))
		{
			if(P->left)
				P=P->left;
			else
				break;
		}
		else
		{
			if(P->right)
				P=P->right;
			else
				break;
		}
	}
	Splay(P);
	if(P->value==v)
        return P;
	else
        return NULL;
}

int splay_tree :: delete_it(int v)
{
	node *N=lookup(v);
	if(!N) return 0;
	Splay(N);
	node *P=N->left;
	if(!P)
	{
		root=N->right;
		root->parent=NULL;
		free(N);
		return 1;
	}
	while(P->right) P=P->right;
	if(N->right)
	{
		P->right=N->right;
		N->right->parent=P;
	}
	root=N->left;
	root->parent=NULL;
	free(N);
	return 1;
}

