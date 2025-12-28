// Bu program girilen n değerine göre sayılarla eşkenar üçgen çizer

#include <stdio.h>

void eskenarUcgenCiz(int n);

int main()
{
    int n;

    printf("eskenar ucgen ciziliyor...\n");

    printf("bir tam sayi girin : ");
    scanf("%d", &n);

    eskenarUcgenCiz(n);   // üçgeni çizen fonksiyon çağrılır

    return 0;
}


void eskenarUcgenCiz(int n) //üçgeni çizen fonksiyon
{
    int i, j;
    int sayi = 1;
    int toplam;

    toplam = n * (n + 1) / 2;  // 1'den n'e kadar olan sayilarin toplamini bulur.

    for (i = 1; i <= n; i++)   // üçgenin her satırı
    {
        for (j = i; j <= n; j++)   // sola hizalama için boşluk
        {
            printf(" ");
        }

        for (j = 1; j <= i; j++)   // satırda yazılacak sayılar
        {
            if (sayi <= toplam)
            {
                printf("%d ", sayi);
                sayi++;
            }
        }
        printf("\n");
    }
}
