#include "../include/linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    LinkedList* L = LinkedList_create();

    
    for(int c = 1 ; c <= 1000; c++)
{ 
    LinkedList_addFirst(L, c);
}
    printf("ANTES: "); 
    LinkedList_print(L);

    LinkedList_Sort(&L);
    printf("\n\n\n");

    printf("DEPOIS: ");
    LinkedList_print(L);

    LinkedList_destroy(&L); 

    return 0;
}