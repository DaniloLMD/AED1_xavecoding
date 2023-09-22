#include "../include/dynamic_stack.h"
#include <stdio.h>

int main(){

    Stack* s = Stack_create();

    Stack_print(s);

    Stack_push(s, 1);
    Stack_push(s, 2);
    Stack_push(s, 3);
    Stack_push(s, 0);
    Stack_pop(s);
    Stack_print(s);

    Stack_push(s, 351);

    printf("Topo = %d\n", Stack_peek(s));

    return 0;
}