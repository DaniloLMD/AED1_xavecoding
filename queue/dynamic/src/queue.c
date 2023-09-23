#include "../include/queue.h"
#include <stdio.h>
#include <stdlib.h>

struct _node{
    int val; 
    struct _node* next;
};

struct _queue{
    struct _node* begin;
    struct _node* end;
    unsigned long int size;
};

Node* QueueNode_create(int val){
    Node* new_node = (Node*) malloc(1 * sizeof(Node));
    new_node->val = val;
    new_node->next = NULL;
}

Queue *Queue_create(){
    Queue* new_queue = (Queue*) malloc(1 * sizeof(Queue));

    new_queue->begin = NULL;
    new_queue->end = NULL;
    new_queue->size = 0;

    return new_queue;
}
void Queue_destroy(Queue **Q_ref){
    Queue* Q = *Q_ref;

    Node* prev = NULL;
    Node* pos = Q->begin;

    while(pos != NULL){
        prev = pos;
        pos = pos->next;
        free(prev);
    }

    free(Q);
    *Q_ref = NULL;  
}

bool Queue_is_empty(const Queue *Q){
    return Q->size == 0;
}

unsigned long int Queue_size(const Queue *Q){
    return Q->size;
}

void Queue_enqueue(Queue *Q, int val){
    Node* new_node = QueueNode_create(val);
    //vazia
    if(Queue_is_empty(Q)){
        Q->begin = Q->end = new_node;
    }
    //ja tem elementos
    else{
        Q->end->next = new_node;
        Q->end = new_node;
    }
    Q->size++;
}

int Queue_peek(const Queue *Q){
    if(Queue_is_empty(Q)){
        printf("ERROR in function 'Queue_peek': queue is empty\n");
        exit(EXIT_FAILURE);
    }

    return Q->begin->val;
}
int Queue_dequeue(Queue *Q){

    if(Queue_is_empty(Q)){
        printf("ERROR in function 'Queue_dequeue': queue is empty\n");
        exit(EXIT_FAILURE);
    }

    Node* front_node = Q->begin;
    int front_val = front_node->val;

    Q->begin = front_node->next;
    free(front_node);
    Q->size--;
    return front_val;
}

void Queue_print(const Queue *Q){
    printf("Size: %lu\n", Q->size);

    Node* node_atual = Q->begin;

    while(node_atual != NULL){
        printf("%d ", node_atual->val);
        fflush(stdout);
        node_atual = node_atual->next;
    }
    printf("\n");
}