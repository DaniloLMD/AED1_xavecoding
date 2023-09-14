#include "../include/linked_list.h"
#include <stdio.h>
#include <stdlib.h>

struct _snode{
    int val; 
    struct _snode* next;
};

struct _linked_list{
    struct _snode* begin;
    struct _snode* end;
};

/******************************** funcoes de node *******************************************************/
//cria um nó
SNode* SNode_create(int val){
    SNode* n = (SNode*) calloc(1, sizeof(SNode));
    n->next = NULL;
    n->val = val;

    return n;
}


/****************************** funcoes de linked list **************************************************/
//cria uma lista encadeada simples
LinkedList* LinkedList_create(void){
    LinkedList* L = (LinkedList*) calloc(1, sizeof(LinkedList));
    L->begin = L->end = NULL;
    
    
    return L;
}

//adiciona um elemento no inicio de uma lista
void LinkedList_addFirst(LinkedList* L, int val){
    SNode* new_node = SNode_create(val);
    new_node->next = L->begin;   

    if(LinkedList_empty(L)) L->end = new_node;
    L->begin = new_node;
}

//adiciona um elemento no final de uma lista
void LinkedList_addLast(LinkedList* L, int val){
    SNode* new_node = SNode_create(val);
    if(LinkedList_empty(L)){
        L->begin = L->end = new_node;
    }
    else{
        L->end->next = new_node;
        L->end = new_node;
    }
}

//verifica se a lista esta vazia e retorna True(vazia) ou False(nao vazia)
char LinkedList_empty(LinkedList* L){
    return L->begin == NULL;
}

/*//retorna o primeiro elemento da lista
int LinkedList_front(LinkedList* L){
    return L->end->val;
}
//retorna o ultimo elemento da lista
int LinkedList_back(LinkedList* L){
    SNode*p = L->end;
    return p->val;
}*/

//printando os valores de uma linked list
void LinkedList_print(const LinkedList* L){
    SNode *p = L->begin;
    printf("L -> ");
    while(p != NULL){
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n");
}