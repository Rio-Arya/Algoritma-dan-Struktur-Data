#include <stdio.h>

void tukar(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectsort(int array[],int size){
    for (int step = 0; step < size-1; step++){
        int min_index = step;
        for (int i = step+1; i < size;i++){
            if (array[i] < array[min_index]){
                min_index = i;
            }
        }
        tukar(&array[min_index], &array[step]);
    }
}

void cetak_array(int array[], int size){
    for (int i = 0; i < size; ++i){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(){
    int data[] = {23, 67, 89, 5, 45, 20, 15, 27};
    int size = sizeof(data)/sizeof(data[0]);
    selectsort(data, size);
    printf("Urutan data dalam ascending : \n");
    cetak_array(data, size);

    return 0;
}