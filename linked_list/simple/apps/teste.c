#include "../include/simple_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    LinkedList* L = SimpleLinkedList_create();
    
    SimpleLinkedList_addSorted(L, 1);
    SimpleLinkedList_addSorted(L, 2);
    SimpleLinkedList_addSorted(L, 3);
    SimpleLinkedList_print(L);
    SimpleLinkedList_removeAt(L, 0);
    SimpleLinkedList_print(L);

    SimpleLinkedList_destroy(&L); //destroi a lista

    return 0;
}