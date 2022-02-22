#include <stdio.h>

void insertsort(int array[],int size){
    int tmp;
    for(int i = 1; i < size; i++){
        tmp = array[i];
        int j = i-1;
        while(array[j] > tmp && j >= 0){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = tmp;
    }
}

void cetak_array(int array[], int size){
    for (int i = 0; i < size; ++i){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(){
    int size;
    printf("Jumlah Data : ");
    scanf("%d", &size);
    int data[size];
    printf("Masukkan Data :\n");
    for ( int i = 0; i < size; i++){
        printf("%d. ", i+1);
        scanf("%d", &data[i]);
    }

    insertsort(data, size);
    printf("Urutan data dalam ascending: \n");
    cetak_array(data, size);

    return 0;
}
