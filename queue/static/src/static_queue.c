#include "../include/static_queue.h"
#include <stdio.h>
#include <stdlib.h>

struct _static_queue{
    int* data;
    unsigned long int capacity;
    unsigned long int size;
    unsigned long int begin;
    unsigned long int end;
};

StaticQueue *StaticQueue_create(unsigned long int capacity){
    StaticQueue* new_StaticQueue = (StaticQueue*) malloc(1 * sizeof(StaticQueue));
    new_StaticQueue->capacity = capacity;
    new_StaticQueue->size = 0;
    new_StaticQueue->begin = 0;
    new_StaticQueue->end = 0;
    new_StaticQueue->data = (int*) malloc(capacity * sizeof(int));

    return new_StaticQueue;
}

void StaticQueue_destroy(StaticQueue **Q_ref){
    StaticQueue* Q = *Q_ref;

    free(Q->data);
    free(Q);
    *Q_ref = NULL;
}

bool StaticQueue_is_empty(const StaticQueue *Q){
    return Q->size == 0;
}

bool StaticQueue_is_full(const StaticQueue *Q){
    return Q->size == Q->capacity;
}

unsigned long int StaticQueue_size(const StaticQueue *Q){
    return Q->size;
}

void StaticQueue_enqueue(StaticQueue *Q, int val){

    //tratando o erro de a fila estar cheia
    if(StaticQueue_is_full(Q)){
        printf("ERROR in function 'StaticQueue_enqueue': queue is full");
        exit(EXIT_FAILURE);
    }

    Q->data[Q->end] = val;
    Q->end = (Q->end+1) % Q->capacity;
    Q->size++;
}

int StaticQueue_peek(const StaticQueue *Q){
    if(StaticQueue_is_empty(Q)){
        printf("ERROR in function 'StaticQueue_peek': queue empty");
        exit(EXIT_FAILURE);
    }

    return Q->data[Q->begin];
}

int StaticQueue_dequeue(StaticQueue *Q){
    int front_val = Q->data[Q->begin];
    Q->size--;
    Q->begin = (Q->begin+1) % Q->capacity;
    return front_val;
}

void StaticQueue_print(const StaticQueue *Q){
    int i_data = Q->begin;

    printf("Q = [%lu / %lu]\n", Q->size, Q->capacity);
    for(int i = 0; i < Q->size; i++){
        printf("%d ", Q->data[i_data]);
        i_data = (i_data + 1) % Q->capacity;
    }
    printf("\n");
}
