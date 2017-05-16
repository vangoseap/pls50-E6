/*************************************************
***    Author Tsouramanis Evaggelos            ***
***           Ergasia2     Thema 1             ***
***  Neo systima katagrafis kratimenwn thesewn ***
***                                            ***
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char adeio[40]= {'\0'};
char pinakida[40]="HHH1234";
unsigned int seats;

struct stoixeia
{
    char name[40];
    unsigned short  phone[10];
    unsigned int thesis;
};

struct stoixeia *epivatis;

void readseats();
int arxikopoiisi();
void emfanisi_kenwn();
int readfile();
void emfanisi_menu();
int kratisi_kenis();
void menu_anazitisis();
int anazitisi_me_names();
int anazitisi_me_thesi();
int anazitisi_me_telephone();
int akirosi_thesis();
int emfanisi_listas();
int apothikefsi_txt();




int main()
{
    struct stoixeia epivatis[seats];
    readseats();
    arxikopoiisi();
    readfile();
    emfanisi_menu();

    return 0;
}
/******************************/
/*Diavasma arxeiou bus.txt gia tin evresi twv thesewn*/
void readseats()
{
    char str[8];
    unsigned int theseis;

    FILE *fp;
    fp=fopen("bus.txt","r");
    if (fp==NULL)
    {
        printf("Error file");
        exit(1);
    }
    fscanf(fp,"%s %u",str,&theseis);
    fclose(fp);
    seats=theseis;
    epivatis=(struct stoixeia *)calloc(seats,sizeof(struct stoixeia));

    if (epivatis==NULL)
    {
        puts("Den yparxei arketi memory");
        exit(2);
    }

}

/*****************************/
int arxikopoiisi()
{
    int i,j;
    for(i=0; i<seats; i++)
    {
        strcpy(epivatis[i].name,adeio);
        for(j=0; j<10; j++) epivatis[i].phone[j]=0;
        epivatis[i].thesis=i+1;
    }
    return 0;
}
/********************************/
int readfile()
{
    int i,j,k;
    char pinakida[40],str1[25],str2[15];
    unsigned int num;

    FILE *fap;
    fap=fopen("bus.txt","r");
    if (fap==NULL)
    {
        printf("ERROR FILE");
        exit(1);
    }
    fscanf(fap,"%s %u ",pinakida,&seats);
    printf("%s  %u\n",pinakida,seats);//Meta to diavasma emfanisi pinakidas kai thesewn stin othoni


    for(i=0; i<seats; i++)
    {
        if (strcmp(epivatis[i].name,adeio)==0)
        {

            fscanf(fap,"%s %s %u",str1,str2,&num);
            if (feof(fap)) break;

            strcat(str1," ");
            strcat(str1,str2);
            strcpy(epivatis[num-1].name,str1); // to stoixeio[0]= me tin 1 thesi
            printf("%s ",epivatis[num-1].name);
            epivatis[num-1].thesis=num;
            printf("%u ",epivatis[num-1].thesis);


            for(j=0; j<10; j++)
            {
                fscanf(fap,"%1hu",&epivatis[num-1].phone[j]);
                printf("%hu",epivatis[num-1].phone[j]);
            }
            printf("\n");
            if (feof(fap)) break;

        }

    }

    fclose(fap);
    return 0;
}

/*****************************/
/*To basiko Menu-Epiloges   */

void emfanisi_menu()
{
    int choice;


    while (choice != 0)
    {
        printf("\n");
        printf("     ****************************************\n");
        printf("     *      Epiloges-Main Menu              *\n");
        printf("     *                                      *\n");
        printf("     *   1.Emfanisi twn kenwn thesewn       *\n");
        printf("     *   2.Kratisi kenis thesis             *\n");
        printf("     *   3.Anazitisi kratimenis thesis      *\n");
        printf("     *   4.Akyrosi kratimenis thesis        *\n");
        printf("     *   5.Emfanisi listas epivatwn         *\n");
        printf("     *                                      *\n");
        printf("     *   0.Telos                            *\n");
        printf("     ****************************************\n");
        printf("\n Epilogi apo to  menu :");

        if (scanf("%d", &choice)==1)
        {
            // system("cls");// for Dos
            system("clear");// For Linux
        }
        else choice=getchar();
        //system("cls");
        system("clear");
        if (choice>=1 && choice<=5)
        {
            switch (choice)
            {
            case 1:
                // system("cls");// for Dos
                system("clear");// For Linux
                emfanisi_kenwn();
                break;
            case 2:
                //system("cls");// for Dos
                system("clear");// For Linux
                //emfanisi_kenwn();
                kratisi_kenis();
                break;
            case 3:
                // system("cls");// for Dos
                system("clear");// For Linux
                menu_anazitisis();
                break;
            case 4:
                // system("cls");// for Dos
                system("clear");// For Linux
                akirosi_thesis();
                break;
            case 5:
                // system("cls");// for Dos
                system("clear");// For Linux
                emfanisi_listas();
                break;
            }
        }
    }
    apothikefsi_txt();
}


