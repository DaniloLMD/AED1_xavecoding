#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct _doubly_node DNode;
typedef struct _doubly_linked_list LinkedList;
typedef char bool;

//cria e retorna um nó duplo
DNode* DNode_create(int val);

//cria uma linked list dupla
LinkedList* LinkedList_create(void);
//destroi uma linked list dupla
void LinkedList_destroy(LinkedList** L_ref);

//adiciona um elemento no inicio da lista
void LinkedList_addFirst(LinkedList* L, int val);
//adiciona um elemento no final de uma lista
void LinkedList_addLast(LinkedList* L, int val);
//adiciona na lista "L" o valor "val" na posicao "index"
void LinkedList_addAt(LinkedList* L, int val, unsigned long int index);
//insere o elemento na lista de maneira ordenada
void LinkedList_addSorted(LinkedList* L, int val);

//destroi o primeiro valor VAL encontrado na lista L
void LinkedList_removeFirstValue(LinkedList* L, int val);
//destroi todos os valores VAL encontrados na lista L
void LinkedList_removeAllValues(LinkedList* L, int val);
//destroi o nó no indice "i" informado
void LinkedList_removeAt(LinkedList* L, unsigned long int i);
//apaga todos os elementos da lista
void LinkedList_removeAll(LinkedList*L);

//verifica se a lista esta vazia e retorna True(vazia) ou False(nao vazia)
bool LinkedList_empty(LinkedList* L);


//retorna o primeiro elemento da lista
int LinkedList_front(LinkedList* L);
//retorna o ultimo elemento da lista
int LinkedList_back(LinkedList* L);
//retorna o valor no index da lista L
int LinkedList_at(LinkedList* L, long unsigned int index);

//printa os valores de uma linked list
void LinkedList_print(const LinkedList* L);

//retorna o tamanho da lista
unsigned long int LinkedList_size(const LinkedList* L);

//inverte uma lista L
void LinkedList_reverse(LinkedList* L);

//concatena os elementos de L2 em L1
void LinkedList_concat(LinkedList* L1, LinkedList* L2);

//ordenando lista por um algoritmo da minha cabeça
void LinkedList_Sort(LinkedList** L_adress);

void SimpleLinkedList_print(const LinkedList* L);

#endif

/*
    FALTAM:
    - Testar
    - Sort
*/
