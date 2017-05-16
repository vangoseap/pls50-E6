/*************************************************
***    Author Tsouramanis Evaggelos            ***
***     Ergasia2     - Thema 2                 ***
***          Epektasi sto                      ***
**    systima katagrafis kratimenvn thesevn    ***
***                                            ***
***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int seats;
char adeio[40]= {'\0'};

struct node
{
    char name[40];
    unsigned int thesis;
    unsigned short phone[10];
    struct node *next;
}*neos,*temp,*p;

struct node *list_head=NULL;
struct node *end=NULL;

struct stoixeia
{
    char name[40];
    unsigned int thesis;
    unsigned short phone[10];

} ;

struct stoixeia *passenger;

int arxikopoiisi();
void emfanisi_menu();
void emfanisi_kenwn();
int kratisi_kenis();
int lista_kata_thesi();
void readseats();
int akirosi_thesis();
void menu_anazitisis();
int anazitisi_me_names();
int anazitisi_me_thesi();
int anazitisi_me_telephone();
void menu_listas();
int lista_kata_onoma();
int read_txt();
void make_list();
void add_node_to_list();
void display_all_nodes();
void apothikefsi_txt();

/*******************************/
int main()
{
    struct stoixeia passenger[seats];
    readseats();
    arxikopoiisi();
    read_txt();
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
    passenger=(struct stoixeia *)calloc(seats,sizeof(struct stoixeia));

    if (passenger==NULL)
    {
        puts("Den yparxei arketi memory");
        exit(2);
    }

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
            system("clear");// For Linux
        }
        else choice=getchar();
        system("clear");
        if (choice>=1 && choice<=8)
        {
            switch (choice)
            {
            case 1:
                //system("cls");// for Dos
                system("clear");// For Linux
                emfanisi_kenwn();
                break;
            case 2:
                //system("cls");// for Dos
                system("clear");// For Linux
                kratisi_kenis();
                break;
            case 3:
                //system("cls");// for Dos
                system("clear");// For Linux
                menu_anazitisis();
                break;
            case 4:
                //system("cls");// for Dos
                system("clear");// For Linux
                akirosi_thesis();
                break;
            case 5:
                //system("cls");// for Dos
                system("clear");// For Linux
                menu_listas();
                break;
            }
        }
    }
    make_list();
    apothikefsi_txt();
}

/*****************************/
int arxikopoiisi()
{
    int i,j;
    for(i=0; i<seats; i++)
    {
        strcpy(passenger[i].name,adeio);
        for(j=0; j<10; j++) passenger[i].phone[j]=0;
        passenger[i].thesis=i+1;
    }
    return 0;
}
/******************************/
/*To Menu anazitisis         */

void menu_anazitisis()
{

    int choice;

    while (choice !=4)
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
        if((strcmp(passenger[i].name,eponymo)==0))
        {
            // system("cls");// for Dos
            system("clear");// For Linux
            printf("NAI yparxei thesi kratimeni apo ton  epivati %s\n",passenger[i].name);
            found++;
            break;

        }
    }
    if (found==0) printf("OXI den yparxei epivatis me auto to onoma");
}


