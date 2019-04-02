#include "bstree.h"
#include <iostream>

using namespace std;

btree :: btree(){
	root = NULL;
}

btree :: ~btree(){
	delete_tree();
}

void btree :: delete_tree(node *leaf){

	if(leaf != NULL){
		delete_tree(leaf->left);
		delete_tree(leaf->right);
		delete leaf;
	}
	root = NULL;
}

void btree :: insert(int key, node *leaf){

	if(key < leaf->value){
		if(leaf->left != NULL){
			insert(key, leaf->left);
		}else{
			leaf->left = new node;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}else if(key >= leaf->value){
		if(leaf->right != NULL){
			insert(key, leaf->right);
		}else{
			leaf->right = new node;
			leaf->right->value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}

}

node *btree :: min(){
    if (root == NULL){
        cout << "Tree is not created(Error at min function)\n";
        return NULL;
    }
    node* look = new node();
    look = root;
    while(look->left != NULL)
        look = look -> left;
    return look;
}

node *btree :: max(){
    if (root == NULL){
        cout << "Tree is not created(Error at max function)\n";
        return NULL;
    }
    node* look = new node();
    look = root;
    while(look->right != NULL)
        look = look -> right;
    return look;
}


int btree :: create(int key){

    if(root != NULL){
        cout << "Tree almost created node with key: "<< key <<" will not inserted\n";
        return -1;
    }
    root = new node;
    root->value = key;
    root->left = NULL;
    root->right = NULL;

    cout << "Tree created\n";

    return 0;

}

int btree :: insert(int key){
	if(root != NULL){
		insert(key, root);
	}else{
	    cout << "Tree is not created yet, node with key:"<< key <<" will not inserted\n";
		return -1;
	}
}

node *btree :: search(int key, node *leaf){
	if(leaf != NULL){
		if(key == leaf->value){
			return leaf;
		}
		if(key < leaf->value){
			return search(key, leaf->left);
		}else{
			return search(key, leaf->right);
		}
	}else{
		return NULL;
	}
}

node *btree :: search(int key){

    node*k = search(key, root);
    if (k == NULL){
        cout << "There is no searching node: " << key <<"\n";
        return NULL;
    }
    cout << "Searching node: " << key <<" founded\n";
    return k;
}

void btree :: delete_tree(){
	delete_tree(root);
}

void btree :: inorder_print(){
	inorder_print(root);
	cout << "\n";
}

void btree :: inorder_print(node *leaf){
	if(leaf != NULL){
		inorder_print(leaf->left);
		cout << leaf->value << " ";
		inorder_print(leaf->right);
	}
}

