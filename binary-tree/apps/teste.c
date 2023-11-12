#include "../include/binary_tree.h"
#include <stdio.h>

int main(){

    BinaryTree *t = BinaryTree_create(1);

    BinaryTree_add(t, 1);

    BinaryTree_add(t, 5);

    BinaryTree_add(t, 2);

    BinaryTree_add(t, 4);

    BinaryTree_add(t, 3);

    BinaryTree_add(t, 324);


    printf("Tem 3 = %d\n", BinaryTree_search(t, 3));
    printf("Tem 5 = %d\n", BinaryTree_search(t, 5));
    printf("Tem 0 = %d\n", BinaryTree_search(t, 0));
    printf("Tem 4 = %d\n", BinaryTree_search(t, 4));
    printf("Tem -1 = %d\n", BinaryTree_search(t, -1));
    printf("Tem 324 = %d\n", BinaryTree_search(t, 324));

    return 0;
}