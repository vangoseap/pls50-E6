/* Author: Tsouramanis Evangelos
   Thema1: Apli arithmomixani */

#include <stdio.h>

void main() {

	double num1,num2;
	char praxi;


	printf("Arithmomixani me praxeis + - * / \n\n");
	printf ("Dwse arithmos: praxi: arithmos: ");

	if (scanf("%lf %c %lf",&num1,&praxi,&num2)==3) {
		if (praxi=='/') {
			if (num2==0) printf("\n Lathos adynati i diairesi me to 0\n\n");
			else printf("\napotelesma =%.2lf\n\n",num1/num2);
		} else if (praxi=='+') printf("\napotelesma =%.2lf\n\n",num1+num2);
		else if (praxi=='-') printf("\napotelesma =%.2lf\n\n",num1-num2);
		else if (praxi=='*') printf("\napotelesma =%.2lf\n\n",num1*num2);
		else printf("\nLathos \n");
	} else
		printf("\nLathos \n");
	system("pause");
	
}
