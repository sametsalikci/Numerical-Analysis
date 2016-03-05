/**
  *	Author:Mehmet Mazhar SALIKCI 
  * Number:111044050 
  * 
  * Date:05.04.2014 
  *
  * Department: Computer Engineering
  * 
  * Description
  * -----------
  *	(x,F(x)) noktalarını kapsayacak şekilde interpolasyon yöntemiyle
  *	bir denklem bulup,bize verilen x noktalarına karşılık gelecek 
  *	f(x) değerlerini bulmak.
  */
#include <stdio.h>

//FUNCTIONS
/* Lagrange Interpolasyon Polinomlarin degerilerini hesaplama için
*  fonksiyonlar 													
*/
/* Fn(x) = (toplam sebbolü)Li(x) *f(Xi);
*  Li(x) = (çarpım sembolü)(X-Xj) / (Xi-Xj) ve Xi != Xj;
*  formülünün ugulanışı için gerekli 
*  fonksiyonlar 													
*/
double calculateLagrange0(double x[],double y[],double valueX);
double calculateLagrange1(double x[],double y[],double valueX);
double calculateLagrange2(double x[],double y[],double valueX);
double calculateLagrange3(double x[],double y[],double valueX);
double calculateLagrange4(double x[],double y[],double valueX);

//MAIN FUNCTION
int main(int argc, char const *argv[])
{	
	/*Variables*/
	double xValue;
	double lag0,lag1,lag2,lag3,lag4;
	double resultPolation = 0;
	/*Array variables*/
	double x[] = {40,50,60,70,80};// x degerlerim
	double y[] = {1.66,1.41,1.22,1.06,0.93};//f(x) degerlerimiz
	
	printf("\nBulmak istediğiniz F(x) degeri için bir x değeri giriniz:");
	scanf("\n%lf",&xValue);
	
	lag0 = calculateLagrange0(x,y,xValue);
	lag1 = calculateLagrange1(x,y,xValue);
	lag2 = calculateLagrange2(x,y,xValue);
	lag3 = calculateLagrange3(x,y,xValue);
	lag4 = calculateLagrange4(x,y,xValue);

	resultPolation = lag0 + lag1 + lag2 + lag3 + lag4;
	printf("result F(x):%f\n\n",resultPolation);

	return 0;
}
/*Lagrange Interpolasyon Polinomlarin denklemi = part1*/
double calculateLagrange0(double x[],double y[],double valueX)
{
	double L0,L1,L2,L3;
	double lagrange;
	
	L0 = (valueX-x[1]) / (x[0]-x[1]);
	L1 = (valueX-x[2]) / (x[0]-x[2]);
	L2 = (valueX-x[3]) / (x[0]-x[3]);
	L3 = (valueX-x[4]) / (x[0]-x[4]);

	lagrange = L0 * L1 * L2 * L3 * y[0];

	return lagrange;
}
/*Lagrange Interpolasyon Polinomlarin denklemi = part2*/
double calculateLagrange1(double x[],double y[],double valueX)
{	
	double L0,L1,L2,L3;
	double lagrange;

	L0 = (valueX-x[0]) / (x[1]-x[0]);
	L1 = (valueX-x[2]) / (x[1]-x[2]);
	L2 = (valueX-x[3]) / (x[1]-x[3]);
	L3 = (valueX-x[4]) / (x[1]-x[4]);

	lagrange = L0 * L1 * L2 * L3 * y[1];

	return lagrange;
}
/*Lagrange Interpolasyon Polinomlarin denklemi*/
double calculateLagrange2(double x[],double y[],double valueX)
{
	double L0,L1,L2,L3;
	double lagrange;

	L0 = (valueX-x[0]) / (x[2]-x[0]);
	L1 = (valueX-x[1]) / (x[2]-x[1]);
	L2 = (valueX-x[3]) / (x[2]-x[3]);
	L3 = (valueX-x[4]) / (x[2]-x[4]);

	lagrange = L0 * L1 * L2 * L3 * y[2];

	return lagrange;
}
/*Lagrange Interpolasyon Polinomlarin denklemi*/
double calculateLagrange3(double x[],double y[],double valueX)
{
	double L0,L1,L2,L3;
	double lagrange;

	L0 = (valueX-x[0]) / (x[3]-x[0]);
	L1 = (valueX-x[1]) / (x[3]-x[1]);
	L2 = (valueX-x[2]) / (x[3]-x[2]);
	L3 = (valueX-x[4]) / (x[3]-x[4]);

	lagrange = L0 * L1 * L2 * L3 * y[3];

	return lagrange;
}
/*Lagrange Interpolasyon Polinomlarin denklemi*/
double calculateLagrange4(double x[],double y[],double valueX)
{
	double L0,L1,L2,L3;
	double lagrange;

	L0 = (valueX-x[0]) / (x[4]-x[0]);
	L1 = (valueX-x[1]) / (x[4]-x[1]);
	L2 = (valueX-x[2]) / (x[4]-x[2]);
	L3 = (valueX-x[3]) / (x[4]-x[3]);

	lagrange = L0 * L1 * L2 * L3 * y[4];

	return lagrange;
}