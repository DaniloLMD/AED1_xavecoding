#include "../include/binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

struct _node{
    int val;
    struct _node *right;
    struct _node  *left;
};

struct _binary_tree{
    struct _node *root;
};

Node* Node_create(int val){
    Node* new_node = (Node*) malloc(1 * sizeof(Node));
    new_node->right = NULL;
    new_node->left = NULL;
    new_node->val = val;
}

BinaryTree *BinaryTree_create(){
    BinaryTree* new_tree = (BinaryTree*) malloc(1 * sizeof(BinaryTree));
    new_tree->root = NULL;
    return new_tree;
}

void BinaryTree_add(BinaryTree *t, int val){
    Node *new_node = Node_create(val);

    if(BinaryTree_isEmpty(t)){
        t->root = new_node;
        return;
    }

    Node *node_atual = t->root;
    while(1){
        if(val > node_atual->val){
            if(node_atual->right == NULL){
                node_atual->right = new_node;
                return;
            }
            node_atual = node_atual->right;
        }
        else{
            if(node_atual->left == NULL){
                node_atual->left = new_node;
                return;
            }
            node_atual = node_atual->left;
        }
    }
}

bool BinaryTree_isEmpty(BinaryTree *t){
    return t->root == NULL;
}

bool BinaryTree_search(BinaryTree *t, int val){
    Node *node_atual = t->root;

    while(node_atual != NULL){
        if(val > node_atual->val){
            node_atual = node_atual->right;
        }
        else if(val < node_atual->val){
            node_atual = node_atual->left;
        }
        else if(node_atual->val == val){
            return true;
        }
    }

    return false;
}




