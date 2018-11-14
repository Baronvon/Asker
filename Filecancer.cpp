#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

#define colsize 100
#define rowsize 2

int main(){
	char filename[100];
	//if data is more then change array size, but I like to save space
	int array[rowsize][colsize];
	FILE *fp;

	//enter a filename
	printf("Enter a filename: ");
	scanf("%s",&filename);

	//checks if filename exists
	fp=fopen(filename,"r");
	if(fp==NULL){
		printf("file: %s does not exist",filename);
		return 1;
	}
	printf("file exists\n");

	//makes a 2d array of data
	int i=0;
	int j=0;
	int size=0;
	while(fscanf(fp,"%d",&array[i][j])!=-1){
		i=i+1;
		if(i==2){
			j=j+1;
			i=0;
		}
	}
	size=j;
	i=0;
	j=0;
	//reseting vars just in case
	//sum
	int fcolsum=0;	//first column sum
	int scolsum=0;	//second column sum
	int min[2][2];		//min [0][]=1st col, [1][]=2nd col
	int max[2][2];		//max
	double difference[100];	//difference between numbers for each year
	double dmin;	//min of difference
	double dmax;	//max of difference
	int dyear[2];	//years for min and max difference [0]=min [1]=max

	//I heard you like arrays so I made all arrays
	for(j=0;j<size;j++){
		//sum of first col
		fcolsum+=array[i][j];

		//DIFFERENCE between the two columns
		difference[j]=(double) abs(array[i][j]-array[i+1][j])/((array[i][j]+array[i+1][j])/2);
		//min of difference
		if(j==0||difference[j]<dmin){
			dmin=difference[j];
			dyear[0]=j+1;
		}
		//max of difference
		if(j==0||difference[j]>dmax){
			dmax=difference[j];
			dyear[1]=j+1;
		}

		//min of first col
		if(j==0||array[i][j]<min[0][0]){
			min[0][0]=array[i][j];
			min[0][1]=j+1;
		}
		//max of first col
		if(j==0||array[i][j]>max[0][0]){
			max[0][0]=array[i][j];
			max[0][1]=j+1;
		}

		i++;	//second col now
		//sum of second col
		scolsum+=array[i][j];
		//min of 2nd col
		if(j==0||array[i][j]<min[1][0]){
			min[1][0]=array[i][j];
			min[1][1]=j+1;
		}
		//max of 2nd col
		if(j==0||array[i][j]>max[1][0]){
			max[1][0]=array[i][j];
			max[1][1]=j+1;
		}
		i=0;	//reset to first col
		//next row
	}
	printf("%d\t%d\n",fcolsum,scolsum);

	fp=fopen("results.dat","w");
	//mean
	double average1=(double)fcolsum/size;
	double average2=(double)scolsum/size;
	//standard dev
	double stdev[1][2];
	for(j=0;j<size;j++){
		stdev[0][0]+=pow((array[i][j]-average1),2);
		i++;
		stdev[0][1]+=pow((array[i][j]-average2),2);
		i=0;
	}
	stdev[0][0]=sqrt(stdev[0][0]/(double)size);
	stdev[0][1]=sqrt(stdev[0][1]/(double)size);


	//Printing and writing to file
	printf("Fossil Fuel Consumption: FFC, Renewable Energy Consumption: REC\nThe following are in quadrillion Btu\n");
	fprintf(fp,"Fossil Fuel Consumption: FFC, Renewable Energy Consumption: REC\nThe following are in quadrillion Btu\n");
	printf("Standard Deviations:FFC:%6.3f REC:%6.3f\n",stdev[0][0],stdev[0][1]);
	fprintf(fp,"Standard Deviations:FFC:%6.3f REC:%6.3f\n",stdev[0][0],stdev[0][1]);
	printf("Averages:FFC:%6.3f REC:%6.3f\n",average1,average2);
	fprintf(fp,"Averages:FFC:%6.3f REC:%6.3f\n",average1,average2);
	printf("Minimums:FFC:%d REC:%d\nMaximums:FFC:%d REC:%d\n",min[0][0],min[1][0],max[0][0],max[1][0]);
	fprintf(fp,"Minimums:FFC:%d REC:%d\nMaximums:FFC:%d REC:%d\n",min[0][0],min[1][0],max[0][0],max[1][0]);
	printf("YEARS MIN:FFC min:%d REC min:%d\nYEARS MAX: FFC max:%d REC max:%d\n",min[0][1],min[1][1],max[0][1],max[1][1]);
	fprintf(fp,"YEARS MIN:FFC min:%d REC min:%d\nYEARS MAX: FFC max:%d REC max:%d\n",min[0][1],min[1][1],max[0][1],max[1][1]);
	printf("Difference min:%6.3f, year:%d\nDifference max:%6.3f, year:%d\n",dmin,dyear[0],dmax,dyear[1]);
	fprintf(fp,"Difference min:%6.3f, year:%d\nDifference max:%6.3f, year:%d\n",dmin,dyear[0],dmax,dyear[1]);
	fclose(fp);
	system("pause");
	return 0;
}
