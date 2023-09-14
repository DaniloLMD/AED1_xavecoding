#include "../include/linked_list.h"
#include <stdio.h>

int main(){

    LinkedList* L = LinkedList_create();
    LinkedList_print(L);
    LinkedList_addLast(L, 0);
    LinkedList_print(L);
    LinkedList_addFirst(L, 2);
    LinkedList_print(L);   
    LinkedList_addFirst(L, 1);
    LinkedList_print(L);
    LinkedList_addLast(L, 3);
    LinkedList_print(L);

    

    return 0;
}