/************************************/
int anazitisi_me_thesi()
{
    int i,j,found=0,numthesis=0;
    do
    {
        printf("Dwse ton arithmo thesis tou epivati :");
        if (scanf("%d",&numthesis)==1)
        {
            // system("cls");// for Dos
            system("clear");// For Linux
        }
        else numthesis=getchar();
    }
    while (numthesis<1 || numthesis>seats);

    for(i=0; i<seats; i++)
    {
        if ((passenger[i].thesis==numthesis) && (strcmp(passenger[i].name,adeio)==1))
        {
            printf("NAI i thesi %d einai kratimeni apo ton epivati:\n",numthesis);
            printf("\n%s",passenger[i].name);
            found=1;
        }
    }
    if (found==0)   printf("OXI i thesi %d einai keni",numthesis);
    return 0;
}
/****************************************/
int anazitisi_me_telephone()
{
    int is_equal=0,found=0;
    int i,j,k,m,cnt=0,cnt2=0;
    char c,atele[11]= {'\0'},astr[11]= {'\0'};
    long long aval;
    unsigned short aphone[10];//= {0};
    // system("cls");// for Dos
    system("clear");// For Linux

    printf("Dwse to tilefono tou epivati me 10 numbers:");

    do
    {
        fgets(atele,sizeof(atele),stdin);
        strlen(atele);
    }
    while (strlen(atele)!=10 );

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
            if (passenger[j].phone[i]!=aphone[i])
            {
                is_equal=0;
                break;
            }
       // }
        for(i=0; i<10; i++)
        {
            if (passenger[j].phone[i]==aphone[i])
            {
                cnt++;
                if(cnt==9)
                {
                    is_equal=1;
                    cnt=0;
                    if (is_equal==1 && (strcmp(passenger[j].name,adeio)==1))
                    {
                        printf("To telephone %s anikei ston epivati: %s\n",atele,passenger[j].name);
                        found++;
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
/**************************/

void emfanisi_kenwn()
{

    int i,j,keni=0;

    for(i=0; i<seats; i++)
    {
        if (strcmp(passenger[i].name,adeio)==0)
        {
            printf("%u ",passenger[i].thesis);
            keni++;
        }
    }
    printf("\n\nSynolikos arithmos kenwn thesewn:%d",keni);
}
/***************************************************************/
int kratisi_kenis()

{
    int i,j,k,numkra,found=0;
    char c,eponymo[40],onoma[15],tele[11]= {'\0'},str[11]= {'\0'};
    long long val;
    do
    {
        printf("Dwse ton arithmo thesis:");
        if (scanf("%d",&numkra)==1)
            // system("cls");// for Dos
            system("clear");// For Linux
        else numkra=getchar();
    }
    while(numkra < 1 || numkra >seats);


    for(i=0; i<seats; i++)
    {
        if (strcmp(passenger[i].name,adeio)==0 && passenger[i].thesis==numkra)
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
            strcpy(passenger[i].name,eponymo);
            passenger[i].thesis=numkra;
            fflush(stdin);
            /*********/
            printf("Dwse to tilefono tou epivati me 10 numbers:");
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
                passenger[i].phone[k]=val%10;
                val =val/10;
            }

        }
    }
    if (found==0) printf("H thesi einai kratimeni");
    return 0;
}
/***************************************/
int akirosi_thesis()
{
    int i,j,numaki=0,akyrosi=0;
    do
    {
        printf("Dwse ton arithmo thesis gia AKYROSI:");
        if (scanf("%d",&numaki)==1)
        {
            // system("cls");// for Dos
            system("clear");// For Linux
        }
        else numaki=getchar();

    }
    while(numaki<1 ||numaki>seats);

    for(i=0; i<seats; i++)
    {
        if ((passenger[i].thesis==numaki) && (strcmp(passenger[i].name,adeio)==1))
        {
            printf("NAI i thesi %d itan  kratimeni apo ton epivati :%s\n",numaki,passenger[i].name);
            printf("\nOK i thesi AKYROTHIKE\n");
            strcpy(passenger[i].name,adeio);
            akyrosi=1;

        }
    }
    if (akyrosi=0) printf("OXI den ginetai akirosi giati i thesi %d einai keni",numaki);
    return 0;
}

/**************************************/

void menu_listas()
{

    int choice;

    while (choice != 3)
    {
        printf("\n\n\n");
        printf("     **********************************\n");
        printf("     *      Epiloges  Listas          *\n");
        printf("     *        Taxinomisi              *\n");
        printf("     *   1.Me tin thesi               *\n");
        printf("     *   2.Me to onomatepwnymo        *\n");
        printf("     *                                *\n");
        printf("     *   3.Epistrofi sto Main Menu    *\n");
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
                lista_kata_thesi();
                break;
            case 2:
                //system("cls");// for Dos
                system("clear");// For Linux
                lista_kata_onoma();
                break;

            }
        }
    }
}


/**************************************/
int lista_kata_thesi()

{
    int i,j;

    struct stoixeia tempthesis;
    for (i = 1; i < seats; i++)
        for (j = 0; j < seats - i; j++)
        {
            if (passenger[j].thesis> passenger[j + 1].thesis)
            {
                tempthesis = passenger[j];
                passenger[j] = passenger[j + 1];
                passenger[j + 1] = tempthesis;
            }
        }


    for(i=0; i<seats; i++)
    {

        if (strcmp(passenger[i].name,adeio)==1)
        {
            printf("\n%s %d ",passenger[i].name,passenger[i].thesis);
            for(j=0; j<10; j++)
                printf("%u",passenger[i].phone[j]);
        }

    }



    return 0;
}

/****************************************/
/*Sort listas kata onomatepwnymo             */

int lista_kata_onoma()
{
    int i,j;

    struct stoixeia temp;
    for (i = 1; i < seats; i++)
        for (j = 0; j < seats - i; j++)
        {
            if (strcmp(passenger[j].name, passenger[j + 1].name) > 0)
            {
                temp = passenger[j];
                passenger[j] = passenger[j + 1];
                passenger[j + 1] = temp;
            }
        }


    for(i=0; i<seats; i++)
    {

        if (strcmp(passenger[i].name,adeio)==1)
        {
            printf("\n%s %d ",passenger[i].name,passenger[i].thesis);
            for(j=0; j<10; j++)
                printf("%u",passenger[i].phone[j]);
        }

    }
    return 0;
}

/**************************************************/
int read_txt()
{
    int i,j,k;
    char pinakida[40],str1[25],str2[15];//Diabasma tou onomateponymou  se eponymo kai onoma
    unsigned int num;
    // unsigned short num2;
    FILE *fap;
    fap=fopen("bus.txt","r");
    if (fap==NULL)
    {
        printf("ERROR FILE");
        exit(1);
    }
    fscanf(fap,"%s %u ",pinakida,&seats);
    printf("%s  %u\n",pinakida,seats);


    for(i=0; i<seats; i++)
    {
        if (strcmp(passenger[i].name,adeio)==0)
        {

            fscanf(fap,"%s %s %u",str1,str2,&num);
            if (feof(fap)) break;

            strcat(str1," ");
            strcat(str1,str2);

            strcpy(passenger[num-1].name,str1);//To stoixeio[0]=me tin 1 thesi
            printf("%s ",passenger[num-1].name);
            passenger[num-1].thesis=num;
            printf("%u ",passenger[num-1].thesis);

            for(j=0; j<10; j++)
            {
                fscanf(fap,"%1hu",&passenger[num-1].phone[j]);
                printf("%hu",passenger[num-1].phone[j]);
            }
            printf("\n");
            if (feof(fap)) break;

        }
    }

    fclose(fap);
    return 0;
}
/*********************************/
void add_node_to_list( char names[], unsigned int thes, unsigned short phon[])

{

    int i;

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    strcpy(temp->name,names);
    temp->thesis=thes;
    for(i=0; i<10; i++)
    {
        temp->phone[i]=phon[i];
    }
    temp->next=NULL;
    if(list_head==NULL)
    {
        list_head=temp;
        end=temp;
        return;
    }
    end->next=temp;
    end=temp;
}


/**********************************/
void make_list()
{
    int i,j,cnt;
    /*taxinomisi kata onomateponymo*/
    struct stoixeia temp;
    for (i = 1; i < seats; i++)
        for (j = 0; j < seats - i; j++)
        {
            if (strcmp(passenger[j].name, passenger[j + 1].name) > 0)
            {
                temp = passenger[j];
                passenger[j] = passenger[j + 1];
                passenger[j + 1] = temp;
            }
        }

    for(i=0; i<seats; i++)
    {
        if (strcmp(passenger[i].name,adeio)==1)
        {
            add_node_to_list( passenger[i].name, passenger[i].thesis, passenger[i].phone);//Kalesma tis synartisis gia dimiourgia node
        }

    }

}

/**************/
void display_all_nodes()
{
    p=list_head;
    while(p!=NULL)
    {
        puts(p->name);
        p=p->next;
    }
    apothikefsi_txt();//Apothikefsi Tis listas se arxeio txt
}
/*********************************************/
void  apothikefsi_txt()
{
    int i,j;
    char pinakida[40]="HHH1234";
    unsigned int seats=53;
    FILE *fap;
    fap=fopen("bus.txt","w");
    if (fap==NULL)
    {
        printf("ERROR FILE");
        exit(1);
    }
    fprintf(fap,"%s ",pinakida);
    fprintf(fap,"%u\n",seats);


    p=list_head;
    while(p!=NULL)
    {
        fprintf(fap,"%s ",p->name);
        fprintf(fap,"%u ",p->thesis);
        for(j=0; j<10; j++)
        {
            fprintf(fap,"%hu",p->phone[j]);
        }
        fprintf(fap,"\n");
        p=p->next;
    }

    fclose(fap);
}

