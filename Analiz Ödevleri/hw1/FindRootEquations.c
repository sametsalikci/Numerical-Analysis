/*
Homework1:Numerical Analysis

Name:Mehmet Mazhar SALIKCI
Number : 111044050

Introduction :
----find the roots that use with Bisection,False Position,One-Point Iteration,
Newton-Raphion,Secant Method
*/
#include<stdio.h>
#include<math.h>
#define LIMIT_ERROR 0.1

double mainEquationFunc(double n);/*Ana fonksiyon denkleminin gösterimi*/
double calculateError(double root1,double root2);/*Hata hesaplama*/
double bisectionFunc(double rootAlt,double rootUst);/*Ikiye bolme yontemiyle kok bulma*/
double modFalsePosition(double rootAlt,double rootUst);/*Yanlis pozisyon yontemiyle kok bulma*/
double onePointIteration(double root1);/*Iteration yontemiyle kok bulma*/
double secantMetod(double root1,double root2);/*Secant metoduyla kok bulma fonksiyonu*/
double derivativeMainEquationFunc(double n);/*Ana fonksiyonun turevinin degerini dondurur*/
double newtonRalphsonMetod(double root);/*Newton-Ralphson metoduyla kok bulma*/
void PrintMainDriverFunciton(int section);/*Fonksiyonlari sirasiyla calistirmamizi kolaylastirmak icin
											kullanacagimiz bir fonksiyondur*/
int printInformationFunction(void)	;/*islem yapacagimiz metod ile ilgili ekrana gerekli bilgiyi basar*/

