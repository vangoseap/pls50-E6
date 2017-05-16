/*************************************************
***    Author Tsouramanis Evaggelos            ***
***         Ergasia 2    Thema 3               ***
***  Ylopoiisi parallagis tou paixnidiou SET   ***
***                                            ***
**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct stoixeia
{
    char name[17];
    int score;
    unsigned char id[2];
} paiktis[3];

struct properties
{
    char color[2];
    char shape[2];
    char number[2];
    char texture[2];
} karta[81],plegma[12] ;

unsigned char kode[2]= {'\0'};
char pinax[3][4]= {'\0'};
int nrand;
int nrand81;

void fill_pinax();
char rand81_karta();
int rand_n3();
int rand_n81();
int karta12();
int player();
int game();
int termatismos();
int player_lost();
int player_lost();
void arxi();
int elegxos_k();


void main()
{
    struct properties karta ;
    arxi();
    srand(time(NULL));
    rand81_karta();
    player();

}

/************************/
void arxi()
{
    struct properties  karta = {0}; //Arxikopoiisi
    struct properties plegma = {0};
    struct stoixeia  paiktis = {0};
}

/**********************/
char rand81_karta()
{
    struct properties;
    int i,rc,rs,rn,rt,ka;


    for (i=0; i<81; i++)
    {
        rc=rand_n3();
        if(rc==0)      strcpy(karta[i].color,"r");
        else if(rc==1) strcpy(karta[i].color,"b");
        else if(rc==2) strcpy(karta[i].color,"g");


        rs=rand_n3();
        if(rs==0)      strcpy(karta[i].shape,"c");
        else if(rs==1) strcpy(karta[i].shape,"t");
        else if(rs==2) strcpy(karta[i].shape,"r");


        rn=rand_n3();
        if(rn==0)      strcpy(karta[i].number,"1");
        else if(rn==1) strcpy(karta[i].number,"2");
        else if(rn==2) strcpy(karta[i].number,"3");


        rt=rand_n3();
        if(rt==0)      strcpy(karta[i].texture,"b");
        else if(rt==1) strcpy(karta[i].texture,"h");
        else if(rt==2) strcpy(karta[i].texture,"e");

    }

}

/******************/
int karta12()
{
    int ka,i;

    for(i=0; i<12; i++)
    {
        ka=rand_n81();
        strcpy(plegma[i].color,karta[ka].color);
        strcpy(plegma[i].shape,karta[ka].shape);
        strcpy(plegma[i].number,karta[ka].number);
        strcpy(plegma[i].texture,karta[ka].texture);

        if (i==0 ||i==1 ||i==2)
            printf("[%s,%s,%s,%s] ",plegma[i].color,plegma[i].shape,plegma[i].number,plegma[i].texture);
        else if (i==3)
            printf("[%s,%s,%s,%s]\n",plegma[i].color,plegma[i].shape,plegma[i].number,plegma[i].texture);

        if (i==4 ||i==5 ||i==6)
            printf("[%s,%s,%s,%s] ",plegma[i].color,plegma[i].shape,plegma[i].number,plegma[i].texture);
        else if (i==7)
            printf("[%s,%s,%s,%s]\n",plegma[i].color,plegma[i].shape,plegma[i].number,plegma[i].texture);

        if (i==8 ||i==9 ||i==10)
            printf("[%s,%s,%s,%s] ",plegma[i].color,plegma[i].shape,plegma[i].number,plegma[i].texture);
        else if (i==11)
            printf("[%s,%s,%s,%s]\n",plegma[i].color,plegma[i].shape,plegma[i].number,plegma[i].texture);

    }
    printf("\n");
    return 0;
}


/*************/
int rand_n3()
{
    int i;

    for( i = 0 ; i < 3 ; i++ )
    {
        nrand=rand() % 3;
    }
    return nrand;
}

/*************/
int rand_n81()
{
    int i ;

    for( i = 0 ; i < 81 ; i++ )
    {
        nrand81=rand() %81;
    }
    return nrand81;
}

