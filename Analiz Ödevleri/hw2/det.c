/*

 Ramazan ÇUBUKCI
 08104416

 nxn Matrisin determinantýný hesaplayan program

*/
#include <stdio.h>

#define MAX_SIZE    20

double calcDet(double A[MAX_SIZE][MAX_SIZE], int n);

void getSubMatrix(double A[MAX_SIZE][MAX_SIZE], int n, int i0, double B[MAX_SIZE][MAX_SIZE]);
void printMatrix(double A[MAX_SIZE][MAX_SIZE], int n);

int main()
{
    int i, j;
    int n;
    double A[MAX_SIZE][MAX_SIZE];
    double detA;

    printf("Enter matrix size:");
    scanf("%d", &n);


    for(j = 0; j < n; j++)
    {
        for(i = 0; i < n; i++)
        {
            printf("matrix %d %d . value : ", i, j);
            scanf("%lf", &(A[j][i]));
        }
    }

    printf("\nThe given matrix is :\n");
    printMatrix(A,n);

    if(n <= 0 || n > MAX_SIZE)
    {
        printf("n: %d is not good!\n", n);
        return 0;
    }

    detA = calcDet(A, n);

    printf("\ndet(A) = %.1lf \n", detA);

    if(detA == 0)
    {
        printf("infinite solution...\n");
    }

}

double calcDet(double A[MAX_SIZE][MAX_SIZE], int n)
{
    int i;

    double det = 0;
    double detB;
    int sign;

    double B[MAX_SIZE][MAX_SIZE];

    if(n == 1)
    {
        return A[0][0];
    }

    for(i = 0; i < n; i++)
    {
        sign = i % 2 ? 1 : -1;

        getSubMatrix(A, n, i, B);

        detB = calcDet(B, n-1);

        det += (A[0][i] * detB * sign);
    }

    return det;
}

void getSubMatrix(double A[MAX_SIZE][MAX_SIZE], int n, int i0, double B[MAX_SIZE][MAX_SIZE])
{
    int i, j;

    for(j = 1; j < n; j++)
    {
        for(i = 0; i < n; i++)
        {
            if(i < i0)
            {
                B[j-1][i] = A[j][i];
            }
            else if(i > i0)
            {
                B[j-1][i-1] = A[j][i];
            }
        }
    }
}

void printMatrix(double A[MAX_SIZE][MAX_SIZE], int n)
{
    int i, j;

    for(i=0; i<n; ++i)
    {
        for(j=0; j<n; ++j)
        {
            printf("%.3lf ", A[i][j]);
        }
        printf("\n");
    }
}
