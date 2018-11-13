#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>


void function1(){
	printf("Group number: 33\n\n11/12/18\nPurpose is to add, subtract, multiply, or divide these two numbers and display the results to the screen as well as a file");
}
int function2(int pos){
	int num;
	printf("\nEnter a value for number %d: ",pos);
	scanf("%d",&num);
	return num;
}
int function3(){
	int choice=0;
	bool moron=false;

	do{
		if(moron){
			printf("That's not one of the options :), please enter a correct number\n");
		}
		printf("Whatcha wanna do with yer numbers m8y\nType in one of the following numbers\n1.Add\n2.Subtract\n3.Multiply\n4.Divide\n");
		scanf("%d",&choice);
		moron=true;
	}while(choice>4||choice<1);
	return choice;
}
double function4(int userchoice,int num1,int num2){
	switch(userchoice){
		case 1:
		return num1+num2;
		break;

		case 2:
		return num1-num2;
		break;

		case 3:
		return num1*num2;
		break;

		case 4:
		return num1/num2;
		break;
	}
}
void function5(int userchoice,int num1,int num2,double answer){
	FILE *fp;
	fp=fopen("results.txt","w");
	switch(userchoice){
		//Add
		case 1:
		printf("%d + %d = %f",num1,num2,answer);
		fprintf(fp,"%d + %d = %f",num1,num2,answer);
		break;

		//Subtract
		case 2:
		printf("%d - %d = %f",num1,num2,answer);
		fprintf(fp,"%d - %d = %f",num1,num2,answer);
		break;

		//Multiply
		case 3:
		printf("%d * %d = %f",num1,num2,answer);
		fprintf(fp,"%d * %d = %f",num1,num2,answer);
		break;

		//Divide
		case 4:
		printf("%d / %d = %f",num1,num2,answer);
		fprintf(fp,"%d / %d = %f",num1,num2,answer);
		break;
	}
	fclose(fp);
}
int main(){
	int num1;
	int num2;
	int userchoice;
	double answer;
	char again;
	bool doagain;
	bool hewantsthenum;

	hewantsthenum=true;
	function1();
	do{
		doagain=false;
		if(hewantsthenum){
			num1=function2(1);
			num2=function2(2);
		}
		userchoice=function3();
		answer=function4(userchoice,num1,num2);
		function5(userchoice,num1,num2,answer);
		//use numbers again
		while(true){
			printf("\nWant to use the numbers again?(y/n)");
			scanf(" %c",&again);
			again=toupper(again);
			if(again=='Y'){
				doagain=true;
				hewantsthenum=false;
				break;
			}
			else if(again=='N'){
				break;
			}
			else{
				printf("\nNot a valid character");
			}
		}
		//use new numbers if same numbers again is false
		while(doagain!=true){
			printf("\nWant to use new numbers?(y/n)");
			scanf(" %c",&again);
			again=toupper(again);
			if(again=='Y'){
				doagain=true;
				hewantsthenum=true;
			}
			else if(again=='N'){
				break;
			}
			else{
				printf("\nNot a valid character");
			}
		}
	}while(doagain);
	system("pause");
	return 0;
}
