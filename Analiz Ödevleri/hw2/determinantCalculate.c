/*
Name:Mehmet Mazhar SALIKCI
Number:111044050
Date:14.03.2014
homework:2
Introduction:
Bu program minor ve kofaktör yöntemlerini kullanarak determinanat bulur
*/

/*NOTE*/
/*
Bu program recursive metoduyla determinant hesapladığı için verimli bir şekilde çalışmayabilir.
Çok buyük matrislerde yavaş çalışabilir.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
// default values
#define MATRIX_SIZE 20
#define VALUE_MIN 1
#define VALUE_MAX 5
// functions

/*matrisin determinantını recursive metoduyla bulma*/
int compute_determinant(double **matrix,int size);
/*matrisimizi oluşturan fonksiyon*/
double** matrix_create(double** matrix, int min_val, int max_val);
/*elde ettigimiz matrisi ekrana basma*/
void matrix_print(double **matrix);

// main function
int main(int argc, char *argv[])
{
	// variables
	double** matrix;
	int row, column;
	// generate different numbers
	srand(time(NULL));
	// create a matrix with random numbers
	matrix = matrix_create(matrix, VALUE_MIN, VALUE_MAX);
	// print matrix
	matrix_print(matrix);
	// calculate determinant of matrix
	printf("Determinant of NxN Matrix:\t%d\n", compute_determinant(matrix,MATRIX_SIZE));
	
	/*system("PAUSE");*/
	return 0;
}
// compute determinent of matrix
int compute_determinant(double **matrix,int size) 
{
	/*Determinant hesaplarken iki boyutlu dinamik bir array elde etmek için
	bize verdiğiniz prototype ları biraz değiştirmek zorunda kaldım
	*/
	// write your HW code HERE!
	
	/*Variables*/
	int i,j,j1,j2;
	double determinant = 0;
  	double **m = NULL;
  	
  	if (size< 1) { /*Error*/
	} else if (size == 1) {/* condition 1 */
     	determinant = matrix[0][0];
   	} else if (size == 2) { /* condition */
      	determinant = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
   	} else {
      	determinant = 0;
      	for (j1=0;j1<size;j1++) {
         	m = (double**)malloc((size-1)*sizeof(double*));/*dinamik hafıza alımı*/
         	for (i=0;i<size-1;i++){
            	m[i] = (double*)malloc((size-1)*sizeof(double));/*dinamik hafıza alımı*/
            }
         	for (i=1;i<size;i++) {
            	j2 = 0;
            	for (j=0;j<size;j++) {
               		if (j == j1)
                  		continue;
               		m[i-1][j2] = matrix[i][j];
           			j2++;
            	}
        	}
         	determinant += pow(-1.0,1.0+j1+1.0) * matrix[0][j1] * compute_determinant(m,size-1);/*Recursive*/
		}
	}
   return(determinant);
}
// print matrix
void matrix_print(double **matrix) {
	int row, column;

	for(row = 0; row < MATRIX_SIZE; row++) {
		for(column = 0; column < MATRIX_SIZE; column++) {
			printf("%.2f\t", matrix[row][column]);
		}
		printf("\n");
	}
}
// create matrix
double** matrix_create(double** matrix, int min_val, int max_val) {
	int row, column;
	srand(time(NULL));
	int i = 0;
	
	matrix = (double**)malloc(MATRIX_SIZE * sizeof(double*));
	for(i = 0; i < MATRIX_SIZE; ++i){
		matrix[i] = (double*)malloc(MATRIX_SIZE * sizeof(double));
	}

	for(row = 0; row < MATRIX_SIZE; row++) {
		for(column = 0; column < MATRIX_SIZE; column++) {
			matrix[row][column] = (rand() % (max_val-min_val+1)) + min_val;
		}
	}
	return matrix;
}


