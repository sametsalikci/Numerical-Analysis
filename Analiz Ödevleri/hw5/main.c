/*
Homework5:Numerical Analysis
Name:Mehmet Mazhar SALIKCI
Number : 111044050
*/
/*
## AÇIKLAMA:
		#a.Analitik
		#b.Yamuk kuralı ve hata
		#c.1/3 Simpson kuralı ve hata
		#d.3/8 Simpson kuralı ve hata
		#e.N = 2, 4, 10, 20 için Yamuk kuralı ve hata
		#f.N = 2, 4, 10, 20 için Simpson 1/3 kuralı ve hata
	Yöntemlerini kullanarak integral heseplama.
--f(x) = (15.3) ^ (2.5x) from a to b  [a = 0.00, b = 1.00];
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//GLOBALS
#define E_VALUE 2.71828182
#define UPPER_LIMIT 1.0
#define LOWER_LIMIT 0.0

//MY FUNCTIONS
double MyFunction(double x);
double calcIntegralWithAnalitical(double upNum1,double downNum2);
double calcError(double firstValue,double lastValue);
double calcIntegralWithTrapezoidRule(int n);
double calcIntegralWithSimpson1_div_3(int n);
double  calcIntegralWithSimpson3_div_8();


/*
#			------MAIN FUNCTION-------
#
*/

int main(int argc, char const *argv[])
{
	double trueValue,approxValue;
	
	/*Genel denklem*/
	printf("\nDenklem > > f(x) = (15.3) ^ (2.5x) from a to b  [a = %.2f, b = %.2f]\n\n",LOWER_LIMIT,UPPER_LIMIT);
	
	/*Analitik çözüm sonucunu gerçek değer olarak kabul edip
	hata heseplamalarında bu değeri kullanacağız*/
	trueValue = calcIntegralWithAnalitical(0.0,1.0);
	
				/* PART A */
	/*Analitik çözüm*/
	printf("\t\t\tPART A\n");
	printf("\nİntegralin Analitik Çözümünün Sonucu: ");
	printf("%f\n\n",calcIntegralWithAnalitical(1.0,0.0));
	
				/* PART B */
	/* yamuk kuralı ve hata*/
	printf("\t\t\tPART B\n");
	printf("İntegralin Yamuk Kuralı ile Çözüm sonucu: ");
	printf("%.10f\n",calcIntegralWithTrapezoidRule(1));
	approxValue = calcIntegralWithTrapezoidRule(1);
	printf("Hata:%.4f\n\n",calcError(trueValue,approxValue));

				/* PART E */
	/* N = 2, 4, 10, 20 için Yamuk kuralı ve hata*/
	/* N=2 için */
	printf("\t\t\tPART E\n");
	printf("İntegralin Yamuk Kuralı ile N=2 Çözüm sonucu: ");
	printf("%.10f\n",calcIntegralWithTrapezoidRule(2));
	approxValue = calcIntegralWithTrapezoidRule(2);
	printf("Hata:%.4f\n\n",calcError(trueValue,approxValue));
	/* N=4 için */
	printf("İntegralin Yamuk Kuralı ile N=4 Çözüm sonucu: ");
	printf("%.10f\n",calcIntegralWithTrapezoidRule(4));
	approxValue = calcIntegralWithTrapezoidRule(4);
	printf("Hata:%.4f\n\n",calcError(trueValue,approxValue));
	/* N=10 için */
	printf("İntegralin Yamuk Kuralı ile N=10 Çözüm sonucu: ");
	printf("%.10f\n",calcIntegralWithTrapezoidRule(10));
	approxValue = calcIntegralWithTrapezoidRule(10);
	printf("Hata:%.4f\n\n",calcError(trueValue,approxValue));
	/* N=20 için */
	printf("İntegralin Yamuk Kuralı ile N=20 Çözüm sonucu: ");
	printf("%.10f\n",calcIntegralWithTrapezoidRule(20));
	approxValue = calcIntegralWithTrapezoidRule(20);
	printf("Hata:%.4f\n\n",calcError(trueValue,approxValue));

					/* PART C */
	/* 1/3 simpson kuralı ve hata hesebı*/
	printf("\t\t\tPART C\n");
	printf("İntegralin Simpson 1/ 3 metodu ile çözüm sonucu: ");
	printf("%.10f\n",calcIntegralWithSimpson1_div_3(1));
	approxValue = calcIntegralWithSimpson1_div_3(1);
	printf("Hata:%.4f\n\n",calcError(trueValue,approxValue));
	
					/* PART F */
	/* N = 2, 4, 10, 20 için Simpson 1/3 kuralı ve hata*/
	/* N = 2*/
	printf("\t\t\tPART F\n");
	printf("İntegralin Simpson 1/ 3 metodu ile N=2 çözüm sonucu: ");
	printf("%.10f\n",calcIntegralWithSimpson1_div_3(2));
	approxValue = calcIntegralWithSimpson1_div_3(2);
	printf("Hata:%.4f\n\n",calcError(trueValue,approxValue));
	/* N = 4*/
	printf("İntegralin Simpson 1/ 3 metodu ile N=4 çözüm sonucu: ");
	printf("%.10f\n",calcIntegralWithSimpson1_div_3(4));
	approxValue = calcIntegralWithSimpson1_div_3(4);
	printf("Hata:%.4f\n\n",calcError(trueValue,approxValue));
	/* N = 10*/
	printf("İntegralin Simpson 1/ 3 metodu ile N=10 çözüm sonucu: ");
	printf("%.10f\n",calcIntegralWithSimpson1_div_3(10));
	approxValue = calcIntegralWithSimpson1_div_3(10);
	printf("Hata:%.4f\n\n",calcError(trueValue,approxValue));
	/* N = 20*/
	printf("İntegralin Simpson 1/ 3 metodu ile N=20 çözüm sonucu: ");
	printf("%.10f\n",calcIntegralWithSimpson1_div_3(2));
	approxValue = calcIntegralWithSimpson1_div_3(20);
	printf("Hata:%.4f\n\n",calcError(trueValue,approxValue));

					/* PART D */
	/*d.3/8 Simpson kuralı ve hata*/
	printf("\t\t\tPART D\n");
	printf("İntegralin Simpson 3/8 metodu ile çözüm sonucu: ");
	printf("%.10f\n",calcIntegralWithSimpson3_div_8());
	approxValue = calcIntegralWithSimpson3_div_8();
	printf("Hata:%.4f\n\n",calcError(trueValue,approxValue));

	return 0;
}
/*integrali alınacak denklem*/
double MyFunction(double x)
{	
	return pow(15.3, 2.5*x);
}
/*
#Gerekli işlemler elle yapıldıktan sonraki integralin son hali
# bilgisayara çözülmüştür.
#integral sonucu = 0.146635*e^(6.81963*x) + constant
#çözülecektir.
*/
double calcIntegralWithAnalitical(double upNum1,double downNum2)
{
	double val1,val2;

	/*belirli integralin bitim noktasındaki değer*/
	val1 = 0.146635 * pow(E_VALUE,6.81963 * upNum1);
	/*belirli integralin başlangıç noktasındaki değer*/
	val2 = 0.146635 * pow(E_VALUE,6.81963 * downNum2);

	return (fabs(val1 - val2));
}
/**
  *Yamuk Kuralı ile integral hesaplama
  */
