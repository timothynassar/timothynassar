//final1.c
//Timothy Nassar
//19990998
//U66969821

#include <stdio.h>
void determinant();
int main(void){
	determinant();
getchar();
return 0;
}
void determinant(){
	float matrix[3][3];
	int k,l;
	for(k=0; k<3; k++){
			for(l=0; l<3; l++){	
			printf("Please type row [%d] column [%d] entry of a [%d] x [%d] matrix => ", k+1, l+1, 3, 3 );
			scanf(" %f", &matrix[k][l]);
			}
		}
		printf("\n");
		printf("Here is your matrix!\n");
	int m, n;
		for(m=0; m<3; m++){
			printf("|");
			for(n=0;n<3;n++){
				printf(" %.2f", matrix[m][n]);
			}
			printf(" |\n");
		}
	float DET;
	DET = matrix[0][0]*((matrix[1][1]*matrix[2][2])-(matrix[1][2]*matrix[2][1])) - matrix[0][1]*((matrix[1][0]*matrix[2][2])-(matrix[1][2]*matrix[2][0])) + matrix[0][2]*((matrix[1][0]*matrix[2][1])-(matrix[1][1]*matrix[2][0]));
	printf("The determinant of your matrix is %f", DET);
}
