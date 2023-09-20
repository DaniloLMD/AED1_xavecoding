#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct _snode SNode;
typedef struct _linked_list LinkedList;

/*********************************** funcoes de node ****************************************************/
SNode* Snode_create(int val);

/****************************** funcoes de linked list **************************************************/

//cria uma linked list simples
LinkedList* SimpleLinkedList_create(void);
//destroi uma linked list simples
void SimpleLinkedList_destroy(LinkedList** L);

//adiciona um elemento no inicio da lista
void SimpleLinkedList_addFirst(LinkedList* L, int val);
//adiciona um elemento no final de uma lista
void SimpleLinkedList_addLast(LinkedList* L, int val);
//adiciona na lista "L" o valor "val" na posicao "index"
void SimpleLinkedList_addAt(LinkedList* L, int val, int index);
//insere o elemento na lista de maneira ordenada
void SimpleLinkedList_addSorted(LinkedList* L, int val);

//destroi o primeiro valor VAL encontrado na lista L
void SimpleLinkedList_removeFirstValue(LinkedList* L, int val);
//destroi todos os valores VAL encontrados na lista L
void SimpleLinkedList_removeAllValues(LinkedList* L, int val);
//destroi o nó no indice "i" informado
void SimpleLinkedList_removeAt(LinkedList* L, int i);
//apaga todos os elementos da lista
void SimpleLinkedList_removeAll(LinkedList*L);

//verifica se a lista esta vazia e retorna True(vazia) ou False(nao vazia)
char SimpleLinkedList_empty(LinkedList* L);


//retorna o primeiro elemento da lista
int SimpleLinkedList_front(LinkedList* L);
//retorna o ultimo elemento da lista
int SimpleLinkedList_back(LinkedList* L);
//retorna o valor no index da lista L
int SimpleLinkedList_at(LinkedList* L, int index);

//printa os valores de uma linked list
void SimpleLinkedList_print(const LinkedList* L);

//retorna o tamanho da lista
unsigned long int LinkedList_size(const LinkedList* L);

//inverte uma lista L
void SimpleLinkedList_reverse(LinkedList* L);

//concatena os elementos de L2 em L1
void SimpleLinkedList_concat(LinkedList* L1, LinkedList* L2);

//ordenando lista por um algoritmo da minha cabeça
void SimpleLinkedList_Sort(LinkedList** L_adress);

#endif
