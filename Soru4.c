#include<stdio.h>

void sezarCoz (char mesaj[] , int anahtar);

int main()
{
    char mesaj[50];
    int anahtar;

    printf("cozmek istediginiz mesaji girin :");
    fgets(mesaj , 50 , stdin);

    printf("anahtar degerini girin: ");
    scanf("%d" , &anahtar);

    sezarCoz(mesaj , anahtar );

    printf("cozulmus mesaj : %s " , mesaj);

    return 0;
}

void sezarCoz (char mesaj[] , int anahtar)
{
    int i ;

    for (int i=0 ; mesaj[i] != '\0' ; i++)
    {
        if (mesaj[i] >= 'a' && mesaj[i] <= 'z')
        {
         mesaj[i]= (mesaj[i] - 'a' - anahtar + 26) %26 + 'a';
        }
        else if (mesaj[i] >= 'A'  && mesaj[i] <= 'Z')
        {
            mesaj[i]=(mesaj[i] - 'A' - anahtar + 26) %26 + 'A';
        }

    }
}
