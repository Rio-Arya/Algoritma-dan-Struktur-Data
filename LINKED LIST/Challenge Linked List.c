ines (175 sloc)  4.88 KB

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
    int data;
    struct node* next;
};
struct node *head;

void awal(){
    struct node *ptr;
    int item;

    ptr = (struct node *) malloc (sizeof(struct node *));
    if (ptr == NULL){
        printf("Overflow!");
    } else {
        printf("masukkan data: "); scanf("%d", &item);
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("data berhasil disimpan di node awal");
    }
}

void akhir(){
    struct node *ptr, *temp;
    int item;

    ptr = (struct node *) malloc (sizeof(struct node *));
    if (ptr == NULL){
        printf("Overflow!");
    } else {
        printf("masukkan data: "); scanf("%d", &item);
        ptr->data = item;
        if (head == NULL){
            ptr->next = NULL;
            head = ptr;
            printf("berhasil simpan node!");
        } else {
            temp = head;
            while (temp->next != NULL){
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("berhasil simpan node diakhir");
        }
    }
}

void sembarang(){
    struct node *ptr, *temp;
    int item, loc;

    ptr = (struct node *) malloc (sizeof(struct node *));
    if (ptr == NULL){
        printf("Overflow!");
    } else {
        printf("masukkan data: "); scanf("%d", &item);
        ptr->data = item;
        printf("mau simpan di lokasi berapa? "); scanf("%d", &loc);
        temp = head;
        for (int i = 0; i < loc; i++){
            temp = temp->next;
            if (temp == NULL){
                printf("tidak dapat menyimpan data!\n");
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("node berhasil disimpan\n");
    }
}

void cetak(){
    struct node *ptr;
    ptr = head;
    if (ptr  == NULL){
        printf("list kosong bosque\n");
    } else {
        printf("cetak isi list...");
        while(ptr != NULL){
            printf("\n %d \n", ptr->data);
            ptr = ptr->next;
        }
    }
}

void hapusAwal(){
    struct node *ptr;
    if (head == NULL){
        printf("\nList kosong bro!\n");
    } else {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\nNODE awal berhasil dihapus!\n");
    }
}

void hapusAkhir(){
    struct node *temp, *tail;
    if (head == NULL){
        printf("\nList kosong bro!\n");
    } else {
        if (head->next == NULL){
            free(head);
            head = NULL;
        } else {
            temp = head;
            while (temp->next != NULL){
                if (temp->next->next == NULL){
                    tail = temp->next;
                    break;
                }
                temp = temp->next;
            }

            // printf("%d ", *tail); // untuk cek nilai seng di ambil
            free(tail);
            temp->next = NULL;
        }
        printf("\nNODE awal berhasil dihapus!\n");
        /*
            temp->next->next == 2 data dari belakang
            tail == data terakhir yang bakal dihapus
            temp->next = NULL == data terakhir di NULL kan
        */
    }
}


void hapusSembarang(){
    struct node *temp;
    int loc, i = 0;

    if (head == NULL){
        printf("\nList kosong bro!\n");
    } else {
        printf("lokasi berapa yang mau dihapus? (0-ndata) "); scanf("%d", &loc);

        temp = head;
        while (i != loc){
            if (i+1 == loc){
                break;
            }
            temp = temp->next;
            i++;
        }

        struct node *next = temp->next->next;
        free(temp->next);
        temp->next = next; // nak ga pake struct next atau langsung di isi temp->next->next ga bisa

        printf("node berhasil dihapus\n");
    }
}

int main(){

    int pilihan = 0;
    while (pilihan != 8){
        system("cls");
        printf("***** Menu latihan linked list *****");
        printf("\n====================================");
        printf("\n1. lihat data dalam linked list\n2. input data dari awal\n3. input data dari akhir\n4. input data sembarang\n5. Hapus data Awal\n6. Hapus Data Akhir\n7. Hapus Data Sembarang\n8. Keluar");
        printf("\npilihanmu? "); scanf("%d", &pilihan); printf("\n");

        system("cls");
        switch(pilihan){
            case 1:
                cetak(); getch(); break;
            case 2:
                awal(); getch(); break;
            case 3:
                akhir(); getch(); break;
            case 4:
                sembarang(); getch(); break;
            case 5:
                hapusAwal(); getch(); break;
            case 6:
                hapusAkhir(); getch(); break;
            case 7:
                hapusSembarang(); getch(); break;
            case 8:
                exit(0);
            default:
                printf("masukkan pilihan yang benar!"); getch();
        }
    }

    return 0;
