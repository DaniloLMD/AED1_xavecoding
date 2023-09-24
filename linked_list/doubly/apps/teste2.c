#include "../include/doubly_linked_list.h"
#include <stdio.h>

int main(){

    printf("sou o teste DOIS\n");
    
    LinkedList* L = LinkedList_create();
    
    LinkedList_addFirst(L, 3);
    LinkedList_addFirst(L, 2);
    LinkedList_addFirst(L, 1);

    LinkedList_print(L);
    printf("\n\n");
    LinkedList_Sort(&L);
    LinkedList_print(L);

    LinkedList_destroy(&L);
    
    return 0;
}