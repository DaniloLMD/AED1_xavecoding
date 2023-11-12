#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#define true 1
#define false 0
typedef char bool;
typedef struct _node Node;
typedef struct _binary_tree BinaryTree;

Node* Node_create(int val);

BinaryTree *BinaryTree_create();

void BinaryTree_add(BinaryTree *t, int val);

bool BinaryTree_isEmpty(BinaryTree *t);

bool BinaryTree_search(BinaryTree *t, int val);


#endif