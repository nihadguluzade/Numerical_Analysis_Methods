/* Trapez Yontemi */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float f(float,float,float,float,float);
int main()
{
	float A,B,C,D,h,x1,x0,x[30],y[30],sum=0,ans;
	int i,n;
	printf("*************************************************************\n");
	printf("Trapez (Yamuklar) Yontemi. Denklem: f(x)=Ax^3 + Bx^2 + Cx + D\nDenklemin katsayilarini giriniz:\n");
	printf("A : ");
	scanf("%f",&A);
	printf("B : ");
	scanf("%f",&B);
	printf("C : ");
	scanf("%f",&C);
	printf("D : ");
	scanf("%f",&D);
	printf("Denklem: %.2fx^3 + %.2fx^2 + %.2fx + %.2f\n",A,B,C,D);
	printf("Integralin sinirlarini giriniz:\n");
	printf("Ust : ");
	scanf("%f",&x1);
	printf("Alt : ");
	scanf("%f",&x0);
	printf("n degerini giriniz (integer) : ");
	scanf("%d",&n);
	h=(x1-x0)/n;
	for (i=0; i<=n; i++)
	{
		x[i]=x0+i*h;
		y[i]=f(A,B,C,D,x[i]);
	}
	for (i=1; i<n; i++)
	{
		sum+=y[i];
	}
	printf("\n\t   x\t\t f(x)\n\n");
	for (i=0; i<=n; i++)
	{
		printf("x%d\t%f\t%f\n", i,x[i],y[i]);
	}
	ans=h*((y[0]+y[n])/2 + sum);
	printf("\nCevap = %.2f * ((%.2f + %.2f) / 2 + %.4f)\n",h,y[n],y[0],sum);
	printf("Cevap: %.4f\n",ans);
}
float f(float A, float B, float C, float D, float x)
{
	return A*x*x*x + B*x*x + C*x + D;
}
