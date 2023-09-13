#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct _snode SNode;
typedef struct _linked_list LinkedList;

//funcoes de node
SNode* Snode_create(int val);

//funcoes de linked list
LinkedList* LinkedList_create(void);

void LinkedList_addFirst(LinkedList* L, int val);

void LinkedList_print(const LinkedList* L);

#endif