/********************************/
void emfanisi_kenwn()
{
    struct stoixeia;
    int i,j,keni=0;

    for(i=0; i<seats; i++)
    {

        if (strcmp(epivatis[i].name,adeio)==0)
        {
            printf("%u ",epivatis[i].thesis);
            keni++;
        }
    }
    printf("\n\nSynolo kenwn thesewn:%d\n",keni);
}

/********************************/
int kratisi_kenis()

{
    int i,j,k,numkra,found=0;
    char c,eponymo[40],onoma[15],tele[11]= {'\0'},str[11]= {'\0'};
    long long val;

    do
    {
        printf("Dwse ton arithmo thesis:");
        if (scanf("%d",&numkra)==1)
            system("clear");// For Linux
        else numkra=getchar();
    }
    while(numkra < 1 || numkra >seats);


    for(i=0; i<seats; i++)
    {
        if (strcmp(epivatis[i].name,adeio)==0 && epivatis[i].thesis==numkra)
        {
            found++;
            printf("Ok i thesi %d einai keni",numkra);
            printf("\nDwse to epwnymo:");
            scanf("%s",eponymo);
            getchar();
            printf("\nDwse to onoma:");
            scanf("%s",onoma);
            getchar();
            strcat(eponymo," ");
            strcat(eponymo,onoma);
            strcpy(epivatis[i].name,eponymo);
            epivatis[i].thesis=numkra;
            fflush(stdin);

            printf("\nDwse to tilefono tou epivati me 10 numbers:");
            do
            {
                fgets(tele,sizeof(tele),stdin);
                strlen(tele);
            }
            while (strlen(tele)!=10);
            strcpy(str,tele);
            val = atoll(str);
            for (k =9; k >=0; k--)
            {
                epivatis[i].phone[k]=val%10;
                val =val/10;
            }

        }
    }
    if (found==0) printf("H thesi einai kartimeni");
    return 0;
}

/******************************/
/*To Menu anazitisis         */

void menu_anazitisis()
{

    int choice;

    while (choice != 4)
    {
        printf("\n\n\n");
        printf("     **********************************\n");
        printf("     *      Epiloges  Anazitisis      *\n");
        printf("     *                                *\n");
        printf("     *   1.Me ton arithmo thesis      *\n");
        printf("     *   2.Me to onomateponymo        *\n");
        printf("     *   3.Me to telephone            *\n");
        printf("     *                                *\n");
        printf("     *   4.Epistrofi sto Main Menu    *\n");
        printf("     **********************************\n");
        printf("\n Epilogi apo to  menu :");
        if (scanf("%d", &choice)==1)
        {
            // system("cls");// for Dos
            system("clear");// For Linux
        }
        else choice=getchar();
        //system("cls");
        system("clear");

        if (choice>=1 && choice<=3)
        {
            switch (choice)
            {
            case 1:
                // system("cls");// for Dos
                system("clear");// For Linux
                anazitisi_me_thesi();
                break;
            case 2:
                //system("cls");// for Dos
                system("clear");// For Linux
                anazitisi_me_names();
                break;
            case 3:
                // system("cls");// for Dos
                system("clear");// For Linux
                anazitisi_me_telephone();
                break;
            }
        }
    }
}

/************************************/

int anazitisi_me_names()
{

    int i,j,found=0;
    char eponymo[40],onoma[15];
    char c;

    printf("\nDwse to epwnymo:");
    scanf("%s",eponymo);
    getchar();
    printf("\nDwse to onoma:");
    scanf("%s",onoma);
    getchar();
    strcat(eponymo," ");
    strcat(eponymo,onoma);

    for(i=0; i<seats; i++)
    {
        // system("cls");// for Dos
        system("clear");// For Linux
        if((strcmp(epivatis[i].name,eponymo)==0))
        {
            // system("cls");// for Dos
            system("clear");// For Linux
            printf("NAI yparxei thesi kratimeni apo ton  epivati %s\n",epivatis[i].name);
            found++;
            break;
        }
    }
    if (found==0)printf("OXI den yparxei thesi kartimeni apo epivati me auto to onoma");

}


