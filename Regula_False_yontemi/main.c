/* Regula False Yontemi */
#include <stdio.h>
#include <stdlib.h>
float f(float A, float B, float C, float D, float x)
{
    return A*x*x*x + B*x*x + C*x + D;
}
int main()
{
    float a,b,c,eps,Fa,Fb,Fc, A,B,C,D;
    int its=0;

    printf("Regula False Yontemi. Denklem: f(x) = Ax^3 + Bx^2 + Cx + D\n\n");
    printf("A : ");
    scanf("%f", &A);
    printf("B : ");
    scanf("%f", &B);
    printf("C : ");
    scanf("%f", &C);
    printf("D : ");
    scanf("%f", &D);
    printf("Denklem: f(x) = ");
    printf("%.2fx3 + %.2fx2 + %.2fx + %.2f\n\n", A,B,C,D);
    printf("a degeri: ");
    scanf("%f", &a);
    printf("b degeri: ");
    scanf("%f", &b);
    printf("Epsilon : ");
    scanf("%f", &eps);
    printf("\n");

    Fa = f(A,B,C,D,a);
    Fb = f(A,B,C,D,b);
    c = (b*Fa - a*Fb) / (Fa - Fb);
    Fc = f(A,B,C,D,c);

    if (Fa * Fb > 0)
    {
        printf("Kok YOK");

    } else
    {
        if (Fa * Fb == 0)
        {
            if (Fa == 0)
            {
                printf("Kok a'dir\n");
            } else {
                printf("Kok b'dir\n");
            }

        } else
        {
            if (Fc == 0)
            {
                printf("Kok c'dir\n");
            } else
            {
                while ((Fc > eps) || (Fc * (-1) > eps))
                {
                    if (Fc * Fa < 0)
                    {
                        b = c;
                    } else {
                    	a = c;
                    }

                    c = (b*Fa - a*Fb) / (Fa - Fb);
                    printf("Iterasyon %d.\n", its+1);
                    printf("a = %.5f\n", a);
                    Fa = f(A,B,C,D,a);
                    printf("f(a) = %.5f\n", Fa);
                    printf("b = %.5f\n", b);
                    Fb = f(A,B,C,D,b);
                    printf("f(b) = %.5f\n", Fb);
                    printf("c = %.5f\n", c);
                    Fc = f(A,B,C,D,c);
                    printf("f(c) = %.5f\n\n", Fc);
                    its++;
                }
				c = (b*Fa - a*Fb) / (Fa - Fb);               
                printf("Kok ~ %.6f\nIterasyon sayisi: %d\n", c,its);
            }
        }
    }
    return 0;
}