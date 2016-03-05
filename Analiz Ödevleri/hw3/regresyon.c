/**
  *
  * Author:Mehmet Mazhar SALIKCI 
  * Number:SALIKCI 
  * 
  * Date:28.03.2014 
  *
  * Department: Computer Engineering
  * 
  * Description
  * -----------
  * bize verilen beş denkelem arasından BİZE VERİLEN NOKTALARI heseplayarak
  * en az hatayla çizilecek denklem bulma
  */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//MY FUNCTIONS

/**
  * Gets dataset from file and writes it into values.
  */
void getValues(double** values, int length, FILE* file);

/**
  * Finds the number of given dataset.
  */
int  getDataCount(FILE* file);/*Dosyadan bize verilen noktaları okur*/
void printFuncEquation(double a1,double a0);/* fonksiyon denkelmini ekrana basar */
void temelHesaplamar(double **array,int size,double *a1,double *a0,double *sumOfY);/*regresyon için gerekli hesepları yapar*/
double calcError(double **array,int size ,double a1,double a0,double sumOfYortalama);/*denklemin grafiksel hatasını hesaplar*/
void fillArray(double **ar,double array[][6],int size);/*denklemin başkatsayılarını matrise çevirme*/
void subMatrix(double ** arr ,double subArr[],int size);/*eşitliğin ağ tarafındaki matrisi bulma*/
void addArray(double arr[][6],double matr[],int size ,int indexCol);/*matrise kolon ekleme*/
double findCoefficient(double **array1,double **array2,int size);/*baş katsayı bulma*/
double compute_determinant(double matrix[][6],int MATRIX_SIZE);/*determinant hesaplama*/
double calcSrForFifthEquation(double **array3,double array[],int dataCount);/*sr hesaplama*/

