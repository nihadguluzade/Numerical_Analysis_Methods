/* Numerik Turev */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float f(float x)
{
	return exp(x);
}
float ileriFark(float x1, float x, float dx)
{
	printf("f(x1) = %f, f(x) = %f, dx = %f\n", f(x1),f(x),dx);
	return (f(x1)-f(x))/dx;
}
float geriFark(float x, float x0, float dx)
{
	return (f(x)-f(x0))/dx;
}
float merkeziFark(float x1, float x0, float dx)
{
	return (f(x1)-f(x0))/(2*dx);
}
int main()
{
    float x,x1,x0,dx;
    printf("Numerik Turev. Bu yontem icin denklem: f(x) = e^x\nx degerini giriniz : ");
    scanf("%f",&x);
    printf("DeltaX degerini giriniz : ");
    scanf("%f",&dx);
    printf("\nAnalitik yontemle cevap = %f\n\n", f(x));
    x1=x+dx;
    x0=x-dx;
    printf("Ileri Fark  Turevi (Numerik) = %f\n\n", ileriFark(x1,x,dx));
    printf("Geri Fark Turevi (Numerik) = %f\n\n", geriFark(x,x0,dx));
    printf("Merkezi Fark Turevi (Numerik) = %f\n\n", merkeziFark(x1,x0,dx));
}
