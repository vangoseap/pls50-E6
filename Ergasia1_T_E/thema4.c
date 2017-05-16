/* Author: Tsouramanis Evangelos
   Thema4: Systima katagrafis kratimenwn thesewn*/


#include <stdio.h>
#include <stdlib.h>

void arxikopoiisi_bus();
void arithmisi_thesewn();
void emfanisi_menu();
void emfanisi_symbolwn();
void kratisi_thesis();
void akyrosi_thesis();
void anazitisi_thesis();
void emfanisi_kenwn();
void kratisi_parathiro();
void emfanisi_kratimenwn();
void apothikefsi_txt();



int line,arithmisi,seats;
int bus[13][5];
int thesis[13][5];

char str[7];


int main() {
	arxikopoiisi_bus();
	emfanisi_menu();
	return 0;
}


/*************************************************************************/
/*Anoigma kai diavasma tou  bustext.txt-- emfanisi pinakidas kai thesewn*/

void arxikopoiisi_bus() {
	int diad,ypol,i,j;

	FILE *fp;
	fp=fopen("bustext.txt","r");
	if (fp==NULL) {
		printf("ERROR NO FILE");
		exit(1);
	}
	fscanf(fp,"%s %d",str,&seats);
	fclose(fp);

	/*Taktopioisi twn thesewn ston pinaka*/
	if (seats>=5 && seats<=53) {
		diad=seats-5;
		ypol=diad%4;

		if(ypol==0) line=diad/4;
		else {
			printf("\nMH APODEKTOS gia taktopoiisi, o arithmos twv thesewv tou leoforeiou\n");
			exit(1);
		}

	} else {
		printf("\nMH APODEKTOS o arithmos twv thesewv tou leoforeiou\nDwse theseis  anamesa se  min=5 kai  max=53\n");
		exit(2);
	}

	for (i=0; i<line+1; i++)
		for (j=0; j<5; j++)
			bus[i][j]=0; /*Arxikopoiisi tou pinaka bus[][] me 0*/
	for(i=0; i<line; i++)
		bus[i][2]=' ';
}

/*****************************/
/* Arxiki Arithmisi thesewn */

void arithmisi_thesewn() {
	int i,j;

	arithmisi=1;
	for (i=0; i<line+1; i++) {
		for (j=0; j<5; j++) {
			if (i<line && j==2) {
				bus[i][2]=' ';
				thesis[i][2]=' ';
			} else if (bus[i][j]==0 ||bus[i][j]==1)
				thesis[i][j]=arithmisi++;
		}
	}
}
/*****************************/
/*To basiko Menu-Epiloges   */

void emfanisi_menu() {
	int choice;


	while (choice != 9) {
		printf("\n");
		printf("****************************************************\n");
		printf("*                 Epiloges-Menu                    *\n");
		printf("* 1.Emfanisi me tous arithmous twn kenwn thesewn   *\n");
		printf("* 2.Kratisi kenis thesis                           *\n");
		printf("* 3.Evresi kai kratisi kenis thesis sto parathiro  *\n");
		printf("* 4.Akyrosi kratimenis thesis                      *\n");
		printf("* 5.Anazitisi kratimenis thesis                    *\n");
		printf("* 6.Emfanisi lista kratimenwn thesewn              *\n");
		printf("* 7.Emfanisi pinakidas kai diagramma               *\n");
		printf("* 8.Apothikefsi se arxeio txt                      *\n");
		printf("* 9.Telos                                          *\n");
		printf("****************************************************\n");
		printf("\n Epilogi apo to  menu :");
		if (scanf("%d", &choice)==1) {
			system("cls");// for Dos
			//system("clear");// For Linux
		} else choice=getchar();
		system("cls");
		//system("clear");

		if (choice>=1 && choice<=8) {
			switch (choice) {
				case 1:
					emfanisi_kenwn();
					break;
				case 2:
					system("cls");// for Dos
					//system("clear");// For Linux
					emfanisi_kenwn();
					kratisi_thesis();
					break;
				case 3:
					kratisi_parathiro();
					break;
				case 4:
					akyrosi_thesis();
					break;
				case 5:
					anazitisi_thesis();
					break;
				case 6:
					emfanisi_kratimenwn();
					break;
				case 7:
					system("cls");// for Dos
					// system("clear");// For Linux
					printf("%s %d\n\n",str,seats);
					emfanisi_symbolwn();
					break;
				case 8:
					apothikefsi_txt();
					break;
			}
		}
	}
}


/****************************************************/
/* Emfanisi twn symbolwn  _ or * kai metritis kenwn*/

void emfanisi_symbolwn() {
	int i,j,keni,kratimeni;

	keni=0;
	kratimeni=0;
	for (i=0; i<line+1; i++) {
		for (j=0; j<5; j++) {
			if(i<line && j==2) printf("%c\t",bus[i][2]);
			else if(bus[i][j]==0) {
				keni++;
				printf("_\t");
			} else if (bus[i][j]==1) {
				printf("*\t");
				kratimeni++;
			}
		}
		printf("\n");
	}
}

/************************************/
/* Kratisi thesis me  elegxo kenis */