/* *********START MAIN FUNTION********** */
int main(int argc, char* argv[])
{
	FILE* dataFile;
	double** values;
	double** array2;
	double array[6][6];
	double subArr[6];
	double coMatrix[6];
	double x = 0.0;
	double sumOfY;
	int i ,j;
	int dataCount = 0;
	double a1,a0;/*bilinmeyenler*/
	double det1 = 0,det2 =0;
	double sr1 = 0,st1 = 0,error1 = 0;
	double y = 0;
	if(argc != 2){
		printf("Usage: %s <datafile>\n", argv[0]);
		return 1;
	}

	/* Open file */
	dataFile = fopen(argv[1], "r");
	if(dataFile == NULL){
		printf("Error opening file!\n");
		return -1;
	}
	/* Find count of given dataset */
	dataCount = getDataCount(dataFile);
	rewind(dataFile);
	
	/*************************************************************
	**************************************************************
	********************FIRST EQUATION****************************/
	/* Allocates enough memory for the dataset */
	values = (double**)calloc(dataCount, sizeof(double*));
	for(i = 0; i < dataCount; ++i){
		values[i] = (double*)calloc(2, sizeof(double));
	}

	getValues(values, dataCount, dataFile); /* Get values from file */
	fclose(dataFile); /* Close file */
	
	printf("----------------\tfirst equation\t---------------\n");
	temelHesaplamar(values,dataCount,&a1,&a0,&sumOfY);
	y = sumOfY;/*bize verilen y lerin toplamı*/
	calcError(values,dataCount ,a1,a0,sumOfY);
	printf("\n\t\ty = (%f) + (%f) * x \n\n",a0,a1);/* fonksiyon denkelmini ekrana basar */
	
	/*************************************************************
	**************************************************************
	********************SECOND EQUATION****************************/
	/* Allocates enough memory for the dataset */
	array2 = (double**)calloc(dataCount, sizeof(double*));
	for(i = 0; i < dataCount; ++i){
		array2[i] = (double*)calloc(2, sizeof(double));
		
	}

	for (i = 0; i < dataCount; ++i)
	{
		for (j = 0; j < 2; ++j)
		{
			
			array2[i][j] = log(values[i][j]);
		}
	}
	printf("----------------\tsecond equation\t---------------\n");
	temelHesaplamar(array2,dataCount,&a1,&a0,&sumOfY);
	calcError(array2,dataCount ,a1,a0,sumOfY);
	printf("\n\t\tlog(y) = (%f) + (%f) * log(x) \n\n",a0,a1);/* fonksiyon denkelmini ekrana basar */

	/* Deallocate previously allocated memory */
	for(i = 0; i < dataCount; ++i){
		free(array2[i]);
	}
	 free(array2);
	/*************************************************************
	**************************************************************
	********************THIRD EQUATION****************************/
	array2 = (double**)calloc(dataCount, sizeof(double*));
	for(i = 0; i < dataCount; ++i){
		array2[i] = (double*)calloc(2, sizeof(double));
		
	}

	for (i = 0; i < dataCount; ++i)
	{
		for (j = 0; j < 2; ++j)
		{
			
			array2[i][j] = values[i][j];
			if(j == 1)
				array2[i][j] = log(values[i][j]);
		}

	}
	printf("----------------\tthird equation\t---------------\n");
	temelHesaplamar(array2,dataCount,&a1,&a0,&sumOfY);
	calcError(array2,dataCount ,a1,a0,sumOfY);
	printf("\n\t\tlog(y) = (%f) + (%f) * x \n\n",a0,a1);/* fonksiyon denkelmini ekrana basar */

	/* Deallocate previously allocated memory */
	for(i = 0; i < dataCount; ++i){
		free(array2[i]);
	}
	free(array2);

	/*************************************************************
	**************************************************************
	********************FOURTH EQUATION****************************/
	array2 = (double**)calloc(dataCount, sizeof(double*));
	for(i = 0; i < dataCount; ++i){
		array2[i] = (double*)calloc(2, sizeof(double));
		
	}

	for (i = 0; i < dataCount; ++i)
	{
		for (j = 0; j < 2; ++j)
		{
			
			array2[i][j] = values[i][j];
			if(j == 1)
				array2[i][j] = 1 / values[i][j];
		}

	}
	printf("----------------\tfourth equation\t---------------\n");
	temelHesaplamar(array2,dataCount,&a1,&a0,&sumOfY);
	calcError(array2,dataCount ,a1,a0,sumOfY);
	printf("\n\t\t1 / y = (%f) + (%f) * x \n\n",a0,a1);/* fonksiyon denkelmini ekrana basar */

	/* Deallocate previously allocated memory */
	for(i = 0; i < dataCount; ++i){
		free(array2[i]);
	}
	 free(array2);

	/*************************************************************
	**************************************************************
	********************FIFTH EQUATION****************************/
	fillArray(values,array,dataCount);
	subMatrix(values ,subArr,dataCount);
	det1 = compute_determinant(array,6);
	
	for (i = 0; i < 6; ++i){
		addArray(array,subArr,dataCount ,i);
		det2 = compute_determinant(array,6);
		coMatrix[i] = det2 / det1 ;
	}
	
	printf("----------------\tfifth equation\t---------------\n");
	sr1 = calcSrForFifthEquation(values,coMatrix,dataCount);
	for (i = 0; i < dataCount; ++i)
	{
		st1 += pow((array[i][1]-y),2);
	}
	printf("st:%f\n",st1);
	error1 = (sr1 - st1) / sr1;
	printf("Tahminin standart hatası: %.10f\n",error1);
	
	printf("\n\t%f + %fx + %f x^2 + %fx^3 + %fX^4 + %fx^5\n\n",coMatrix[0],coMatrix[1],coMatrix[2],
			coMatrix[3],coMatrix[4],coMatrix[5]);

	/* Deallocate previously allocated memory */
	for(i = 0; i < dataCount; ++i){
		free(values[i]);
	}
	free(values);
	 printf("\n\n\t\tVERİLEN DENKELEMLERİ EN İYİ TEMSİL EDEN DENKLEM\n");
	 printf("\tHATASI BİRE (1) YAKIN OLAN DENKLEMDİR\n\n");

	return 0; /* End of program */
}
void getValues(double** values, int length, FILE* file)
{
	double x, y;
	int index = 0;
	while(!feof(file) && index < length){
		fscanf(file, "%lf%lf", &x, &y);
		values[index][0] = x;
		values[index][1] = y;
		++index;
	}
	return;
}

