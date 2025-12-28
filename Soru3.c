// Bu program Gezegen Bob'daki kurallara göre geçerli üç harfli isimleri bulur ve ekrana yazdırır

#include <stdio.h>

int asalMi(int sayi) ;
int unluMu(char c) ;


int main()
{
    char harf1, harf2;
    int sayac = 0;   // Geçerli isim sayısını tutar


    for (harf1 = 'a'; harf1 <= 'z'; harf1++) // ilk ve üçüncü harf için 'a'dan 'z'ye kadar tüm harfler denenir
    {

        for (harf2 = 'a'; harf2 <= 'z'; harf2++) // Ortadaki harf için'a'dan 'z'ye kadar tüm harfler denenir
        {

            //isim ünlü-ünsüz-ünlü veya ünsüz-ünlü-ünsüz olmalı

            if ((unluMu(harf1) && !unluMu(harf2)) ||
                (!unluMu(harf1) && unluMu(harf2)))
            {

                int asciiToplam = harf1 + harf2 + harf1;


                if (asalMi(asciiToplam))
                {
                    sayac++;
                    printf("%d. %c%c%c\n", sayac, harf1, harf2, harf1);

                }
            }
        }
    }

    printf("\nToplam gecerli isim sayisi: %d\n", sayac);

    return 0;
}

 int asalMi(int sayi)
 {

    if (sayi < 2)
        return 0;


    for (int i = 2; i * i <= sayi; i++) // Sayının kendisine kadar gitmeye gerek yok, kareköküne kadar kontrol yeterli
    {

        if (sayi % i == 0)

            return 0;
    }

   return 1;   // Hiç bölen bulunmazsa asal kabul edilir

}

// Girilen karakterin unlu harf olup olmadigini kontrol eder

int unluMu(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

