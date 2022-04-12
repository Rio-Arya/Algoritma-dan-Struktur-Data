#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
typedef struct node node_t; //eror if not use typedef

void cetak(node_t *head){
    node_t *sementara = head;

    while (sementara != NULL){
        printf("%d - ", sementara->data);
        sementara = sementara->next;
    }
    printf("\n");
}

int main () {

    node_t n1, n2, n3;
    node_t *head;

    n1.data = 15;
    n2.data = 20;
    n3.data = 5;

    // connecting node
    head = &n3;
    n3.next = &n2;
    n2.next = &n1;
    n1.next = NULL;

    cetak(head);

    return 0;
}