int getDataCount(FILE* file)
{
	int count = 0;
	char c = ' ';
	while(!feof(file)){
		if((c = fgetc(file)) == '\n'){
			++count;
		}
	}
	return count;
}
void temelHesaplamar(double **array,int size,double *a1,double *a0,double *sumYortalama)
{	
	int i;
	double sumX=0,productYX,sumOfY=0;
	double sumXortalama,sumFarkY = 0;
	double sumX2 = 0,a11,a12;
	
	/*verilen x lerin ortalaması*/
	for(i=0;i<size;++i){

		sumX += array[i][0];

	}
	sumXortalama = sumX / size;
	/*verilen y lerin degerleri toplamı*/
	sumOfY=0;
	for(i=0;i<size;++i){

		sumOfY += array[i][1];

	}
	*sumYortalama = sumOfY / size;
	
	/*x ve y nin çarpımlarının toplamı*/
	for(i=0;i<size;++i){

		productYX += array[i][0] * array[i][1];

	}
	
	/*y ve y nin ortalamasının farkı*/
	for(i=0;i<size;++i){

		sumFarkY += pow((array[i][1] - *sumYortalama),2);

	}
	
	for (i = 0; i < size; ++i){

		sumX2 += array[i][0] * array[i][0];
	}
	
	a11 = size * productYX - sumX * sumOfY;
	a12 = size * sumX2 - pow(sumX,2);
	
	*a1 = a11 / a12;
	*a0 = sumOfY - *a1 * sumX;
	printf("a1:%f\na0:%f\n",*a1,*a0);
}
double calcError(double **array,int size ,double a1,double a0,double sumOfYortalama)
{

	double Sr=0,St=0,r,function=0,error;
	int i;
	
	
	for(i=0;i<size;++i)
		St += pow((array[i][1] - sumOfYortalama),2);
	
	for(i=0;i<size;++i){
		function += array[i][1] - a1 - a0 * array[i][0];
		Sr += pow(function,2);
	}
		
		printf("\nSt:%f \nSr:%f\n",St,Sr);
		
		/*error = sqrt(Sr/(size-2));*/
		error = sqrt((Sr-St) / Sr);
		printf("Tahminin standart hatası:%.10f\n",error);
	return error;
}
void fillArray(double **ar,double array[][6],int size)
{
	double total = 0;
	int i,j,k;
	
	for(i=0;i<6;++i){
		for(j=0;j<6;++j){
			
			for (k = 0; k < size; ++k)
			{
				total+=pow(ar[k][0],i + j);
			}
			array[i][j] = total;
			total = 0;
			
		}
	}		
	
}
/*crammer yöntemiyle baş katsayıları hesaplanırken
*eşitliğin sağ tarafındaki değerleri bulma
*/
void subMatrix(double **arr ,double subArr[],int size)
{
	int i,j;
	double total = 0;

	for (i = 0; i < 6; ++i)
	{
		for (j = 0; j < size; ++j)
		{
			
			total += pow(arr[j][0],i) * arr[j][1];;
			
		}
		subArr[i]=total;
		total = 0;
	}
}
void addArray(double arr[][6],double matr[],int size ,int indexCol)
{
	int i;
	for (i = 0; i < size; ++i)
	{
		arr[i][indexCol] = matr[i];
	}

}
/*sr hesaplama*/
double calcSrForFifthEquation(double **array3,double array[],int dataCount)
{
	double sr = 0, sr1 = 0,sr2 = 0;
	int i;
	
	for (i = 0; i < dataCount; ++i)
	{
		sr1 = array3[i][1]-array[0]-array[1]*array3[i][0]-array[2]*pow(array3[i][0],2);
		sr2 = -array[3]*pow(array3[i][0],3)-array[4]*pow(array3[i][0],4)-array[5]*pow(array3[i][0],5);
		sr += pow(sr1 + sr2,2);
	}
	printf("Sr:%f\n",sr);
	return sr;
}
/*determinant hesaplama*/ 
double compute_determinant(double matrix[][6],int MATRIX_SIZE) 
{
	int i,j,k,m,index;			/*Declaration "for" statement variables */
	int n=0; /*satırların yerlerini degistirirken determinant eksi ile carpılması icin */
	double ratio,determinant=1.0,temp;  /*Declaration ratio and determinant variables */
	
	
	/*Compute determinant of matrix  */
	for(i=0;i<MATRIX_SIZE-1;++i)
	{
		for(j=i+1;j<MATRIX_SIZE;++j)
		{
			/*if first value=0 , this loop step chanege it.*/
			if(matrix[0][0] == 0.0)
			{	n++;
				
				for(m=0;m<MATRIX_SIZE;m++)
				{	
					for(k=1;k<MATRIX_SIZE;k++)
					{
						temp = matrix[0][m];
						matrix[0][m] = matrix[k][m];
						matrix[k][m] =  temp ;
						if(matrix[0][0] == 0.0)
						{
							n++;
							continue;
						}
					}
				}
			}	
			/*compute ratio */
			ratio = matrix[j][i] / matrix[i][i];
			for(k=0;k<MATRIX_SIZE;++k)
			{	
				/*compute every cordinate number */
				matrix[j][k] -= ratio * matrix[i][k];
			}			
		}
	}
	/*Compute determinant  */
	for(index=0;index<MATRIX_SIZE-1;++index)
		determinant *= matrix[index][index];
	
		/*sign for every change step matris */
		determinant *=pow(-1,n);
	
	/* return result of determinant */ 
	return determinant;
}