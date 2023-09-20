#include "../include/doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

//dnode = doubly node
struct _dnode{
    int val; 
    struct _dnode* next;
    struct _dnode* prev;
};

struct _doubly_linked_list{
    struct _dnode* begin;
    struct _dnode* end;
    unsigned long int size;
};

/*********************************** funcoes de node ****************************************************/
DNode* Dnode_create(int val);


/****************************** funcoes de linked list **************************************************/

LinkedList* LinkedList_create(void);

void LinkedList_destroy(LinkedList** L);


void LinkedList_addFirst(LinkedList* L, int val);

void LinkedList_addLast(LinkedList* L, int val);

void LinkedList_addAt(LinkedList* L, int val, int index);

void LinkedList_addSorted(LinkedList* L, int val);

void LinkedList_removeFirstValue(LinkedList* L, int val);

void LinkedList_removeAllValues(LinkedList* L, int val);

void LinkedList_removeAt(LinkedList* L, int i);

void LinkedList_removeAll(LinkedList*L);

bool LinkedList_empty(LinkedList* L);


int LinkedList_front(LinkedList* L);

int LinkedList_back(LinkedList* L);

int LinkedList_at(LinkedList* L, int index);

void LinkedList_print(const LinkedList* L);

unsigned long int LinkedList_size(const LinkedList* L);

void LinkedList_reverse(LinkedList* L);

void LinkedList_concat(LinkedList* L1, LinkedList* L2);

void LinkedList_Sort(LinkedList** L_adress);