#include "../include/linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    LinkedList* L = LinkedList_create();

    LinkedList_addLast(L, 1);
    LinkedList_addLast(L, 2);
    LinkedList_addLast(L, 3);
    LinkedList_addLast(L, 4);
    LinkedList_addLast(L, 4);
    LinkedList_addLast(L, 4);
    LinkedList_addLast(L, 5);
    LinkedList_addLast(L, 4);
    LinkedList_addLast(L, 5);
    LinkedList_addLast(L, 4);
    LinkedList_addLast(L, 4);

    LinkedList_print(L);

    LinkedList_removeAllValues(L, 4);
    LinkedList_removeFirstValue(L, 5);
    LinkedList_removeFirstValue(L, 5);
    LinkedList_removeAllValues(L, 80);
    LinkedList_removeAt(L, 2);

    LinkedList_print(L);

    LinkedList_destroy(&L); 

    return 0;
}