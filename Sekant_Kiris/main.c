/* Sekant Kiris Yontemi */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float f(float A, float B, float C, float D, float x)
{
    return A*x*x*x + B*x*x + C*x + D;
}
int main()
{
    float x0,x1,x2,eps,A,B,C,D,y0,y1;
    int its=0;
    printf("Sekant Kiris Yontemi. Denklem: Ax^3 + Bx^2 + Cx + D\n\n");
    printf("A : ");
    scanf("%f", &A);
    printf("B : ");
    scanf("%f", &B);
    printf("C : ");
    scanf("%f", &C);
    printf("D : ");
    scanf("%f", &D);
    printf("\nDenklem: f(x) = %.2fx^3 + %.2fx^2 + %.2fx + %.2f\n\n", A,B,C,D);
    printf("x0 : ");
    scanf("%f", &x0);
    printf("x1 : ");
    scanf("%f", &x1);
    printf("\nAralik: %.2f<x<%.2f\n\n",x0,x1);
    printf("Epsilon : ");
    scanf("%f", &eps);
    printf("\n");
    x2=0;
    while (!(fabs(x2-x0) <= eps))
    {
    	if(its!=0)
    		x0=x2;

        y0=f(A,B,C,D,x0);
        y1=f(A,B,C,D,x1);
    	x2=x0-y0*(x1-x0)/(y1-y0);
    	its++;
    	printf("%d. iterasyonda x0: %.6f, y0: %.6f, x1: %.6f, y1: %.6f, x2: %.6f\n", its,x0,y0,x1,y1,x2);
    }
    printf("\nKok ~ %.6f", x2);
    return 0;
}