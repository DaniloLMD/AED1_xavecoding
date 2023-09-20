#include "../include/static_stack.h"
#include <stdio.h>

int main(){

    StaticStack*  S = StaticStack_create(5);

    StaticStack_push(S, 1);
    StaticStack_push(S, 2);
    StaticStack_push(S, 3);
    StaticStack_push(S, 4);
    printf("\nPUSHS TERMINADOS!!!\n");
    
    StaticStack_print(S);
    StaticStack_pop(S);
    StaticStack_pop(S);
    StaticStack_pop(S);
    StaticStack_pop(S);
    printf("\n\nPOPS TERMINADOS!!!\n");
    StaticStack_print(S);

    return 0;
}