/**************************************/
int player()
{
    int i=0,j=0,k=0,found=0,idios=0,pass=0;
    char c;
    char onoma[17]= {'\0'};
    //system("cls");//Dos
    system("clear");//Linux

    for(i=0; i<3; ++i)
    {
        printf("Dwse to onoma sou %d paiktis:",(i+1));
        fgets(onoma,sizeof(onoma),stdin);
        strcpy(paiktis[i].name,onoma);
        do
        {
            printf("Dwse ton kwdiko sou:");
            fgets(kode,sizeof(kode),stdin);
            if (i==0) strcpy(paiktis[i].id,kode);
            c=getchar();
            if (i==1 ||i==2)
            {
                idios=elegxos_k();
                if (idios==0) strcpy(paiktis[i].id,kode);
                if (idios==1) printf("O kwdikos autos yparxei\n");
            }
        }
        while (idios==1);

    }
    //system("cls");//Dos
    system("clear");//Linux

    fill_pinax();
    return 0;
}

/************************************************/
int elegxos_k(int k)
{

    int i,j,found=0;
    for(i=0; i<3; i++)
    {
        if(strcmp(paiktis[i].id,kode)==0 )
        {
            found++;
            break;
        }

    }
    if (found==0) return 0;
    else if (found!=0) return 1;
}

