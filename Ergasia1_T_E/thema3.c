/* Author: Tsouramanis Evangelos
   Thema3: Antistrofi dyadiki anaparastasi arithmou */
#include <stdio.h>

#define const 2;

void anaparastasi_binary(int ar)
{
    int ypol;
    while(ar!=0)
    {
        ypol=ar % const;
        (ypol==1) ? putchar(49) : putchar(48);
        ar=ar/const;
    }
    printf("\n");
}
//============================================
void main()
{
    int num;
    char ch;
arxi:;

    printf("Dwse ena thetiko akeraio :");

    if(scanf("%d%c", &num, &ch) != 2 || ch != '\n')
    {
        system("cls");
        printf("Lathos arithmos \n");
        while((ch=getchar()) != '\n' && ch != EOF);
        goto arxi;
    }
    else if (num==0) printf("Telos\n");

    else if(num<0)
    {
        system("cls");
        printf("Lathos arithmos\n");
        goto arxi;
    }
    else anaparastasi_binary(num);
    system("pause");
}
