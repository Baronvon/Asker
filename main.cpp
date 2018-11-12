#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#define MAXLENGTH 150
#define MAXCOLUMNS 2
/*	Reads in a file of integers to store into a 2d array
	Must be seperated by a whitespace for each column
	of max size 100,2
*/
//returns the min of the numbers in each column
int min(int num[]){
	int min=num[0];
	for(int x=0;x<sizeof(num);x++){
		if(num[x]<min){
			min=num[x];
		}
	}
	return min;
}
//returns the max of the numbers in each column
int max(int num[]){
	int max=num[0];
	for(int x=0;x<sizeof(num);x++){
		if(num[x]>max){
			max=num[x];
		}
	}
	return max;
}
//average of each column
double mean(int num[]){
	int mean=0;
	for(int x=0;x<sizeof(num);x++){
		mean+=num[x];
	}
	return mean;
}
//standard deviation of each column
double stdev(){
	return 0;
}
//runs the program, asks for a file location
int main(){
	FILE *fp;
//must be less than MAXLENGTH value
	char filename[MAXLENGTH];
	bool isfilename=false;

	do{
		//asks for a filename then gives true or false based on whether file exists
		printf("Gimme a file name: ");
		scanf("%s",&filename);
		fp=fopen(filename,"r");
		if(fp){
			printf("Your file exists\n");
			isfilename=true;
		}
		else{
			printf("Your file does not exist\n");
		}
	}while(fp==false);

//when file is true creates a 2d array here
//where x=rows and y= column of data
	int numbs[MAXLENGTH][MAXLENGTH];
	for(int x=0;x<MAXLENGTH;x++){
		for(int y=0; y<MAXCOLUMNS;y++){
			fscanf(fp,"%d",&numbs[x][y]);
		}
	}

	for(int y=0;y<MAXCOLUMNS;y++){
		//create 1d arrays from a 2d a array here
		printf("%d",mean(numbs));
	}


	fclose(fp);
	system("pause");
	return 0;
}
