#ifndef QUEUE_H
#define QUEUE_H

typedef struct _queue Queue;
typedef struct _node Node;
typedef char bool;

//cria e retorna uma fila dinamica
Queue *Queue_create();
//destroi uma fila
void Queue_destroy(Queue **Q_ref);

//retorna True(fila vazia) ou False(fila nao vazia)
bool Queue_is_empty(const Queue *Q);
//retorna o tamanho da fila
unsigned long int Queue_size(const Queue *Q);

//adiciona o valor no final da fila
void Queue_enqueue(Queue *Q, int val);
//retorna o valor no inicio da fila
int Queue_peek(const Queue *Q);
//remove o valor no inicio da fila
int Queue_dequeue(Queue *Q);

//printa uma fila
void Queue_print(const Queue *Q);

#endif