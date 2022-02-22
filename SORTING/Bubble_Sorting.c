#include <stdio.h>

int data[];
int size;

void placeholder(int a, int b){
    int tmp = data[a];
    data[a] = data[b];
    data[b] = tmp;
}

void bubble_sort(int array[],int size){
    for(int i = 1; i < size; i++){
        for(int j = size-1; j >= i; j--){
            if(array[j] < array[j-1]){
                placeholder(j,j-1);
            }
        }
    }
}

void cetak_array(int array[], int size){
    for (int i = 0; i < size; ++i){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(){

    printf("Jumlah Data : ");
    scanf("%d", &size);
    data[size];
    printf("Masukkan Data :\n");
    for ( int i = 0; i < size; i++){
        printf("%d. ", i+1);
        scanf("%d", &data[i]);
    }

    bubble_sort(data, size);
    printf("Urutan data dalam ascending: \n");
    cetak_array(data, size);

    return 0;
}