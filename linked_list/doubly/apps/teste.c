#include "../include/doubly_linked_list.h"
#include <stdio.h>

int main(){
    
    LinkedList* L = LinkedList_create();
    LinkedList* L2 = LinkedList_create();

    LinkedList_addFirst(L, 1);
    LinkedList_addFirst(L, 2);
    LinkedList_addFirst(L2, 4);
    LinkedList_addFirst(L2, 5);
    LinkedList_addAt(L, 3 , 0);
    //LinkedList_addLast(L, 0);

    printf("Antes do concat\n");
    LinkedList_print(L);
    LinkedList_print(L2);
    printf("\n\n");

    printf("#   Ultimo val: %d\n", LinkedList_back(L)), 
    LinkedList_concat(L, L2);
    printf("Depois do concat\n");
    printf("#   Ultimo val: %d\n", LinkedList_back(L));
    LinkedList_print(L);
    printf("\n\n");

    LinkedList_Sort(&L);
    printf("Depois do sort\n");
    LinkedList_print(L);


    LinkedList_destroy(&L);
    
    return 0;
}