int main(void){

	int section;
	
	/*tum fonksiyonlarimizi teset etmek icin yazilmis menu*/
	/*Butun fonksiyonlarimizin menusu*/	
	section = printInformationFunction();
	PrintMainDriverFunciton(section);
	
	
	return 0;
}
/*Kokunu bulacagimiz denklem*/
double mainEquationFunc(double n)
{
	double root;
	
	root = (-3000 * pow(1.2,n)) / (pow(1.2,n) - 1) + (175*n) / (pow(1.2,n) - 1) + 5000;
	
	return root;
}
/*Ana fonksiyonun turevinin degerini dondurur*/
double derivativeMainEquationFunc(double n)
{
	double value1,value2,root = 0;
	
	if(n !=0){
		value1 = (-3000 * n *pow(1.2,n-1) * (pow(1.2,n) - 1)) - ((-3000 * pow(1.2,n)) * n * pow(1.2,n-1));	
		value2 = (175*(pow(1.2,n) - 1)) - (175 * pow(n,2) * pow(1.2,n-1));
		root = (value1 + value2) / (pow((pow(1.2,n) - 1),2));
	}
	else{
		
		printf("Girdiginiz deger fonksinun paydasini '0' sifir yaptigi icin hatalidir.\n");
		return n;
	}
	return (root);
}
/*
/*Hata hesaplama fonksiyonu*/
double calculateError(double root1,double root2)
{

	double error;

	error = fabs((root1 -root2) / root1) * 100;
	
	return error;
}
/*TEST EDILDI*/
/*Fonksiyon kokunu bulmak icin kullanacagimiz bisection metodu*/
/*Bu fonksiyona tahmini olarak iki deger veriyoruz ve verdigimiz bu
degerlerin arasinda bizim gercek kokumuz varsa bir deger dondurur*/
double bisectionFunc(double rootAlt,double rootUst)
{

	double realRoot = 0,tempRoot;
	double valueY2,valueY1,error;
	double test;
	
	valueY1 = mainEquationFunc(rootAlt);

	do{
		tempRoot = realRoot;
		realRoot = (rootAlt + rootUst) / 2.0;
		valueY2 = mainEquationFunc(realRoot);
		
		if(realRoot != 0)
			error = calculateError(realRoot,tempRoot);
		
		test = valueY1 *valueY2;
		if(test < 0){
			rootUst = realRoot;
		}
		else{ 
			if(test > 0)
			{
				rootAlt = realRoot;
				valueY1 = valueY2;

			}
			else
				error = 0;
			}
	}while(error > LIMIT_ERROR);
	
	printf("Output Error:%f\n",error);
	
	return realRoot;
}
/*TEST EDILDI*/
/*Hatali pozisyon yontemiyle kok bulma fonksiyonu*/
/*Fonksiyona baslangic olarak kok kabul ettigimiz iki deger veriyoruz
ve bize yaklasik kok buluyor*/
double modFalsePosition(double rootAlt,double rootUst)
{
	double realRoot = 0,tempRoot;
	double valueY2,valueY1,valueY3,error;
	double test;
	int ia=0,iu=0,iter=0;
	valueY1 = mainEquationFunc(rootAlt);
	valueY2 = mainEquationFunc(rootUst);
	
	do{
		tempRoot = realRoot;
		realRoot = rootUst - valueY2 *((rootAlt - rootUst) / (valueY1 - valueY2));
        valueY3 = mainEquationFunc(realRoot);
          
		if(realRoot > 0)
        	error = calculateError(realRoot,tempRoot);
		
        test = valueY1 * valueY3;
        if(test < 0){
                
        	rootUst = realRoot;
            valueY2 = mainEquationFunc(rootUst);
        	iu = 0;
        	ia = ia + 1;
    		if(ia>=2)
    			valueY1 = valueY1 / 2;
    			
        }
        else if(test >0){
                    
        	rootAlt = realRoot;
            valueY1 = (rootAlt);
        	ia = 0;
        	iu = iu + 1;
        	if(iu >=2)
        		valueY2 = valueY2 / 2;
     	}
        else
        	error = 0;
        
	}while(error > LIMIT_ERROR);
     
	printf("Output Error:%f\n",error); 
	          
	return realRoot;
}
/*Sabit nokta iteration ile kok bulma "EKSIK"*/
/*fonksiyon calismiyor*/
double onePointIteration(double root1)
{
     double root,error,tempRoot;
          
	root = root1;
	
	do{
     	tempRoot = root;
     	root = mainEquationFunc(tempRoot);
     	printf("tempRoot:%f\n",tempRoot);
     	printf("root:%f\n",root);
     	error = calculateError(root,tempRoot);
     	
     	
     }while(error > LIMIT_ERROR);
	
	printf("Output Error:%f\n",error);
	
	return root;
}
/*Secant metoduyla kok bulma "bitti"*/
/*Bu metodda fonksiyona baslangic olarak iki deger veriyoruz.Fonksiyon
bu degerleri kullanarak bize gercek koku donduruyor*/
double secantMetod(double root1,double root2)
{
	double valueY1,valueY2,root3,error;
	
	valueY1 = mainEquationFunc(root1);
	valueY2 = mainEquationFunc(root2);
	
	do{
		root3 = root2 - ((valueY2*(root2-root1)) / (valueY2 - valueY1));
		root1 = root2;
		valueY1 = valueY2;
		valueY2 = mainEquationFunc(root3);
		error = calculateError(root3,root2);
		root2 = root3;
	}while(error>LIMIT_ERROR);
	 
	printf("Output Error:%f\n",error);
	
	return root3;
}
/*TEST	EDILDI*/
/*Newton-Ralphson metoduyla kok bulma fonksiyonu/
/*Fonksiyona baslangic olarak kok kabul ettigimiz bir deger veriyoruz.*/
/*Bu fonksiyon bize dogru degeri donduruyor*/
double newtonRalphsonMetod(double root)
{
	double valueY0,valueDerivative,root1,error;
	
	do{
		valueY0 = mainEquationFunc(root);
		valueDerivative = derivativeMainEquationFunc(root);
		root1 = root - (valueY0 / valueDerivative);
		error = calculateError(root1,root);
		root = root1;
	}while(error > LIMIT_ERROR);
	
	printf("Output Error:%f\n",error);
	
	return root1;
}
/*Islem yapacagimiz kok bulma yontemiyle ilgili gerekli bilgiyi
kullaniciya sunar*/
int printInformationFunction(void){

	int section;
	do{
	printf("1 enter for Bisection Metod:\n");
	printf("2 enter for False Position:\n");
	printf("3 enter for One-Point Iteration:\n");
	printf("4 enter for Newton-Raphion:\n");
	printf("5 enter for Secant Method:\n");
	printf("6 enter for exit:\n");
	printf("Enter the one Number: ");
	scanf("%d",&section);
	}while((section >=7) || (section <= 0));
	
	return (section);
}
/*Bu fonksiyon menu gorevi gorur.Kullanici islem yapmak istedigi metodu secerek
bu metdodla ilgili gerekli inputlari vererek istedikleri koku bulurlar*/
void PrintMainDriverFunciton(int section){
	
	double rootAlt,rootUst;
	switch(section){
	 case 1:
	 	printf("enter two number for Bisection Metod: ");
	 	scanf("%lf %lf",&rootAlt,&rootUst);
		printf("Root:%f\n",bisectionFunc(rootAlt,rootUst));
	 		break;
	 case 2:
	 	printf("Enter two number for False Position: ");
	 	scanf("%lf %lf",&rootAlt,&rootUst);
		printf("Root:%f\n",modFalsePosition(rootAlt,rootUst));
	 		break;
	 case 3:
		printf("Enter one number for One-Point Iteration: ");
	 	scanf("%lf",&rootAlt);
		printf("Root:%f\n",onePointIteration(rootAlt));
			break;
	case 4:
		printf("Enter one number for Newton-Raphion ");
	 	scanf("%lf",&rootAlt);
		printf("Root:%f\n",newtonRalphsonMetod(rootAlt));
			break;
	case 5:
		printf("Enter two number for Secant Method: ");
	 	scanf("%lf %lf",&rootAlt,&rootUst);
		printf("Root:%f\n",secantMetod(rootAlt,rootUst));
			break;
	
	case 6:
			printf("exit\n");
			break;	      	
	default:
			break;
	}
}

