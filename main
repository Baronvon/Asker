#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#define MAXLENGTH 100

int main(){
	FILE *fp;
	char filename[MAXLENGTH];
	bool isfilename=false;
	do{
		printf("Gimme a file name: ");
		scanf("%s",&filename);
		fp=fopen(filename,"r");
		//asks for a filename then gives true or false based on whether file exists
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
	int *numbs[MAXLENGTH][MAXLENGTH];
	for(int x=0;x<MAXLENGTH;x++){
		for(int y=0; y<2;y++){
			fscanf(fp,"%d",numbs[x][y]);
		}
	}
	fclose(fp);
	return 0;
}