/**********************************************/
void fill_pinax()
{
    //char c;
    //unsigned char kod[2]= {'\0'};
    //int i;
    //system("cls");//Dos
    system("clear");//Linux

    karta12();
    game();
}
/***************************************************/
int game()
{

    char c;
    int i,j,k,m,x1,y1,x2,y2,x3,y3;
    int c1=0,c2=0,c3=0,flag=0,found=0,idia=0,diff=0,nfound=0;
    unsigned char kod[2]= {'\0'};
    int yes = 1;

//Apoklismos idias kartas
    for (i = 0; i < 11; ++i)
    {
        for (j = i + 1; j < 12; ++j)
            if (strcmp(plegma[i].color,plegma[j].color)==0 &&
                    strcmp(plegma[i].shape,plegma[j].shape)==0 &&
                    strcmp(plegma[i].number,plegma[j].number)==0 &&
                    strcmp(plegma[i].texture,plegma[j].texture)==0)

            {
                system("clear");
                yes = 0;
                break;
            }
        if (!yes) break;
    }
    if (!yes)
    {
        karta12();
        game();
    }
    if (yes)

//Energos paiktis sto game

        printf("\nO paiktis pou pata prwtos ton kwdiko tou xekina to paixnidi:");
    scanf("%s",kode);
    strcpy(kod,"0");
    if (strcmp(kode,kod)==0) termatismos();
    for (i=0; i<3; i++)
    {
        if (strcmp(paiktis[i].id,kode)==0)
        {
            printf("%s",paiktis[i].name);
            flag++;
        }
        if (flag==1) break;
    }

    if (flag==0) fill_pinax();//New game

    do
    {
        printf("Dwse syntetagmenes X Y tis  1 kartas:");
        if (scanf("%d %d",&x1,&y1)==2);
        else x1=getchar();
    }
    while(x1 < 0 || x1 >3 || y1<0 || y1 >3);

    do
    {
        printf("Dwse syntetagmenes X Y tis  2 kartas:");
        if (scanf("%d %d",&x2,&y2)==2);
        else x2=getchar();
    }
    while(x2 < 0 || x2 >3 || y2<0 || y2 >3);

    do
    {
        printf("Dwse syntetagmenes X Y tis  3 kartas:");
        if (scanf("%d %d",&x3,&y3)==2);
        else x3=getchar();
    }
    while(x3 < 0 || x3 >3 || y3<0 || y3 >3);

    if     (x1==0 && y1==0) c1=0;
    else if(x1==0 && y1==1) c1=1;
    else if(x1==0 && y1==2) c1=2;
    else if(x1==0 && y1==3) c1=3;
    else if(x1==1 && y1==0) c1=4;
    else if(x1==1 && y1==1) c1=5;
    else if(x1==1 && y1==2) c1=6;
    else if(x1==1 && y1==3) c1=7;
    else if(x1==2 && y1==0) c1=8;
    else if(x1==2 && y1==1) c1=9;
    else if(x1==2 && y1==2) c1=10;
    else if(x1==2 && y1==3) c1=11;

    if     (x2==0 && y2==0) c2=0;
    else if(x2==0 && y2==1) c2=1;
    else if(x2==0 && y2==2) c2=2;
    else if(x2==0 && y2==3) c2=3;
    else if(x2==1 && y2==0) c2=4;
    else if(x2==1 && y2==1) c2=5;
    else if(x2==1 && y2==2) c2=6;
    else if(x2==1 && y2==3) c2=7;
    else if(x2==2 && y2==0) c2=8;
    else if(x2==2 && y2==1) c2=9;
    else if(x2==2 && y2==2) c2=10;
    else if(x2==2 && y2==3) c2=11;

    if     (x3==0 && y3==0) c3=0;
    else if(x3==0 && y3==1) c3=1;
    else if(x3==0 && y3==2) c3=2;
    else if(x3==0 && y3==3) c3=3;
    else if(x3==1 && y3==0) c3=4;
    else if(x3==1 && y3==1) c3=5;
    else if(x3==1 && y3==2) c3=6;
    else if(x3==1 && y3==3) c3=7;
    else if(x3==2 && y3==0) c3=8;
    else if(x3==2 && y3==1) c3=9;
    else if(x3==2 && y3==2) c3=10;
    else if(x3==2 && y3==3) c3=11;


    if(strcmp(plegma[c1].color,plegma[c2].color)==0 && strcmp(plegma[c2].color,plegma[c3].color)==0) found++;
    if(strcmp(plegma[c1].shape,plegma[c2].shape)==0 && strcmp(plegma[c2].shape,plegma[c3].shape)==0)found++;
    if(strcmp(plegma[c1].number,plegma[c2].number)==0 && strcmp(plegma[c2].number,plegma[c3].number)==0 ) found++;
    if(strcmp(plegma[c1].texture,plegma[c2].texture)==0 && strcmp(plegma[c2].texture,plegma[c3].texture)==0) found++;

    if(strcmp(plegma[c1].color,plegma[c2].color)!=0 && strcmp(plegma[c2].color,plegma[c3].color)!=0) nfound++;
    if(strcmp(plegma[c1].shape,plegma[c2].shape)!=0 && strcmp(plegma[c2].shape,plegma[c3].shape)!=0) nfound++;
    if(strcmp(plegma[c1].number,plegma[c2].number)!=0 && strcmp(plegma[c2].number,plegma[c3].number)!=0 ) nfound++;
    if(strcmp(plegma[c1].texture,plegma[c2].texture)!=0 && strcmp(plegma[c2].texture,plegma[c3].texture)!=0) nfound++;

    for (i=0; i<3; i++)
    {
        if (found==3)
        {
            if (strcmp(paiktis[i].id,kode)==0)
            {
                printf("You Found SET !!");
                paiktis[i].score=(paiktis[i].score)+2;
                printf(" %s\n",paiktis[i].name);
                printf("Score==%d\n",paiktis[i].score);
                getchar();
                printf("Press Enter gia synexeia");
                getchar();

                if (paiktis[i].score>=10)//Megalytero > giati mpore na yparxei 9+2=11 vathmoi tou paikti
                {
                    termatismos();
                }
                fill_pinax();
            }
        }

        else if (found==1 && nfound==3)
        {
            if (strcmp(paiktis[i].id,kode)==0)
            {
                printf("You Found SET !!");
                paiktis[i].score=(paiktis[i].score)+2;
                printf(" %s\n",paiktis[i].name);
                printf("Score==%d\n",paiktis[i].score);
                getchar();
                printf("Press Enter gia synexeia");
                getchar();

                if (paiktis[i].score>=10)
                {
                    termatismos();
                }

                fill_pinax();
            }
        }
        else if (found==2 || found==1 ||found ==0 )
        {
            if(strcmp(paiktis[i].id,kode)==0)
            {
                printf("NO SET ??");
                paiktis[i].score=(paiktis[i].score)-1;
                if (paiktis[i].score < 0) paiktis[i].score=0;
                printf(" %s\n",paiktis[i].name);
                printf("Score==%d\n",paiktis[i].score);
                game();
            }
        }
    }
}

/************************************************/
int termatismos()
{
    int i;
    //system("cls");//Dos
    system("clear");//Linux
    for(i=0; i<3; i++)
    {
        printf("%s Score= %d\n",paiktis[i].name,paiktis[i].score);
        if (paiktis[i].score>=10) printf("\nNIKHTHS einai o %s\n",paiktis[i].name);
    }
    exit(1);
    return 0;
}



