#include "../include/linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    LinkedList* L = LinkedList_create();
    
    LinkedList_print(L); //printa a lista

    LinkedList_addFirst(L, 2);  //adiciona o valor 2 no inicio da lista
    LinkedList_addFirst(L, 5); //adiciona o valor 5 no inicio da lista
    
    LinkedList_addLast(L, 0); //adiciona o valor 0 no fim da lista
    LinkedList_addLast(L, 3); //adiciona o valor 3 no fim da lista
    LinkedList_addLast(L, 7); //adiciona o valor 7 no fim da lista

    LinkedList_addAt(L, 4, 2); //adiciona o valor 4 no indice 2
    LinkedList_addAt(L, 8, 0); //adiciona o valor 8 no indice 0

    LinkedList_Sort(&L); //ordena a lista

    LinkedList_addSorted(L, 1); //adiciona o valor 1 na lista de modo ordenado
    LinkedList_addSorted(L, 6); //adiciona o valor 6 na lista de modo ordenado
    LinkedList_addSorted(L, 9); //adiciona o valor 9 na lista de modo ordenado


    LinkedList_print(L); //printa a lista

    LinkedList_reverse(L); //inverte a lista
    
    LinkedList_print(L); //printa a lista

    LinkedList_destroy(&L); //destroi a lista

    return 0;
}