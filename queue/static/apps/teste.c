#include "../include/static_queue.h"
#include <stdio.h>

int main(){

    StaticQueue* Q = StaticQueue_create(5);
    StaticQueue_enqueue(Q, 1);
    StaticQueue_enqueue(Q, 2);
    StaticQueue_enqueue(Q, 3);
    StaticQueue_print(Q);
    StaticQueue_dequeue(Q);
    StaticQueue_print(Q);
    StaticQueue_enqueue(Q, 4);
    StaticQueue_dequeue(Q);
    StaticQueue_enqueue(Q, 5);
    StaticQueue_dequeue(Q);
    StaticQueue_print(Q);

    StaticQueue_destroy(&Q);
    return 0;
}