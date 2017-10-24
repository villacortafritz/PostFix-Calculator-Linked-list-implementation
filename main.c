#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include "postfix.h"

int main(int argc, char *argv[]) {
	char st[20]="";
	float i=0.0;
	char loop;
	

	do{
		printf("Input postfix problem: ");
		gets(st);
		int errorcode=1;
		i=check(st, &errorcode);
		if(errorcode==1){
			printf("Answer = %.2f", i);
		}
		else if(errorcode==2){
			printf("Missing operand!");
		}
		else{
			printf("Missing operator!");
		}
		printf("\nRun again? y / n:");
		loop=getch(&loop);
		system("cls");
	}while(loop=='Y'|| loop =='y');
	
	
	return 0;
}
