#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data{
	char nama[100];
	int harga;
}buah[5];

void display (int x){
	 printf("Menu Lihat Data Buah\n");
     printf("=====================\n");
     printf("No|Nama Buah|Harga Buah| \n");
     printf("---------------------------------------------------------------\n");
        for(int a = 1 ; a<x; a++){
          printf("%d|", a);
          printf("%s|", buah[a].nama);
          printf("Rp.%d|\n", buah[a].harga);
        }
}

//insertion
void sortnama (int x){
	struct data tmp;
		        	printf("---Sorting Nama---\n");
                    printf("=====================\n");
                    printf("No|Nama Buah|Harga Buah| \n");
                for(int i=1; i<x; i++){
                    for(int j=1; j<x-i; j++){
                        if(strcmp(buah[j].nama, buah[j+1].nama) > 0){
                             tmp=buah[j];
                            buah[j]=buah[j+1];
                            buah[j+1]=tmp;
                         }
                    }
                }
                for (int i=1; i<x; i++){
                printf("%d|",i);
                printf("%s|",buah[i].nama);
                printf("%d|\n",buah[i].harga);
                }
}
void sortharga(int x){
	struct data tmp;
                    printf("----Sorting Harga----\n");
                    printf("=====================\n");
                    printf("No|Nama Buah|Harga Buah| \n");
                for(int i=1;i <x;i++){
                    for(int j=0;j<(x-i);j++){
                        if(buah[j].harga > buah[j+1].harga){
                            tmp = buah[j];
                            buah[j] = buah[j+1];
                            buah[j+1]= tmp;
                }
                    }
                        }

                     for (int i=1; i<x; i++){
                         printf("%d|",i);
                         printf("%s|",buah[i].nama);
                         printf("%d|\n",buah[i].harga);
                }
}

//sequential
void searchnama (int x){
	char search[100];
		printf("Nama Buah yang ingin dicari: ");
		scanf("%[^\n]", search);
		strlwr(search);
        	for (int i=1; i< x; i++){
                if (strcmp(search, buah[i].nama)==0){
                      printf ("Buah tersedia!\n");
                         printf("Nama: %s \n",buah[i].nama);
                         printf("Harga: %d \t",buah[i].harga);
                        break;

                        }
                else if (i==x){
                	printf("Buah Tidak ditemukan");
				}
            }
}
void searchharga (int x){
	int search2;
	printf("Harga Buah yang ingin dicari: ");
	scanf("%d",&search2);
        for (int i=1; i<x; i++){
            if (search2 == buah[i].harga){
            printf ("Buah tersedia!\n");
            printf("Nama   : %s \n",buah[i].nama);
            printf("Harga  : %d \t",buah[i].harga);
            break;
            }
            else if (search2==i) {
            printf("Buah Tidak Ditemukan");
            }
        }
}

int main(){
	int n;
	int flag=0;
	int x=1;

	do{
		getchar();
		system("cls");
		printf("---------------Tugas 3----------------\n");
		printf("================MENU==================\n");
		printf("1. Tambah Data Buah\n");
		printf("2. Lihat Data Buah\n");
		printf("3. Sorting Nama\n");
		printf("4. Sorting Harga\n");
		printf("5. Searching Nama\n");
		printf("6. Searching Harga\n");
		printf("7. Exit\n");
		printf("==========================================\n");
		printf("Masukkan Pilihan: ");
		scanf("%d", &n);
        getchar();
		switch(n)
		{
			case 1:
                system ("cls");
                printf("Menu Tambah Data Buah\n");
                printf("======================\n");

                char array[100];
                int y;
                printf("Masukkan Banyaknya Data: ");
                scanf("%d",&y);
                fflush(stdin);
                system ("cls");
                if (y<=5){
                for (int i=0;i<y;i++){
                printf("Nama Buah   : ");
                scanf("%[^\n]", array);
                strlwr(array);
                fflush(stdin);
                printf("Harga Buah  : Rp. ");
                scanf("%d", &buah[x].harga);
                fflush(stdin);
                for (int i=1;i<=x;i++){
                    if (strcmp(array,buah[i].nama)==0){
					printf("Buah Sudah Tersedia\n");
					break;
				}
                    else if (x==i){
                        strcpy(buah[x].nama,array);
                        printf("Input Berhasil\n");
                        x++;
                        break;
                        }
                    }
                    }
                }
                else{printf("Input lebih dari 5");}
				getchar();
				break;

			case 2:
				system ("cls");
				display(x);
                getchar();
				break;
			case 3:
                system("cls");
       			sortnama(x);
       			getchar();
				break;
			case 4:
				system("cls");
				sortharga(x);
		        getchar();
				break;
			case 5:
				system("cls");
				searchnama (x);
				getchar();
				break;

			case 6:
				system("cls");
				searchharga(x);
                getchar();
				break;
			case 7:
				flag = 1;
				break;
			default:
				printf("pilihan tidak ada\n");
			 getchar();
			}


  }while (flag == 0);
	return 0;
}