void kratisi_thesis() {
	int numkra;
	int i,j;

	do {
		printf("\nDwse ena arithmo gia kratisi kenis thesis:");
		if (scanf("%d",&numkra)==1) {
			system("cls");// for Dos
			// system("clear");// For Linux
		} else numkra=getchar();
		system("cls");// for Dos
		//system("clear");
	} while (numkra<1 && numkra > seats);

	arithmisi_thesewn();


	for (i=0; i<line+1; i++) {
		for (j=0; j<5; j++) {
			if( bus[i][j]==0  && thesis[i][j]==numkra) {
				bus[i][j]=1;
				printf("\nNAI i thesi %d KRATITHIKE\n",numkra);
			} else if(bus[i][j]==1 && thesis[i][j]==numkra)
				printf("\n\nOXI i thesi %d einai KRATIMENI dialexe alli thesi\n",numkra);
		}
	}
}


/**************************************/
/* Akyrosi thesis me elegxo tis kenis*/

void akyrosi_thesis() {
	int numakiro,i,j;

	do {
		printf("\nDwse ton arithmo   gia akyrosi thesis:");
		if  (scanf("%d",&numakiro)==1) {
			system("cls");// for Dos
			// system("clear");// For Linux
		} else numakiro=getchar();
		system("cls");// for Dos
		//	system("clear");// For Linux
	} while (numakiro<1 && numakiro > seats);

	arithmisi_thesewn();

	for (i=0; i<line+1; i++) {
		for (j=0; j<5; j++) {
			if( bus[i][j]==1  && thesis[i][j]==numakiro) {
				bus[i][j]=0;
				printf("\nNAI i thesi %d AKYROTHIKE\n",numakiro);
			} else if(bus[i][j]==0 && thesis[i][j]==numakiro)
				printf("\n\nOXI i thesi %d einai keni dialexe alli thesi gia akyrosi\n\n",numakiro);
		}
	}
}
/********************************************/
/* Anazitisi kratimenis thesis me elegxo   */

void anazitisi_thesis() {
	int numanazitisi,i,j;
	do {
		printf("\nDwse ton arithmo gia anazitisi kratimenis thesis:");
		if (scanf("%d",&numanazitisi)==1) {
			system("cls");// for Dos
			// system("clear");// For Linux
		} else numanazitisi=getchar();
		system("cls");
		//system("clear");
	} while (numanazitisi<1 && numanazitisi > seats);

	arithmisi_thesewn();

	for (i=0; i<line+1; i++) {
		for (j=0; j<5; j++) {
			if( bus[i][j]==1  && thesis[i][j]==numanazitisi)
				printf("\n\nNAI i thesi %d einai KRATIMENI\n\n",numanazitisi);
			else if(bus[i][j]==0 && thesis[i][j]==numanazitisi)
				printf("\n\nOXI  i thesi %d den einai KRATIMENI \n\n",numanazitisi);
		}
	}
}

/*******************************************************/
/*Emfanisi tou synolou kenwn thesewn me tous arithmous*/

void emfanisi_kenwn() {
	int i,j,arithmken,keni;

	keni=0;

	for (i=0; i<line+1; i++) {
		for (j=0; j<5; j++) {
			if(bus[i][j]==0) keni++;
		}
	}
	printf("\n\nOi kenes theseis einai: %d\n\n",keni);

	arithmken=1;
	for (i=0; i<line+1; i++) {
		for (j=0; j<5; j++) {
			if (i<line && j==2) {
				bus[i][2]=' ';
				thesis[i][2]=' ';
			} else if (bus[i][j]==0 ||bus[i][j]==1 )
				thesis[i][j]=arithmken++;
			if(bus[i][j]==0) printf("%d ",thesis[i][j]);
		}
	}
	printf("\n");
}
//*******************************************//
/* Kratisi protis kenis thesis sto parathiro*/

void kratisi_parathiro() {
	int i;

	arithmisi_thesewn();

	for (i=0; i<line+1; i++) {
		if( bus[i][0]==0) {
			bus[i][0]=1;
			printf("\n\nNAI i thesi %d sto parathiro kratithike\n\n",thesis[i][0]);
			goto stop1;
		} else if (bus[i][4]==0) {
			bus[i][4]=1;
			printf("\n\nNAI i thesi %d sto parathiro kratithike\n\n",thesis[i][4]);
			goto stop1;
		} else if (bus[i][0]==1 || bus[i][4]==1)  continue;

	}
stop1 :
	printf(" ");
}

//*********************************//
// Emfanisi twn kratimenwn thesewn //

void emfanisi_kratimenwn() {
	int i,j,arithmkra,keni;
	keni=0;

	for (i=0; i<line+1; i++) {
		for (j=0; j<5; j++) {
			if(bus[i][j]==0) keni++;
		}
	}
	printf("\n\nOi kratimenes theseis einai:");

	arithmkra=1;
	for (i=0; i<line+1; i++) {
		for (j=0; j<5; j++) {
			if (i<line && j==2) {
				bus[i][2]=' ';
				thesis[i][2]=' ';
			} else if (bus[i][j]==0 ||bus[i][j]==1 )
				thesis[i][j]=arithmkra++;
			if (bus[i][j]==1) printf("%d ",thesis[i][j]);
		}
	}
	printf("\n");
}
/*************************************/
/* Apothikefsi se arxeio to diagramma*/

void apothikefsi_txt() {
	int i,j;

	FILE *fap;
	fap=fopen("layout.txt","w");
	if (fap==NULL) {
		printf("ERROR FILE");
		exit(1);
	}
	fputs(str,fap);
	fprintf(fap," %d\n",seats);

	for (i=0; i<line+1; i++) {
		for (j=0; j<5; j++) {
			if(i<line && j==2) fprintf(fap," ");
			else if(bus[i][j]==0) fprintf(fap,"_");
			else if (bus[i][j]==1) fprintf(fap,"*");
		}
		fprintf(fap,"\n");
	}

	fclose(fap);
}