double calcIntegralWithTrapezoidRule(int n)
{	
	int i;
	double A1 = 0,area = 0,y1 = 0,y2 = 0;
	double h_value;
	double x1,x2;

	h_value = (UPPER_LIMIT - LOWER_LIMIT) / n;/*average h*/
	x1 = LOWER_LIMIT;
	x2 = LOWER_LIMIT +h_value;

	for (i = 0; i < n;++i)
	{
		y1 = MyFunction(x1);
		y2 = MyFunction(x2);
		A1 += (y1 + y2);

		x1 += h_value;
		x2 += h_value;
	}
	area = A1 * h_value * 0.5;
	return fabs(area);	
}
/**
  * Simpson 1/3 kuralı
  */
double calcIntegralWithSimpson1_div_3(int n)
{
	double avh = (UPPER_LIMIT - LOWER_LIMIT) / n; /*average h*/
	double* h = (double*)calloc(n, sizeof(double)); 
	double sum = MyFunction(LOWER_LIMIT);
	int i = 0;
	
	for(i = 0; i < n; ++i){
		h[i] = (avh * i);
	}
	
	for(i = 1; i < n - 2; i+=2){
		sum = sum + 4 * MyFunction(h[i]) + 2 * MyFunction(h[i + 1]);
	}
	sum = sum + 4 * MyFunction(h[n-1]) + MyFunction(UPPER_LIMIT);
	free(h);
	return fabs(avh * sum / 3);
}
/**
  * Simpson 3/8 kuralı
  */
double  calcIntegralWithSimpson3_div_8()
{
	double avh = (UPPER_LIMIT - LOWER_LIMIT) / 3; /*average h*/
	double *h  = (double*)calloc(4, sizeof(double));
	double sum = 0.0;
	int i = 0;

	for(i = 0; i < 4; ++i){
		h[i] = avh * i;
	}
	sum = (3.0 / 8.0) * avh * (MyFunction(h[0]) + 3 * (MyFunction(h[1]) + MyFunction(h[2])) + MyFunction(h[3]));
	free(h);
	return fabs(sum);
}
/*hata heseplama*/
double calcError(double firstValue,double lastValue)
{
	return ((fabs(firstValue - lastValue) / fabs(firstValue)) * 100 );
}