#include "../include/doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

struct _doubly_node{
    int val; 
    struct _doubly_node* next;
    struct _doubly_node* prev;
};

struct _doubly_linked_list{
    struct _doubly_node* begin;
    struct _doubly_node* end;
    unsigned long int size;
};

DNode* DNode_create(int val){
    DNode* new_node = (DNode*) malloc(1 * sizeof(DNode));

    new_node->val = val;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

LinkedList* LinkedList_create(void){
    LinkedList* new_list = (LinkedList*) malloc(1 * sizeof(LinkedList));

    new_list->size = 0;
    new_list->begin = NULL;
    new_list->end = NULL;

    return new_list;
}

void LinkedList_destroy(LinkedList** L_ref){
    LinkedList* L = *L_ref;

    DNode* node_atual = L->begin;
    DNode* node_anterior = NULL;
    while(node_atual != NULL){
        node_anterior = node_atual;
        node_atual = node_atual->next;
        free(node_anterior);
    }

    free(L);
    *L_ref = NULL;
}


void LinkedList_addFirst(LinkedList* L, int val){
    DNode* new_node = DNode_create(val);

    new_node->next = L->begin;
    if(LinkedList_empty(L)){
        L->end = new_node;
    }
    else{
        L->begin->prev = new_node;
    }

    L->begin = new_node;
    L->size++;
}

void LinkedList_addLast(LinkedList* L, int val){
    DNode* new_node = DNode_create(val);

    new_node->prev = L->end;
    if(LinkedList_empty(L)){
        L->begin = new_node;
    }
    else{
        L->end->next = new_node;
    }

    L->end = new_node;
    L->size++;
}

void LinkedList_addAt(LinkedList* L, int val, unsigned long int index){

    //verificando se o index informado é valido
    if(index < 0){
        printf("ERROR in function 'LinkedList_addAt': index out of range - negative value\n");
        exit(EXIT_FAILURE);
    }
    else if(index > L->size){
        printf("ERROR in function 'LinkedList_addAt': index out of range - higher than list size\n");
        exit(EXIT_FAILURE);   
    }

    int i_atual = 0;
    DNode* new_node = DNode_create(val);
    DNode* node_atual = L->begin;

    //tratando os casos de a lista estar vazia, inserir na primeira posicao ou inserir na ultima posicao
    if(index == 0){
        LinkedList_addFirst(L, val);
        return;
    }
    else if(index == L->size){
        LinkedList_addLast(L, val);
        return;
        }

    while(1){
        if(i_atual == index){

            new_node->prev = node_atual->prev;

            new_node->next = node_atual;

            node_atual->prev->next = new_node;

            node_atual->prev = new_node;

            L->size++;

            return;
        }
        node_atual = node_atual->next;
        i_atual++;
    }

}

//1 <-> 2 <-> 3

void LinkedList_addSorted(LinkedList* L, int val){

    //tratando caso da lista estar vazia
    if(LinkedList_empty(L)){
        LinkedList_addFirst(L, val);
        return;
    }

    unsigned long int i_atual = 0;
    DNode* new_node = DNode_create(val);
    DNode* node_atual = L->begin;

    while(node_atual != NULL){
        if(new_node->val <= node_atual->val){
            LinkedList_addAt(L, val, i_atual);
            return;
        }
        node_atual = node_atual->next;
        i_atual++;
    }
    LinkedList_addLast(L, val);

}

void LinkedList_removeFirstValue(LinkedList* L, int val){

    DNode *node_atual = L->begin;
    DNode *node_to_be_deleted = NULL;

    while(node_atual != NULL){
        if(node_atual->val == val){

            node_to_be_deleted = node_atual;

            //lista tem apenas um elemento
            if(L->begin == L->end){
                L->begin = L->end = NULL;
            }
            //remover o elemento inicial
            else if(node_atual == L->begin){
                L->begin->next->prev = NULL;
                L->begin = node_atual->next;
            }
            //remover o ultimo elemento
            else if(node_atual == L->end){
                L->end->prev->next = NULL;
                L->end = node_atual->prev;
            }
            //remover um elemento no meio
            else{
                node_atual->prev->next = node_atual->next;
                node_atual->next->prev = node_atual->prev;
            }

            free(node_to_be_deleted);
            L->size--;

            return;
        }
        node_atual = node_atual->next;
    }
}

void LinkedList_removeAllValues(LinkedList* L, int val){
    DNode* node_atual = L->begin;
    DNode* node_to_be_removed = NULL;

    while(node_atual != NULL){
        if(node_atual->val == val){

            node_to_be_removed = node_atual;

            if(node_atual == L->begin){
                L->begin = L->begin->next;
            }else{
                node_atual->prev->next = node_atual->next;
            }

            if(node_atual == L->end){
                L->end = L->end->prev;
            }else{
                node_atual->next->prev = node_atual->prev;
            }

            node_atual = node_atual->next;

            free(node_to_be_removed);

            L->size--;
        }
        else{
            node_atual = node_atual->next;
        }
    }
}

void LinkedList_removeAt(LinkedList* L, unsigned long int i){

    if(i < 0 || i >= L->size){
        printf("ERROR in function 'LinkedList_removeAt': invalid index\n");
        exit(EXIT_FAILURE);
    }

    unsigned long int i_atual = 0;
    DNode *node_atual = L->begin;
    while(1){
        if(i_atual == i){

            //atualizando o inicio da lista
            if(node_atual == L->begin){
                L->begin = L->begin->next;

                if(L->begin != NULL){
                    L->begin->prev = NULL;
                }
            }

            //atualizando o fim da lista
            if(node_atual == L->end){
                L->end = L->end->prev;

                if(L->end != NULL){
                    L->end->next = NULL;
                }

            }
            //atualizando o meio da lista e fazendo a verificacao novamente de que nao esta no inicio
            else if (i_atual != 0){
                node_atual->prev->next = node_atual->next;
                node_atual->next->prev = node_atual->prev;
            }

            free(node_atual);
            L->size--;

            return;
        }
        i_atual++;
        node_atual = node_atual->next;
    }
}

void LinkedList_removeAll(LinkedList*L){
    DNode* node_atual = L->begin;

    while(node_atual != NULL){
        if(L->size == 1 || node_atual == L->end){
            free(node_atual);
            node_atual = NULL;
        }
        else{
            node_atual = node_atual->next;
            free(node_atual->prev);
        }
    }
    L->size = 0;
    L->begin = L->end = NULL;
}

bool LinkedList_empty(LinkedList* L){
    return L->size == 0;
}


int LinkedList_front(LinkedList* L){
    if(LinkedList_empty(L)){
        printf("ERROR in function 'LinkedList_front': list is empty\n");
        exit(EXIT_FAILURE);
    }

    return L->begin->val;
}

int LinkedList_back(LinkedList* L){
    if(LinkedList_empty(L)){
        printf("ERROR in function 'LinkedList_back': list is empty\n");
        exit(EXIT_FAILURE);
    }

    return L->end->val;
}

int LinkedList_at(LinkedList* L, long unsigned int index){

    if(index < 0 || index >= L->size){
        printf("ERROR in function 'LinkedList_at': invalid index\n");
        exit(EXIT_FAILURE);
    }

    long unsigned int i_atual = 0;
    DNode *node_atual = L->begin;

    while(1){
        if(i_atual == index){
            return node_atual->val;
        }
        i_atual++;
        node_atual = node_atual->next;
    }
}

void LinkedList_print(const LinkedList* L){

    if(L == NULL){
        printf("ERROR in function 'LinkedList_print': list does not exist\n");
        exit(EXIT_FAILURE);
    }

    DNode *node_atual = L->begin;
    printf("Size: %lu\n", L->size);
    printf("L = ");
    while(node_atual != NULL){
        if(L->begin == L->end){ 
            printf("NULL <- %d -> NULL", node_atual->val);
            break;
        }

        
        if(node_atual == L->begin){
            //printf("\n##############   ");
            printf("NULL <- %d", node_atual->val);
        }
        else if(node_atual == L->end){
            //("\n@@@@@@@@@@@@@@   ");
            printf(" <-> %d -> NULL", node_atual->val);
        }
        else{
            //printf("\n$$$$$$$$$$$$$$   ");
            printf(" <-> %d", node_atual->val);
        }  

        node_atual = node_atual->next;

    }
    printf("\n");
}

unsigned long int LinkedList_size(const LinkedList* L){
    return L->size;
}

void LinkedList_reverse(LinkedList* L){

    DNode *node_atual = L->begin;
    DNode *node_anterior = NULL;
    DNode *prev_aux = NULL;

    while(node_atual != NULL){

        node_anterior = node_atual;
        node_atual = node_atual->next;

        prev_aux = node_anterior->prev;
        //invertendo o next e o prev
        node_anterior->prev = node_anterior->next;
        node_anterior->next = prev_aux;

    }

    //invertendo o end e o begin
    node_atual = L->begin;
    L->begin = L->end;
    L->end = node_atual;

}

void LinkedList_concat(LinkedList* L1, LinkedList* L2){

    if(LinkedList_empty(L1)){
        L1 = L2;
    }

    else if(LinkedList_empty(L2)) return;

    else{
        L1->end->next = L2->begin;
        L2->begin->prev = L1->end;
        L1->end = L2->end;
        L1->size += L2->size;
    }
}

void LinkedList_Sort(LinkedList** L_adress){

    LinkedList*L = *L_adress;
    //tratando casos da lista estar vazia
    if(LinkedList_empty(L)) return;

    LinkedList* L_sorted = LinkedList_create();

    DNode* node_atual;
    int i_atual, i_maior, maior_val;

    while(L->size > 0){

        maior_val = L->begin->val;
        i_maior = 0;

        node_atual = L->begin->next;
        i_atual = 1;

        while(node_atual != NULL){

            if(node_atual->val > maior_val){
                maior_val = node_atual->val;
                i_maior = i_atual;
            }

            node_atual = node_atual->next;
            i_atual++;
        }

        LinkedList_addFirst(L_sorted, maior_val);
        LinkedList_removeAt(L, i_maior);
    }

    free(L);
    *L_adress = L_sorted;
}