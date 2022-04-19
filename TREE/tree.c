#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node{
      int data;
      struct Node *kiri;
      struct Node *kanan;
};

void tambah(struct Node **root, int dataku){
      if((*root) == NULL){
            struct Node *baru;
            // baru = new Node;  // 'new' doesn't exist in C
            baru = (struct Node*)malloc(sizeof(struct Node)); // Solution for 'new'
            baru->data = dataku;
            baru->kiri = NULL;
            baru->kanan = NULL;
            (*root) = baru;
            (*root)->kiri = NULL;
            (*root)->kanan = NULL;
            printf("Data bertambah!");
      }
      //jika data yang akan dimasukkan lebih kecil daripada elemen root, maka akan diletakkan di node sebelah kiri.
      else if(dataku<(*root)->data){
            tambah(&(*root)->kiri, dataku);
      }
     //jika data yang akan dimasukkan lebih besar daripada elemen root, maka akan diletakkan di node sebelah kanan
      else if(dataku>(*root)->data){
            tambah(&(*root)->kanan, dataku);
      }
     //jika saat dicek data yang akan dimasukkan memiliki nilai yang sama dengan data pada root
      else if(dataku == (*root)->data){
            printf("Data sudah ada!");
      }
}

void preOrder(struct Node *root){ //Root Left Right
      if(root != NULL){
            printf("%d ", root->data);
            preOrder(root->kiri);
            preOrder(root->kanan);
      }
}

void inOrder(struct Node *root){ //Left Root Right
      if(root != NULL){
            inOrder(root->kiri);
            printf("%d ", root->data);
            inOrder(root->kanan);
      }
}

void postOrder(struct Node *root){ //Left Right Root
      if(root != NULL){
            postOrder(root->kiri);
            postOrder(root->kanan);
            printf("%d ", root->data);
      }
}

void search(struct Node **root, int data){ // BST
	if((*root)!=NULL){
		if(data<(*root)->data){
			search(&(*root)->kiri,data);
		}else if(data>(*root)->data){
			search(&(*root)->kanan,data);
		}else{
			printf("Found : %d", (*root)->data);
		}
	}else{
		printf("Not Found.");
	}
}

void hapus(struct Node **root, int data) {
	if(data == (*root)->data) { //data ada di root?
		if((*root)->kanan == NULL) { //jika anak kanan null maka
			*root = (*root)->kiri; //isi data dengan anak kiri, namun apabila anak kiri ternyata null?
		}else if((*root)->kiri == NULL) {
			*root = (*root)->kanan;
		}else {
		      struct Node **successor = &(*root)->kiri;
			(*root)->data = (*successor)->data;
			hapus(successor, (*successor)->data);
		}
      }else if(data < (*root)->data) {
		hapus(&(*root)->kiri, data);
      }else {
		hapus(&(*root)->kanan, data);
      }
}

int main(){
      int pil, data;
      struct Node *tree;
      tree = NULL;

      do{
            system("cls"); //bersihkan layar
            printf("\tPROGRAM TREE Bahasa C");
            printf("\n\t=====================");
            printf("\nMENU\n");
            printf("1. Input Data\n");
            printf("2. Lihat pre-order\n");
            printf("3. Lihat in-order\n");
            printf("4. Lihat post-order\n");
            printf("5. Cari Data\n");
            printf("6. Hapus Data\n");
            printf("7. Keluar\n");
            printf("Pilihan kamu? = ");
            scanf("%d", &pil);
            switch(pil){
                  case 1 :
                        printf("\nINPUT : ");
                        printf("\n-------");
                        printf("\nData baru : ");
                        scanf("%d", &data);
                        tambah(&tree, data);
                        break;
                  case 2 :
                        printf("\nOUTPUT PRE ORDER : ");
                        printf("\n------------------\n");
                        if(tree!=NULL)
                        //panggil fungsi untuk mencetak data secara preOrder
                              preOrder(tree);
                        else
                              printf("Masih kosong!");
                        break;
                  case 3 :
                        printf("\nOUTPUT IN ORDER : ");
                        printf("\n-----------------\n");
                        if(tree!=NULL)
                        //panggil fungsi untuk mencetak data secara preOrder
                              inOrder(tree);
                        else
                              printf("Masih kosong!");
                        break;
                  case 4 :
                        printf("\nOUTPUT POST ORDER : ");
                        printf("\n------------------\n");
                        if(tree!=NULL)
                        //panggil fungsi untuk mencetak data secara postOrder
                              postOrder(tree);
                        else
                              printf("Masih kosong!");
                        break;
                  case 5 :
                        printf("\nHAPUS DATA");
                        printf("\n-----------");
                        int data1;
                        printf("\nMasukkan data yang mau dicari: ");
                        scanf("%d", &data1);
                        //panggil fungsi untuk mencetak data secara postOrder
                        if(tree!=NULL)
                              search(&tree, data1);
                        else
                              printf("Masih kosong!");
                        break;
                  case 6 :
                        printf("\nHAPUS DATA");
                        printf("\n-----------");
                        int data2;
                        printf("\nMasukkan data yang akan dihapus: ");
                        scanf("%d", &data2);
                        //panggil fungsi untuk mencetak data secara postOrder
                        if(tree!=NULL)
                              hapus(&tree, data2);
                        else
                              printf("Masih kosong!");
                        break;
            }
            getch();
      }
      while(pil!=7);
}
