#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct _snode SNode;
typedef struct _linked_list LinkedList;

/*********************************** funcoes de node ****************************************************/
SNode* Snode_create(int val);


/****************************** funcoes de linked list **************************************************/

//cria uma linked list simples
LinkedList* LinkedList_create(void);
//destroi uma linked list simples
void LinkedList_destroy(LinkedList** L);

//adiciona um elemento no inicio da lista
void LinkedList_addFirst(LinkedList* L, int val);
//adiciona um elemento no final de uma lista
void LinkedList_addLast(LinkedList* L, int val);

//destroi o primeiro valor VAL encontrado na lista L
void LinkedList_removeFirstValue(LinkedList* L, int val);
//destroi todos os valores VAL encontrados na lista L
void LinkedList_removeAllValues(LinkedList* L, int val);
//destroi o nó no indice "i" informado
void LinkedList_removeAt(LinkedList* L, int i);

//verifica se a lista esta vazia e retorna True(vazia) ou False(nao vazia)
char LinkedList_empty(LinkedList* L);


//retorna o primeiro elemento da lista
int LinkedList_front(LinkedList* L);
//retorna o ultimo elemento da lista
int LinkedList_back(LinkedList* L);

//printa os valores de uma linked list
void LinkedList_print(const LinkedList* L);

//retorna o tamanho da lista
unsigned long int LinkedList_size(const LinkedList* L);

#endif