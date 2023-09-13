#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _snode{
    int val; 
    struct _snode* next;
} SNode;

typedef struct _linked_list{
    struct _snode* begin;
} LinkedList;


                //funcoes de node
//cria um nó
SNode* SNode_create(int val){
    SNode* n = (SNode*) calloc(1, sizeof(SNode));
    n->next = NULL;
    n->val = val;

    return n;
}

            //funcoes de linked list
//cria uma lista encadeada simples
LinkedList* LinkedList_create(void){
    LinkedList* L = (LinkedList*) calloc(1, sizeof(LinkedList));
    L->begin = NULL;
    
    return L;
}

//adiciona um elemento no inicio de uma lista
void LinkedList_addFirst(LinkedList* L, int val){
    SNode* n = SNode_create(val);
    n->next = L->begin;   
    L->begin = n;
}

//printando os valores de uma linked list
void LinkedList_print(const LinkedList* L){
    SNode *p = L->begin;
    printf("L -> ");
    while(p){
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n");
}