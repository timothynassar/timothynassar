//final2.c
//19990998
//Timothy Nassar
//U66969821

#include<stdio.h>
#define THEFILE "Sensor_Record.txt"//Reading
#define THEFILE2 "Sensor_Record_Modified.txt"//Writing

int main(void){

FILE *fp;//Assign a pointer for FILE
	fp = fopen(THEFILE, "r");//Open Sensor_Record.txt
	float imp[10][4];//assign an array of float type for the the opened file
	int i, j;//assign counting variables to read through the opened .txt file
	
for(i=0; i<10; i++){
	for(j=0; j<4; j++){
	fscanf(fp, "%f", &imp[i][j]);
	}
}//For loop that reads Sensor_Record.txt and assigns values to te imp array
	printf("This is the original Sensor Record in Celcius scale with Glitches.\n");
//output the Sensor_Record.txt
for(i=0; i<10; i++){
	for(j=0; j<4; j++){
	printf("%.2f		", imp[i][j]);
	}
	printf("\n");
}
	printf("\n");
for(i=0; i<10; i++){
	for(j=0; j<4; j++){
		if(imp[i][j]>0){
	printf("Glitch effected=>	");
	printf("%.2f: row %d  column %d\n\n", imp[i][j], i+1, j+1);
	}
}
}//This For loop finds "glitches" in the file
//the glitches were some kind of condition on the paper my professor gave
char mode;//assign a character type variable to decide whether to write or append the file
printf("Would you like to write(w) to the file, or append(a)?");
scanf(" %c", &mode);
printf("\n\n");
FILE *fpp;//File pointer for Sensor_Record_Modified.txt
switch(mode){
		case'W':case'w':
			fpp = fopen(THEFILE2, "w");//write to Sensor_Record_Modified.txt
			break;	
					
		case'A':case'a':
			fpp = fopen(THEFILE2, "a");//append Sensor_Record_Modified.txt
			break;
			
		default:
			printf("That was neither an A or a W, you Dummy\n\n");
			break;
}
float imp_mod[10][8];//assigning a float array for the new modified .txt document
int k, l;//counting variables
for(i=0; i<10; i++){
	for(j=0; j<4; j++){
		if(imp[i][j]>0){
			imp_mod[i][j]=-1*imp[i][j];//this part modifies "glitches"
		}
		else{
			imp_mod[i][j]=imp[i][j];//This part leaves "glitches" as is
		}
	}
	for(j=4; j<8; j++){
		if(imp[i][j-4]>0){
		imp_mod[i][j]=(((-1)*imp[i][j-4]*9)/5)+32;//Temperature conversion
	}
		else{
		imp_mod[i][j]=((imp[i][j-4]*9)/5)+32;//Temperature conversion
	}
	}
}
for(i=0; i<10; i++){
	for(j=0; j<8; j++){
	fprintf(fpp, "%.2f	", imp_mod[i][j]);
	}
	fprintf(fpp, "\n");
}
	fprintf(fpp, "\n");
printf("This is the modified Sensor Record in Farenheit scale(Glitches Adjusted).\n\n\n");

fpp = fopen(THEFILE2, "r");
for(i=0; i<10; i++){
	for(j=0; j<8; j++){
	fscanf(fp, "%f", &imp_mod[i][j]);
	}
}
for(i=0; i<10; i++){
	for(j=0; j<8; j++){
	printf("%.2f	", imp_mod[i][j]);
	}
	printf("\n");
}
	printf("\n");
printf("The result is saved in Sensor_Record_Modifieid.txt\n");
 fclose(fpp);
getchar();
return 0;
}
//Enjoy!
