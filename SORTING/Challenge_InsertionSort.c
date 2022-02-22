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
    int data[] = {23, 67, 89, 5, 45, 20, 15, 27};
    int size = sizeof(data)/sizeof(data[0]);
    insertsort(data, size);
    printf("Urutan data dalam ascending: \n");
    cetak_array(data, size);

    return 0;
    
}