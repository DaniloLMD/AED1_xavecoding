#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H


typedef struct _static_queue StaticQueue;
typedef char bool;

//cria e retorna uma fila estatica
StaticQueue *StaticQueue_create(unsigned long int capacity);
//destroi uma fila estatica
void StaticQueue_destroy(StaticQueue **Q_ref);

//retorna True(fila vazia) ou False(fila com elementos)
bool StaticQueue_is_empty(const StaticQueue *Q);
////retorna True(fila cheia) ou False(fila ainda tem espaco)
bool StaticQueue_is_full(const StaticQueue *Q);
//retorna o tamanho da fila
unsigned long int StaticQueue_size(const StaticQueue *Q);

//adiciona o valor no final da fila
void StaticQueue_enqueue(StaticQueue *Q, int val);
//retorna o valor no inicio da fila
int StaticQueue_peek(const StaticQueue *Q);
//remove e retorna o valor no inicio da fila
int StaticQueue_dequeue(StaticQueue *Q);

//printa uma fila estatica
void StaticQueue_print(const StaticQueue *Q);

#endif