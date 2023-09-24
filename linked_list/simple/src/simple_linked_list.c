#include "../include/simple_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

struct _snode{
    int val; 
    struct _snode* next;
};

struct _linked_list{
    struct _snode* begin;
    struct _snode* end;
    unsigned long int size;
};

/******************************** funcoes de node *******************************************************/

SNode* SNode_create(int val){
    SNode* n = (SNode*) calloc(1, sizeof(SNode));
    n->next = NULL;
    n->val = val;

    return n;
}


/****************************** funcoes de linked list **************************************************/

LinkedList* SimpleLinkedList_create(void){
    LinkedList* L = (LinkedList*) malloc(1 * sizeof(LinkedList));
    L->begin = L->end = NULL;
    L->size = 0;

    return L;
}

void SimpleLinkedList_destroy(LinkedList** L){
    SNode *pos = (*L)->begin, *pre = NULL;

    while(pos != NULL){
        pre = pos;
        pos = pos->next;
        free(pre);
    }
    free(*L);
    *L = NULL;
}  


void SimpleLinkedList_addFirst(LinkedList* L, int val){
    SNode* new_node = SNode_create(val);
    new_node->next = L->begin;   

    if(SimpleLinkedList_empty(L)) L->end = new_node;
    L->begin = new_node;

    L->size++;
}

void SimpleLinkedList_addLast(LinkedList* L, int val){
    SNode* new_node = SNode_create(val);
    if(SimpleLinkedList_empty(L)){
        L->begin = L->end = new_node;
    }
    else{
        L->end->next = new_node;
        L->end = new_node;
    }

    L->size++;
}

void SimpleLinkedList_addAt(LinkedList* L, int val, int index){
    int i = 0;
    SNode* new_node = SNode_create(val), *pos = L->begin, *pre = NULL;

    //verificando se o index informado é valido
    if(index < 0){
        printf("ERROR in function 'SimpleLinkedList_addAt': index out of range - negative value\n");
        exit(EXIT_FAILURE);
    }
    else if(index > L->size){
        printf("ERROR in function 'SimpleLinkedList_addAt': index out of range - higher than list size\n");
        exit(EXIT_FAILURE);   
    }

    while(1){
        if(i == index){

            //verificando se vai inserir no final da lista
            if(index == L->size){
                SimpleLinkedList_addLast(L, val);
            }
            
            else{
                new_node->next = pos;

                if(index == 0) L->begin = new_node;
                else pre->next = new_node;

                L->size++;
            }

            return;
        }
        pre = pos;
        pos = pos->next;
        i++;
    }

}

void SimpleLinkedList_addSorted(LinkedList* L, int val){

    if(SimpleLinkedList_empty(L)){
        SimpleLinkedList_addFirst(L, val);
        return;
    }

    int i_atual = 0;
    SNode* node_atual = L->begin, *prev = NULL;

    while(node_atual != NULL){

        if(node_atual->val > val){
            SimpleLinkedList_addAt(L, val, i_atual);
            return;
        }
        
        prev = node_atual;
        node_atual = node_atual->next;
        i_atual++;
    }

    SimpleLinkedList_addLast(L, val);
}

void SimpleLinkedList_removeFirstValue(LinkedList* L, int val){

    //pos = ponteiro da frente, pre = ponteiro de tras
    SNode *pos = L->begin, *pre = NULL;

    //avancando pos e pre ate achar o valor
    while(pos != NULL && pos->val != val){
        pre = pos;
        pos = pos->next;
    }

    //verificando se tem ao menos um valor na lista
    if(pos != NULL){     

        //verificando se o valor é o ultimo elemento da lista
        if(L->end == pos){
            L->end = pre;
        }

        //verificando se o valor é o primeiro elemento da lista
        if(L->begin == pos){
            L->begin = pos->next;
        }
        else{  
            pre->next = pos->next;
        }

        free(pos);
        L->size--;
    }
}

void SimpleLinkedList_removeAllValues(LinkedList* L, int val){
    SNode *pre = NULL, *pos = L->begin, *aux_para_free;

    while(pos != NULL){

        //verificando se o nó tem o mesmo valor
        if(pos->val == val){


            //verificando se o nó é o ultimo
            if(L->end == pos){
                L->end = pre;
            }

            //verificando se o nó é o primeiro
            if(L->begin == pos){
                L->begin = pos->next;
            }
            //verificando se o nó esta no meio
            else{
                pre->next = pos->next;
            }

            aux_para_free = pos;
            pos = pos->next;
            free(aux_para_free);
            aux_para_free = NULL;

            L->size--;
        }
        //caso o valor do nó atual nao seja o valor informado, avança os ponteiros em uma posicao
        else{
            pre = pos;
            pos = pos->next;
        }
    }
}

