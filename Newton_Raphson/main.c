/* Newton Raphson Yontemi */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float f(float A, float B, float C, float D, float x)
{
    return A*x*x*x + B*x*x + C*x + D;
}

float df(float A, float B, float C, float x)
{
    return 3*A*x*x + 2*B*x + C;
}
int main()
{
    float xk,eps,x1,A,B,C,D;
    int its=0;
    printf("Newton Raphson Yontemi. Denklem: f(x) = Ax^3 + Bx^2 + Cx + D\n\n");
    printf("A : ");
    scanf("%f", &A);
    printf("B : ");
    scanf("%f", &B);
    printf("C : ");
    scanf("%f", &C);
    printf("D : ");
    scanf("%f", &D);
    printf("Denklem: f(x) = %.2fx^3 + %.2fx^2 + %.2fx + %.2f\n", A,B,C,D);
    printf("x0 : ");
    scanf("%f", &xk);
    printf("Epsilon : ");
    scanf("%f", &eps);
    x1=xk-f(A,B,C,D,xk)/df(A,B,C,xk);
    printf("\n0. iterasyonda x = %.6f\n", x1);

    while (!(fabs(x1 - xk) <= eps))
    {
    	xk=x1;
    	x1=xk-f(A,B,C,D,xk)/df(A,B,C,xk);
    	printf("%d. iterasyonda x = %.6f\n", its+1, x1);
    	its++;
    }
    printf("\nX Kok: %.6f\n", xk);
    printf("Iterasyon Sayisi: %d\n", its);
    return 0;
}