/* Grafik Yontemi */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float f(float A,float B,float C,float x)
{
    return A*x*x+B*x+C;
}
int main()
{
    float x,x0,dX,eps,F0,F1=0, A,B,C;
    int iterasyon=1;
    printf("\nGrafik Yontemi. Denklem: f(x) = Ax^2 + Bx + C\n\n");
    printf("A : ");
    scanf("%f", &A);
    printf("B : ");
    scanf("%f", &B);
    printf("C : ");
    scanf("%f", &C);
    printf("Denklem: f(x) = ");
    printf("%.2fx^2 + %.2fx + %.2f\n", A,B,C);
    printf("x0 : ");
    scanf("%f", &x0);
    printf("DeltaX degeri : ");
    scanf("%f", &dX);
    printf("Epsilon : ");
    scanf("%f", &eps);
    printf("\n");
    x = x0;
    F0 = f(A,B,C,x);
    while (dX > eps)
    {
        while (F1 * F0 >= 0)
        {
            F0 = f(A,B,C,x);
            x = x + dX;
            F1 = f(A,B,C,x);
        }

        dX = dX / 2;
        x = dX - x;
        iterasyon++;
    }
    printf("Kok ~ %.6f\n", x-dX);
    printf("Iterasyon sayisi: %d\n", iterasyon);

    return 0;
}
