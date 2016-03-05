/*
Name:Mehmet Mazhar SALIKCI
Number:111044050
Date:14.03.2014
homework:2
Introduction:
Bu program minor ve kofaktör yöntemlerini kullanarak determinanat bulur.
*/

/*NOTE*/
/*
Bu program recursive metoduyla determinant hesaplar.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
// default values
#define MATRIX_SIZE 6
#define VALUE_MIN 1
#define VALUE_MAX 5
// functions
/*matrisin determinantını recursive metoduyla bulma*/
double compute_determinant(int matrix[MATRIX_SIZE][MATRIX_SIZE],int n);
/*matrisimizi oluşturan fonksiyon*/
void matrix_create(int matrix[MATRIX_SIZE][MATRIX_SIZE], int min_val, int max_val);
/*elde ettigimiz matrisi ekrana basma*/
void matrix_print(int matrix[MATRIX_SIZE][MATRIX_SIZE]);
/*bir matrisi alt matrislere parçalama*/
void getSubMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE], int n, int i0, int B[MATRIX_SIZE][MATRIX_SIZE]);
// main function
int main(int argc, char *argv[])
{
	// variables
	int matrix[MATRIX_SIZE][MATRIX_SIZE];
	int row, column;
	// generate different numbers
	srand(time(NULL));
	// create a matrix with random numbers
	matrix_create(matrix, VALUE_MIN, VALUE_MAX);
	// print matrix
	matrix_print(matrix);
	// calculate determinant of matrix
	printf("Determinant of NxN Matrix:\t%f", compute_determinant(matrix,MATRIX_SIZE));
	return 0;
}
// compute determinent of matrix
double compute_determinant(int matrix[MATRIX_SIZE][MATRIX_SIZE],int n) {
	/*
	öncelikle bir alt matris elde etmek için bir matris tanımlarız.
	sonra tanımladığımız bu matrisi alt matris elde etmek için oluşturduğumuz fonksiyona yollarız.
	bu fonksiyonun döndürdüğü matrisi recursive fonksiyonumuza tekrardan yollarız.bu adımlar 1*1 lik 
	bir matris elde edene kadar devam ederiz.sonrada minör-kofaktörden yaralanarak bu herbir parçanın determinantını
	hesaplayıp toplarız.
	*/
	
	int i;				
	int det = 0;
    int detB;
    int sign;

    int B[MATRIX_SIZE][MATRIX_SIZE];/*alt matris elde etmek için oluşturduğumuz matris*/

    if(n == 1)
    {
        return matrix[0][0];
    }

    for(i = 0; i < n; i++)
    {
        sign = i % 2 ? 1 : -1;/*işlem sırasının işaretini belirleme*/

        getSubMatrix(matrix, n, i, B);/*alt matris elde etmek için bu fonksiyona ana matris yollanır*/

        detB = compute_determinant(B, n-1);

        det += (matrix[0][i] * detB * sign);
    }

	return det;
}
// print matrix
void matrix_print(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
	int row, column;

	for(row = 0; row < MATRIX_SIZE; row++) {
		for(column = 0; column < MATRIX_SIZE; column++) {
			printf("%d\t", matrix[row][column]);
		}
		printf("\n");
	}
}
// create matrix
void matrix_create(int matrix[MATRIX_SIZE][MATRIX_SIZE], int min_val, int max_val) {
	int row, column;
	srand(time(NULL));

	for(row = 0; row < MATRIX_SIZE; row++) {
		for(column = 0; column < MATRIX_SIZE; column++) {
			matrix[row][column] = (rand() % (max_val-min_val+1)) + min_val;
		}
	}
}
/*bir matrisi alt matrislere parçalama*/
void getSubMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE], int n, int i0, int B[MATRIX_SIZE][MATRIX_SIZE])
{
    int i, j;

    for(j = 1; j < n; j++)
    {
        for(i = 0; i < n; i++)
        {
            if(i < i0)
            {
                B[j-1][i] = matrix[j][i];
            }
            else if(i > i0)
            {
                B[j-1][i-1] = matrix[j][i];
            }
        }
    }
}