/************************************/
int anazitisi_me_thesi()
{
    int i,j,found=0;
    unsigned int numthesis=0;
    do
    {
        printf("Dwse ton arithmo thesis tou epivati :");
        if (scanf("%u",&numthesis)==1)
        {
            // system("cls");// for Dos
            system("clear");// For Linux
        }
        else
        {
            numthesis=getchar();
        }

    }
    while (numthesis<1 || numthesis>seats);

    for(i=0; i<seats; i++)
    {
        if ((epivatis[i].thesis==numthesis) && (strcmp(epivatis[i].name,adeio)==1))
        {
            printf("NAI i thesi %u einai kratimeni apo ton epivati:\n",numthesis);
            printf("\n%s",epivatis[i].name);
            found=1;
        }

    }
    if(found==0)
    {
        printf("OXI i thesi %u einai keni",numthesis);
    }
    return 0;
}
/****************************************/
int anazitisi_me_telephone()
{
    int i,j,k,m,cnt=0,found=0;
    char c,atele[11]= {'\0'},astr[11]= {'\0'};
    long long aval;
    unsigned short aphone[10]= {0};
    int is_equal=0;
    // system("cls");// for Dos
    system("clear");// For Linux

    printf("Dwse to tilefono tou epivati me 10 numbers:");

    do
    {
        fgets(atele,sizeof(atele),stdin);
        strlen(atele);
    }
    while (strlen(atele)!=10);

    strcpy(astr,atele);
    aval = atoll(astr);

    for (k =9; k >=0; k--)
    {
        aphone[k]=aval%10;
        aval =aval/10;
    }
    printf("\n");

    for (j=0; j<seats; j++)
    {
        for (i=0; i<10; i++)
        {
            if (epivatis[j].phone[i]!=aphone[i])
            {
                is_equal=0;
                break;
            }

            for(i=0; i<10; i++)
            {
                if (epivatis[j].phone[i]==aphone[i])
                {
                    cnt++;
                    if(cnt==9)
                    {
                        is_equal=1;
                        cnt=0;
                        if (is_equal==1 && (strcmp(epivatis[j].name,adeio)==1))
                        {
                            found++;
                            printf("To telephone %s anikei ston epivati: %s\n",atele,epivatis[j].name);
                            break;
                        }
                    }
                }
            }
            if (found!=0) break;
        }
        if (found!=0) break;
    }

    if (found==0)printf("Den yparxei epivatis me auto to telephone");
    return 0;
}
/***************************************/
int akirosi_thesis()
{
    int i,j,numaki,akyrosi=0;
    do
    {
        printf("Dwse ton arithmo thesis gia AKYROSI:");
        if (scanf("%d",&numaki)==1)
        {
            // system("cls");// for Dos
            system("clear");// For Linux
        }
        else
        {
            numaki=getchar();
        }
    }
    while(numaki<1 || numaki>seats);

    for(i=0; i<seats; i++)
    {
        if ((epivatis[i].thesis==numaki) && (strcmp(epivatis[i].name,adeio)==1))
        {
            printf("NAI i thesi %d einai kratimeni apo ton epivati :%s\n",numaki,epivatis[i].name);
            printf("\nH thesi AKYROTHIKE");
            strcpy(epivatis[i].name,adeio);
            akyrosi=1;

        }
    }

    if (akyrosi==0)  printf("OXI den ginetai akirosi giati i thesi %d einai keni",numaki);
    return 0;
}

/**************************************/
int emfanisi_listas()
{
    int i,j;
    for(i=0; i<seats; i++)
    {
        if (strcmp(epivatis[i].name,adeio)==1 ||strcmp(epivatis[i].name,adeio)==-1)
        {
            printf("\n%s %d ",epivatis[i].name,epivatis[i].thesis);
            for(j=0; j<10; j++)  printf("%u",epivatis[i].phone[j]);
        }
    }
    return 0;
}
/**********************************/

int apothikefsi_txt()
{
    int i,j;
    seats=53;

    FILE *fap;
    fap=fopen("bus.txt","w");
    if (fap==NULL)
    {
        printf("ERROR FILE");
        exit(1);
    }
    fprintf(fap,"%s ",pinakida);
    fprintf(fap,"%u\n",seats);


    for(i=0; i<seats; i++)
    {
        if (strcmp(epivatis[i].name,adeio)==1||strcmp(epivatis[i].name,adeio)==-1)
        {
            fprintf(fap,"%s ",epivatis[i].name);
            fprintf(fap,"%u ",epivatis[i].thesis);
            for(j=0; j<10; j++)
            {
                fprintf(fap,"%hu",epivatis[i].phone[j]);
            }
            fprintf(fap,"\n");
        }
    }
    fclose(fap);
}






