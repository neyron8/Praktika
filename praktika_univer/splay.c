#include<stdio.h>
#include<stdlib.h>
#include "splay.h"

void rightRotate(Node *P)
{
	Node *T=P->left;
	Node *B=T->right;
	Node *D=P->parent;
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
void leftRotate(Node *P)
{
	Node *T=P->right;
	Node *B=T->left;
	Node *D=P->parent;
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

void Splay(Node *T)
{
	while(1)
	{
		Node *p=T->parent;
		if(!p)
            break;

		Node *pp=p->parent;
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
void Insert(int value)
{
	if(!root)
	{
		root=(Node *)malloc(sizeof(Node));
		root->left=NULL;
		root->right=NULL;
		root->parent=NULL;
		root->value=value;
		return;
	}
	Node *P=root;
	while(1)
	{
		if(P->value==value)
            break;
		if(value < (P->value) )
		{
			if(P->left) P=P->left;
			else
			{
				P->left=(Node *)malloc(sizeof(Node));
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
				P->right=(Node *)malloc(sizeof(Node));
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
void show_it(Node *R)
{
	if(!R)
        return;
	show_it(R->left);
	printf("Value: %d |",R->value);
	if(R->left)
        printf("Left is: %d |",R->left->value);
	if(R->right)
        printf("Right is: %d |",R->right->value);
	puts("");
	show_it(R->right);
}
Node* lookup(int v)
{
	if(!root) return NULL;
	Node *P=root;
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
int delete_it(int v)
{
	Node *N=lookup(v);
	if(!N) return 0;
	Splay(N);
	Node *P=N->left;
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
