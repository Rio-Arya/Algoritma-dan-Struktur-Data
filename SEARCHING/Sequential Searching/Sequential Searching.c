#include <stdio.h>
 
int main()
{
   int array[100], cari, x, n, jumlah = 0;
   
   printf("Mau berapa data yang disimpan? ");
   scanf("%d", &n);
   
   printf("Masukkan %d integer\n", n);
   
   for (x = 0; x < n; x++)
      scanf("%d", &array[x]);
     
   printf("Angka yang ingin dicari? ");
   scanf("%d", &cari);
   
   for (x = 0; x < n; x++) {
      if (array[x] == cari) {
         printf("Angka %d ada, dan ada di lokasi %d.\n", cari, x+1);
         jumlah++;
      }
   }
   if (jumlah == 0)
      printf("%d tidak ada di array\n", cari);
   else
      printf("Angka %d ada sebanyak %d kali di array\n", cari, jumlah);
     
   return 0;
}