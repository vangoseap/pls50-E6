/* Author: Tsouramanis Evangelos
   Thema2: Geometrikoi ypologismoi */

#include <stdio.h>
#include <math.h>

#define pi 3.141592

float tetragwno(float x)
{
    float p_tetragwnou;
    p_tetragwnou=4*x;
    return(p_tetragwnou);
}

float parallililogrammo(float x, float y)
{
    float p_paralliligrammou=2*(x+y);
    return(p_paralliligrammou);
}

double orthogwnio_trigwno(float x,float y)
{
    double p_trigwnou;
    double t_riza;
    t_riza=sqrt(pow(x,2)+pow(y,2));
    p_trigwnou=x+y+t_riza;
    return(p_trigwnou);
}

float kyklos(float x)
{
    float p_kyklou;
    p_kyklou=2*pi*x;
    return(p_kyklou);
}

void main()
{

    int choice;
    float a,b,ptet,ppar,ptrig,pkyk;
    //system("clear");
     system("cls"); 
do {
  
  do{
    printf(" Ypologismos Perimetrou\n\n");
    printf(" 0. Telos\n");
    printf("\n");
    printf(" 1. Tetragwno\n");
    printf(" 2. Parallilogrammo\n");
    printf(" 3. Orthogwnio trigwno\n");
    printf(" 4. Kyklos\n");
    printf("\n");             
    
    printf("\nDwse epilogi sximatos :");
    
     scanf("%d",&choice) ; 
     system("cls");// for DOS
     //system("clear");// for Linux
        
  }while(choice<0 || choice >4);

    switch (choice){
      case 0:
        printf("Exodos\n");
        break; 
      case 1:
        printf("\nDwse to mikos tis plevras tou tetragwnou:");
        if (scanf("%f",&a)==1){
        ptet=tetragwno(a);
        printf("\nH perimetros tou tetragwnou einai :%.3f\n",ptet);
        }
        else printf("\n\nError\n");
        getchar();
        break;
    
      case 2: 
        printf("\nDwse to mikos kai to platos tou parallilogrammou:");
        if (scanf("%f %f",&a,&b)==2){
        ppar=parallililogrammo(a,b);
        printf("\nH perimetros tou parallilogrammou einai:%.3f\n",ppar);
        }
        else printf("\n\nError\n");
        getchar();
        break; 
    
      case 3:
        printf("\nDwse tis dyo kathetes plevres tou orthogwniou trigwnou:");
        if (scanf("%f %f",&a,&b)==2){
        ptrig=orthogwnio_trigwno(a,b);
        printf("\nH perimetros tou orthogwniou trigwnou einai :%.3f\n",ptrig);
        }
        else printf("\n\nError\n");
        getchar();
        break;
      case 4:
        printf("\nDwse tin aktina tou kyklou:");
        if (scanf("%f",&a)==1){
        pkyk=kyklos(a);
        printf("\nH perimetros tou kyklou einai:%.3f\n",pkyk);
        }
         else printf("\n\nError\n");
        getchar();
        break;
       
       }
        printf("\n");
      } while (choice!=0);    
 
}


