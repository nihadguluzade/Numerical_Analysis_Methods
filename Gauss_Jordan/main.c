/* Gauss Jordan Yontemi */
#include<stdio.h>
int main()
{
    int i,j,k,n;
    float mat[30][30],arr[30],c;
    printf("Gauss Jordan Yontemi.\nMatrisin boyutunu giriniz : ");
    scanf("%d",&n);
    printf("\nDenklemin katsayilarini giriniz:\n");
    for(i=1; i<=n; i++)
    {
        printf("%d. denklem:\n", i);
        for(j=1; j<=(n+1); j++)
        {
            printf("A[%d][%d] = ", i,j);
            scanf("%f",&mat[i][j]);
        }
        printf("\n");
    }
    // Diagonel matrisin elemanlarini bulmak icin
    for (j=1; j<=n; j++)
    {
        for (i=1; i<=n; i++)
        {
            if (i != j)
            {
                c=mat[i][j]/mat[j][j];
                for (k=1; k<=n+1; k++)
                {
                    mat[i][k]=mat[i][k]-c*mat[j][k];
                }
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        arr[i]=mat[i][n+1]/mat[i][i];
        printf("\n x%d=%f\n",i,arr[i]);
    }
    return 0;
}