void SimpleLinkedList_removeAt(LinkedList* L, int i){
    int i_atual = 0;
    SNode *pos = L->begin, *pre = NULL;

    //verificando se o index informado é valido
    if(i < 0){
        printf("ERROR in function 'SimpleLinkedList_removeAt': index out of range - negative value\n");
        exit(EXIT_FAILURE);
    }
    else if(i >= L->size){
        printf("ERROR in function 'SimpleLinkedList_removeAt': index out of range - higher than list size\n");
        exit(EXIT_FAILURE);
    }

    while(pos != NULL){

        if(i_atual == i){ 
            
            //verificando se o nó esta no final
            if(pos == L->end){
                L->end = pre;
            }

            //verificando se o nó esta no inicio
            if(pos == L->begin){
                L->begin = pos->next;
            }
            //verificando se o nó está no meio
            else{
                pre->next = pos->next;
            }

            free(pos);
            L->size--;

            return;
        }

        pre = pos;
        pos = pos->next;
        i_atual++;
    }

}

void SimpleLinkedList_removeAll(LinkedList*L){
    SNode *pre = NULL, *pos = L->begin;

    while(pos != NULL){

        free(pre);

        pre = pos;
        pos = pos->next;
    }

    L->begin = L->end = NULL;
    L->size = 0;
}

char SimpleLinkedList_empty(LinkedList* L){
    return L->size == 0;
}


int SimpleLinkedList_front(LinkedList* L){
    if(SimpleLinkedList_empty(L)){
        printf("ERROR in function 'SimpleLinkedList_front': list is empty\n");
        exit(EXIT_FAILURE);
    }
    return L->end->val;
}

int SimpleLinkedList_back(LinkedList* L){
    if(SimpleLinkedList_empty(L)){
        printf("ERROR in function 'SimpleLinkedList_back': list is empty\n");
        exit(EXIT_FAILURE);
    }
    SNode*p = L->end;
    return p->val;
}

int SimpleLinkedList_at(LinkedList* L, int index){

    if(SimpleLinkedList_empty(L)){
            printf("ERROR in function 'SimpleLinkedList_at': list is empty\n");
            exit(EXIT_FAILURE);
    }
    else if(index < 0){
        printf("ERROR in function 'SimpleLinkedList_at: invalid index - negative value\n");
        exit(EXIT_FAILURE);
    }
    else if(index >= L->size){
        printf("ERROR in function 'SimpleLinkedList_at: invalid index - higher than list size\n");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    SNode* node_atual = L->begin;

    while(1){

        if(i == index){
            return node_atual->val;
        }

        i++;
        node_atual = node_atual->next;
    }

}


void SimpleLinkedList_print(const LinkedList* L){

    if(L == NULL){
        printf("ERROR in function 'SimpleLinkedList_print': list does not exist\n");
        printf("List = NULL. Use SimpleLinkedList_create() to initialize\n");
        exit(EXIT_FAILURE);
    }

    SNode *p = L->begin;
    //sleep(2);
    printf("L -> ");

    while(p != NULL){
        printf("%d -> ", p->val);
        fflush(stdout);

        p = p->next;
    }
    printf("NULL\n");
    printf("Tamanho: %lu\n", L->size);
    printf("L->begin = %p\n", L->begin);
    printf("L->end = %p\n", L->end);
    if(L->size >= 1){
        printf("First val = %d\n", L->begin->val);
        printf("Last val = %d\n", L->end->val);
    }
    printf("\n");
}

unsigned long int SimpleLinkedList_size(const LinkedList* L){
    return L->size;
}

void SimpleLinkedList_reverse(LinkedList* L){
    SNode* tras = NULL, *meio = L->begin, *frente = NULL;

    if(SimpleLinkedList_empty(L)){
        printf("ERROR in function 'SimpleLinkedList_reverse': list is empty\n");
        exit(EXIT_FAILURE);
    }

    if(L->size > 1) frente = L->begin->next;

    while(meio != NULL){

        meio->next = tras;

        tras = meio;
        meio = frente;
        if(frente != NULL) frente = frente->next;
    }

    //trocando o fim e o inicio da lista
    tras = L->begin;
    L->begin = L->end;
    L->end = tras;

}

void SimpleLinkedList_concat(LinkedList* L1, LinkedList* L2){
    if(SimpleLinkedList_empty(L2)) return;
    if(SimpleLinkedList_empty(L1)){
        L1 = L2;
    }
    else{
        L1->end->next = L2->begin;
    }
    L1->end = L2->end;
    L1->size += L2->size;
}

//retorna o indice do maior valor de umam lista
int SimpleLinkedList_max(LinkedList* L){

    if(SimpleLinkedList_empty(L)){
        printf("ERROR in function 'SimpleLinkedList_max': list is empty\n");
        exit(EXIT_FAILURE);
    }

    int max = L->begin->val, index_max = 0, index_atual = 0;
    SNode* node_atual = L->begin;

    while(node_atual != NULL){
        if(node_atual->val > max){
            max = node_atual->val;
            index_max = index_atual;
        }

        node_atual = node_atual->next;
        index_atual++;
    }

    return index_max;

} 
void SimpleLinkedList_Sort(LinkedList** L_adress){
    LinkedList* L = *L_adress;

    //verificando se a lista esta vazia
    if(L->size <= 1) return;

    LinkedList* L_ordenada = SimpleLinkedList_create();
    int index_max;

    while(L->size > 0){
        index_max = SimpleLinkedList_max(L);
        SimpleLinkedList_addFirst(L_ordenada, SimpleLinkedList_at(L, index_max));
        SimpleLinkedList_removeAt(L, index_max);
    }

    SimpleLinkedList_destroy(L_adress);

    *L_adress = L_ordenada;
}
