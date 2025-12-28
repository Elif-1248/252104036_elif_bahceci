// Bu program 12 aylık ciro değerlerini rastgele üretir
// yatay ve dikey bar grafiği şeklinde ekrana yazdırır.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int aylikCiro[12];
int i , j ;


int main()
{

   srand(time(NULL));  // Rastgele sayı üretimini her çalıştırmada farklı yapmak için



   for (int i = 0; i < 12; i++)
    {
        aylikCiro[i] = rand() % 10 + 1;  // 1-10 arası aylık ciro değerleri
    }
    printf("\nYATAY BAR GRAFIGI\n");


    for(i=0 ; i<12 ; i++)
     {
        printf("Ay %2d | " , i + 1);

            for (j=0 ; j<aylikCiro[i] ; j++)  // Ciro değeri kadar yıldız basımı
             {
                    printf(" * ");
             }
                    printf("\n");
     }



     int max = aylikCiro[0];   // Dikey grafik için maksimum değerin bulunması


    for(i=1 ; i<12 ; i++)
     {
        if (aylikCiro[i] > max)

            max = aylikCiro[i];
     }
        printf("\nDIKEY BAR GRAFIGI\n");



    for (j= max ; j>0 ; j--)    // Dikey bar grafiğinin çizimi
     {
    for (i=0 ; i<12 ; i++)
     {

        if(aylikCiro[i] >= j)
        printf(" * ");


        else
        printf("   ");
     }

     printf("\n");

     }


     printf("\n");


     for (i = 0; i < 12; i++)
      {
        printf(" %2d", i + 1);  // Ay numaraları
      }

         printf("\n");


     return 0;
   }


