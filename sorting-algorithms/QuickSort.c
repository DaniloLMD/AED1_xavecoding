#include <stdio.h>
#include <stdlib.h>

void swap(int* v, int i1, int i2){
    int t = v[i1];
    v[i1] = v[i2];
    v[i2] = t;
}

int partition(int* v, int left, int right){
    int i = left-1;

    for(int j = left; j < right; j++){
        if(v[j] < v[right]){
            i++;
            swap(v, j, i);
        }
    }

    swap(v, i+1, right);
    return i+1;
}

void QuickSort(int* v, int left, int right){
    if(left < right){
        int pivot = partition(v, left, right);

        QuickSort(v, left, pivot-1);
        QuickSort(v, pivot+1, right);
    }
}

int main(){

    int fla = 1;

    while(fla>0){
        printf("FLAMENGO    FLAMENGO     FLAMENGO     ");
    }

    int v[] = {3, 2, 1, 4, 7, 0, -8};

    int size = sizeof(v) / sizeof(int);

    QuickSort(v, 0, size-1);

    for(int i = 0 ; i < size; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}