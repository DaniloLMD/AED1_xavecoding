#include "../include/static_stack.h"
#include <stdio.h>
#include <stdlib.h>

struct _static_stack{
    int* data;
    long int capacity; //quantidade de elementos que cabe na pilha estatica
    long int top; //indice do elemento do topo da pilha (max = capacity -1)
};


/****************************** funcoes de static StaticStack **************************************************/

StaticStack* StaticStack_create(long int capacity){
    if(capacity < 0){
        printf("ERROR in function 'StaticStack_create': capacity is a negative number\n");
        exit(EXIT_FAILURE);
    }

    StaticStack* new_stack = (StaticStack*) malloc(sizeof(StaticStack));

    new_stack-> capacity = capacity;
    new_stack->top = -1;
    new_stack->data = (int*) malloc(capacity * sizeof(int));
}

void StaticStack_destroy(StaticStack** S_ref){
    StaticStack* S = *S_ref;

    free(S->data);
    free(S);
    *S_ref = NULL;
}

void StaticStack_push(StaticStack* S, int val){
    if(S->top == S->capacity -1){
        printf("ERROR in function 'StaticStack_push': stack is full\n");
        exit(EXIT_FAILURE);
    }

    S->data[++S->top] = val;
}

int StaticStack_pop(StaticStack*S){
    int val_top = S->data[S->top];
    S->top--;
    return val_top;
}

bool StaticStack_full(const StaticStack* S){
    return S->top == S->capacity -1;
}

bool StaticStack_empty(const StaticStack* S){
    return S->top == -1;
}

int StaticStack_top(StaticStack* S){
    return S->data[S->top];
}

void StaticStack_print(const StaticStack* S){
    if(S == NULL){
        printf("Stack haven't been created yet\n");
        return;
    }

    printf("Capacity : %ld\n", S->capacity);
    printf("Top = %ld\n", S->top);
    printf("Stack: ");
    if(!StaticStack_empty(S)){
        for(int c = 0; c < S->top; c++){
            printf("%d -> ", S->data[c]);
        }
        printf("Top val = %d\n", S->data[S->top]);
    }
    else printf("EMPTY\n");
}

long int StaticStack_size(const StaticStack* S){
    return S->capacity;
}

