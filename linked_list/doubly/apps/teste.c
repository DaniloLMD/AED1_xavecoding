#include "../include/doubly_linked_list.h"
#include <stdio.h>

int main(){
    
    LinkedList* L = LinkedList_create();

    printf("PRIMEIRO PRINT\n");
    //LinkedList_print(L);
    LinkedList_print(L);
    printf("\n\n");

    printf("ADICIONEI 1 (FIRST) \n");
    LinkedList_addFirst(L, 1);
    LinkedList_print(L);
    //LinkedList_print(L);
    printf("\n\n");

    printf("ADICIONEI 3 (LAST)\n");
    LinkedList_addLast(L, 3);
    LinkedList_print(L);;
    //LinkedList_print(L);
    printf("\n\n");

    printf("ADICIONEI 2 (SORTED) \n");
    LinkedList_addSorted(L, 2);
    LinkedList_print(L);
    //LinkedList_print(L);
    printf("\n\n");

    printf("INVERTI\n");
    LinkedList_reverse(L);
    LinkedList_print(L);
    printf("\n\n");

    printf("ADICIONEI 4 (AT [0])\n");
    LinkedList_addAt(L, 4, 0);
    LinkedList_print(L);
    printf("\n\n");
    
    LinkedList_addLast(L, 2);
    LinkedList_addLast(L, 2);
    LinkedList_addLast(L, 2);
    LinkedList_addLast(L, 2);
    printf("ADICIONEI MUITOS 2\n"); 
    LinkedList_print(L);
    printf("\n\n");

   printf("REMOVI TODOS OS 2\n");
   LinkedList_removeAllValues(L, 2);
   LinkedList_print(L);
   printf("\n\n");

   printf("REMOVI TODOS OS VALORES\n");
   LinkedList_removeAll(L);
   LinkedList_print(L);
   printf("\n\n");


    LinkedList_destroy(&L);
    
    return 0;
}