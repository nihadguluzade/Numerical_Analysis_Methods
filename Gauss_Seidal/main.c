/* Gauss-Seidal Yontemi */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void maxDiagonal(float[30][30],int);
void gaussSeidal(float[30][30],float[30],float,int);
int main()
{
    float mat[30][30],x[30],eps;
    int n;
    printf("Gauss-Seidal Yontemi.\n\nMatrisin boyutu (Bilinmeyenler sayisi) giriniz : ");
    scanf("%d",&n);
    printf("Matrisin elemanlarini (Denklemin katsayilari) giriniz:\n");
    for (int i=0; i<n; i++)
    {
    	printf("%d. denklem:\n", i+1);
    	for (int j=0; j<=n; j++)
    	{
    		printf("A[%d][%d] = ", i,j);
    		scanf("%f", &mat[i][j]);
    	}
    	printf("\n");
    }
    printf("\nEpsilon degerini giriniz : ");
    scanf("%f",&eps);
    maxDiagonal(mat,n);
    gaussSeidal(mat,x,eps,n);
    printf("Yontem bu denklem icin calismaz.");
    return 0;
}
void maxDiagonal(float mat[30][30], int n)
{
	int i,j;
	for (j=0; j<=n; j++)
	{
		for (i=1; i<n; i++)
		{
            int k=i-1;
            while (mat[i][j] > mat[k][j])
            {
                if (k==0 && mat[i][j]>mat[k][j])
                {
                   if (i != j)
                    {
                        double tmp;
                        while (j != n+1)
                        {
                            tmp=mat[i-1][j];
                            mat[i-1][j]=mat[i][j];
                            mat[i][j]=tmp;
                            j++;
                        } 
                    
                    } 
                break;
                }
                k--;
            }
		}
	}
	printf("\n\tMaksimum diyagonal matris:\n\n");
	for (i=0; i<n; i++)
	{
		for (j=0; j<=n; j++)
		{
			printf("\t%.3f",mat[i][j]);
		}
		printf("\n");
	}
}
void gaussSeidal(float mat[30][30], float x[30], float eps, int n)
{
	int itr=0,i,j;
	float dx=1,sum=0,x0=1;
	for (i=0; i<n; i++)
    	x[i]=1;
    while (dx>eps)
    {
    	for (i=0; i<n; i++)
    	{
    		
    			dx=0;
    			for (j=0; j<n; j++)
			  		if (i != j)
    				 	sum+=mat[i][j]*x[j];    			
    			x0=(mat[i][n]-sum)/mat[i][i];
    			dx=fabs(x[i]-x0);
    			x[i]=x0;
		    	sum=0;
    			itr++;
	    	
    	}
    	if (dx<=eps)
    	{
    		for (i=0; i<n; i++)
    			printf("\n x%d = %f",i+1,x[i]);
    		printf("\n Iterasyon sayisi: %d\n", itr);
    		exit(1);
    	}
    }
}