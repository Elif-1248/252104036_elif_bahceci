// Bu program, 5x5 boyutundaki bir labirentte başlangıç noktası (0,0)'dan
//çıkış noktası (4,4)'e ulaşan bir yol olup olmadığını kontrol eder.

#include <stdio.h>
#define BOYUT 5   // Labirentin satır ve sütun sayısı sabit olarak tanımlar


 int yolBul(int labirent[BOYUT][BOYUT], int yol[BOYUT][BOYUT], int satir, int sutun);
 void yoluYazdir(int labirent[BOYUT][BOYUT], int yol[BOYUT][BOYUT]);

int main()
{
    // 1: gidilebilir yol, 0: engel olacak şekilde labirent tanımlar

   int labirent[BOYUT][BOYUT] =
  {
    {1,0,1,1,1},
    {1,0,1,0,1},
    {1,1,1,0,1},
    {0,0,1,1,1},
    {1,1,1,0,1}
  };


    int yol[BOYUT][BOYUT] = {0};


    if (labirent[0][0] == 0 || labirent[BOYUT-1][BOYUT-1] == 0)  // Başlangıç veya çıkış noktası kapalıysa labirent geçersizdir
    {
        printf("Gecersiz labirent\n");
        return 0;
    }

    printf("cikis yolu bulundu:\n\n");


    if (yolBul(labirent, yol, 0, 0))  // Yol arama işlemi başlatır
    {

        yoluYazdir(labirent, yol);
    }
    else
    {

        printf("Cikis yolu yok\n");
    }

    return 0;
}

// Bu fonksiyon geri izleme yöntemi ile labirentte çıkış noktasına ulaşan bir yol arar


int yolBul(int labirent[BOYUT][BOYUT], int yol[BOYUT][BOYUT], int satir, int sutun)
{

    if (satir < 0 || satir >= BOYUT || sutun < 0 || sutun >= BOYUT)  // Dizi sınırlarının dışına çıkılmışsa geri dön
        return 0;


    if (labirent[satir][sutun] == 0 || yol[satir][sutun] == 1)  // Hücre engel ise veya daha önce ziyaret edilmişse geri dön
        return 0;


    yol[satir][sutun] = 1;  // Geçerli hücre yolun bir parçası olarak işaretlenir


    if (satir == BOYUT-1 && sutun == BOYUT-1)  // Çıkış noktasına ulaşıldıysa yol bulundu demektir
        return 1;


    // Aşağı, yukarı, sağ ve sol yönlerde yol aranır

    if (yolBul(labirent, yol, satir + 1, sutun) ||
        yolBul(labirent, yol, satir - 1, sutun) ||
        yolBul(labirent, yol, satir, sutun + 1) ||
        yolBul(labirent, yol, satir, sutun - 1))
        return 1;


    yol[satir][sutun] = 0;
    return 0;
}

void yoluYazdir(int labirent[BOYUT][BOYUT], int yol[BOYUT][BOYUT])  // Bulunan yolu ekrana yazdıran fonksiyon
{
    for (int i = 0; i < BOYUT; i++)
    {
        for (int j = 0; j < BOYUT; j++)
        {
            if (yol[i][j] == 1) // Yolun bir parçası olan hücreler 1 olarak yazdırılır
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }
}

