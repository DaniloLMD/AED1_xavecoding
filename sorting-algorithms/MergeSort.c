#include <stdio.h>
#include <stdlib.h>

void printaArray(int *array, int array_size){
    for(int i = 0; i < array_size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void merge(int* array, int inicio, int meio, int fim){

    int i_right = 0, i_left = 0; //indices de controle dos arrays da direita e da esquerda
    int i_array = inicio; //indice de controle para o array original

    int size_left = meio - inicio + 1;
    int size_right = fim - meio;

    //criando um array com a parte esquerda do array original
    int* left = (int*) malloc (size_left * sizeof(int));
    for(int i = 0; i < size_left; i++){
        left[i] = array[i_array];
        i_array++;
    }

    //criando um array com a parte direita do array original
    int* right = (int*) malloc (size_right * sizeof(int));
    for(int i = 0; i < size_right; i++){
        right[i] = array[i_array];
        i_array++;
    }

    i_array = inicio;
    while(i_array <= fim){

        if(i_right >= size_right){
            array[i_array] = left[i_left++];
        }
        else if(i_left >= size_left){
            array[i_array] = right[i_right++];
        }
        else if(left[i_left] < right[i_right]){
            array[i_array] = left[i_left++];
        }
        else{
            array[i_array] = right[i_right++];
        }

        i_array++;
    }

    free(left);
    free(right);
}


//inicio e fim sao INDICES do primeiro e ultimo termos
void merge_sort(int* array, int inicio, int fim){
    if(inicio < fim){
        int meio = inicio + (fim - inicio) / 2; //igual a (fim+inicio)/2 , evitando romper a capacidade do tipo int

        merge_sort(array, inicio, meio);
        merge_sort(array, meio+1, fim);
        
        merge(array, inicio, meio, fim);
    }
}

int main(){
    int array_size = 10000000;
    int *array = (int*) malloc(array_size * sizeof(int));
    int i = 0;
    for(int c = array_size; c > 0; c--){
        array[i++] = c;
    }
    
    merge_sort(array, 0, array_size-1);

    printf("Array: "); printaArray(array, array_size);

    free(array); 

    return 0;
}
