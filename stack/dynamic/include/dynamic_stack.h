#ifndef STACK_H
#define STACK_H

typedef struct _dynamic_stack Stack;
typedef struct _stack_node StackNode;
typedef char bool;

//cria um nó de pilha dinamica
StackNode* StackNode_create(int val);

//cria e retorna uma pilha dinamica
Stack* Stack_create();

//destroi uma pilha dinamica
void Stack_destroy(Stack **S_ref);

//retorna True(pilha vazia) ou False(pilha tem elementos)
bool Stack_is_empty(const Stack *S);

//retorna a quantidade de elementos na pilha
unsigned long int Stack_size(const Stack *S);

//adiciona o valor "val" no topo da pilha
void Stack_push(Stack *S, int val);

//retorna o valor do topo da pilha
int Stack_peek(const Stack *S);

//remove o elemento do topo da pilha e retorna seu valor
int Stack_pop(Stack *S);

//printa uma pilha
void Stack_print(const Stack *S);

#endif
