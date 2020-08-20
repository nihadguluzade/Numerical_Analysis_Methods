/* Gauss Eliminasyon Yontemi */
#include<stdio.h>
int main()
{
    int i,j,k,n;
    float mat[30][30],c,arr[10],sum=0;
    printf("Gauss Eliminasyon Yontemi.\n\nMatrisin boyutunu giriniz : ");
    scanf("%d",&n);
    printf("Matrisin elemanlarini giriniz:\n");
    for(i=1; i<=n; i++)
    {
        printf("%d. denklem:\n", i);
        for(j=1; j<=(n+1); j++)
        {
            printf("A[%d][%d] : ", i,j);
            scanf("%f",&mat[i][j]);
        }
        printf("\n");
    }
    for(j=1; j<=n; j++)
    {
        for(i=1; i<=n; i++)
        {
            if(i>j)
            {
                c=mat[i][j]/mat[j][j];
                for(k=1; k<=n+1; k++)
                {
                    mat[i][k]=mat[i][k]-c*mat[j][k];
                }
            }
        }
    }
    arr[n]=mat[n][n+1]/mat[n][n];
    for(i=n-1; i>=1; i--)
    {
        sum=0;
        for(j=i+1; j<=n; j++)
        {
            sum=sum+mat[i][j]*arr[j];
        }
        arr[i]=(mat[i][n+1]-sum)/mat[i][i];
    }
    for(i=1; i<=n; i++)
    {
        printf("\nx%d=%f\t",i,arr[i]);
    }
    return(0);
}