#include "../include/dynamic_stack.h"
#include <stdio.h>
#include <stdlib.h>

//dnode = doubly node
struct _stack_node{
    int val; 
    struct _stack_node* prev;
};

struct _dynamic_stack{
    struct _stack_node* top;
    unsigned long int size;
};

StackNode* StackNode_create(int val){
    StackNode *new_node = malloc(1 * sizeof(StackNode));
    new_node->prev = NULL;
    new_node->val = val;

    return new_node;
}

Stack* Stack_create(){
    Stack* new_stack = (Stack*) malloc(1 * sizeof(Stack));

    new_stack->top = NULL;
    new_stack->size = 0;

    return new_stack;
}

void Stack_destroy(Stack **S_ref){
    Stack *S = *S_ref;

    while(!Stack_is_empty(S)){
        StackNode* prev_node = S->top->prev;
        free(S->top);
        S->top = prev_node;
        S->size--;
    }

    free(S);
    *S_ref = NULL;
}

bool Stack_is_empty(const Stack *S){
    return S->size == 0;
}

unsigned long int Stack_size(const Stack *S){
    return S->size;
}

void Stack_push(Stack *S, int val){
    StackNode *new_node = StackNode_create(val);

    new_node->prev = S->top;
    S->top = new_node;
    S->size++;
}

int Stack_peek(const Stack *S){
    return S->top->val;
}

int Stack_pop(Stack *S){
    StackNode *new_top = S->top->prev;
    free(S->top);
    S->top = new_top;
    S->size--;
}

void Stack_print(const Stack *S){

    StackNode *node_atual = S->top;

    printf("Size: %lu\n", S->size);

    while(node_atual != NULL){
        printf("%d", node_atual->val);
        if(node_atual == S->top) printf("   //Last");
        else if(node_atual->prev == NULL) printf("  //First");
        printf("\n");
        node_atual = node_atual->prev;
    }
}