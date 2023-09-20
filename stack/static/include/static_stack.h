#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct _static_stack StaticStack;
typedef char bool;

/****************************** funcoes de static stack **************************************************/

//cria uma pilha estatica
StaticStack* StaticStack_create(long int capacity);
//destroi uma pilha estatica
void StaticStack_destroy(StaticStack** S);

//adiciona um elemento na pilha estatica(ultima posicao)
void StaticStack_push(StaticStack* S, int val);

//retira o ultimo elemento da pilha estatica e retorna seu valor
int StaticStack_pop(StaticStack*S);

//verifica se a pilha esta vazia e retorna True(vazia) ou False(nao vazia)
bool StaticStack_empty(const StaticStack* S);
//verifica se a pilha esta cheia e retorna True(cheia) ou False(nao cheia)
bool StaticStack_full(const StaticStack* S);

//retorna o ultimo elemento da pilha
int StaticStack_top(StaticStack* S);

//printa uma pilha estatica
void StaticStack_print(const StaticStack* S);

//retorna o tamanho da pilha
long int StaticStack_size(const StaticStack* S);

#endif
