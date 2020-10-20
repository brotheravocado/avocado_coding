#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int row=0, col=0, i=0, j=0, **m1, **m2;
	
	printf("input row, col size: ");
	scanf("%d %d", &row, &col);
	
	m1 = (int **)malloc(sizeof(int *)*row);
	m2 = (int **)malloc(sizeof(int *)*row);
	
	//make matrix1 box
	for(i = 0; i<row; i++){
		m1[i] = (int *)malloc(sizeof(int)*col);
		m2[i] = (int *)malloc(sizeof(int)*col);
		}
	//make matrix1 num
	for( i=0; i<row; i++){
		for( j = 0; j<col;j++){
		m1[i][j]=(int)(20*(rand()/(RAND_MAX+1.0)));
		m2[i][j]=(int)(20*(rand()/(RAND_MAX+1.0)));
		}
	}
	//you can see the matrix1
	printf("-----------maxtrix1-------------\n");
	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){
			printf("%5d",m1[i][j]);	
		}printf("\n");
		}
	
	printf("-----------maxtrix2-------------\n");
	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){
			printf("%5d",m2[i][j]);	
		}printf("\n");
	}
	printf("-------maxtrix1 + matrix2-------\n");
	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){
			printf("%5d",m1[i][j]+m2[i][j]);	
		}printf("\n");
	}
	return 0;
	
	free(m1);
	free(m2);
}
