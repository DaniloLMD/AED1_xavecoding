#include "../include/queue.h"
#include <stdio.h>

int main(){

    Queue* Q = Queue_create();

    
    Queue_enqueue(Q, 1);
    
    Queue_enqueue(Q, 2);
    
    Queue_enqueue(Q, 3);
    
    Queue_print(Q);
    Queue_dequeue(Q);
    Queue_enqueue(Q, 4);
    Queue_enqueue(Q, 5);
    Queue_dequeue(Q);
    Queue_dequeue(Q);
    Queue_print(Q);

    Queue_destroy(&Q);
    return 0;
}