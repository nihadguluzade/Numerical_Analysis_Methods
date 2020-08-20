/* Cofactor + Determinant + Transpose + Inverse of Matrix */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float determinant(float[30][30],float);
void cofactor(float[30][30],float);
void transpose(float[30][30],float[30][30],float);
int main()
{
	float mat[30][30],n,d;
	printf("Cofactor + Determinant + Transpose + Inverse of matrix\n\n");
	printf("Kare matrisin boyutunu belirleyiniz : ");
	scanf("%f",&n);
	printf("Matrisin elemanlarini giriniz:\n");
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			printf("A[%d][%d] = ",i,j);
			scanf("%f",&mat[i][j]);
		}
	}
	d=determinant(mat,n);
	printf("\nMatrisin determinanti = %f\n\n",d);
	if(d==0)
		printf("Matrisin inversi mevcut degil\n");
	else
		cofactor(mat,n);
}
float determinant(float mat[30][30],float n)
{
	float mini[30][30],det=0,tmp=1;
	int i,j,k,a1,a2;
	if(n==1)
		return (mat[0][0]);
	else
	{
		det=0;
		for (i=0;i<n;i++)
		{
			a1=0; a2=0;
			for (j=0;j<n;j++)
			{
				for (k=0;k<n;k++)
				{
					mini[j][k]=0;
					if (j != 0 && k != i)
					{
						mini[a1][a2]=mat[j][k];
						if (a2<(n-2))
							a2++;
						else
						{
							a2=0; a1++;
						}
					}
				}
			}
			det=det + tmp*(mat[0][i]*determinant(mini,n-1));
			tmp=-1*tmp;
		}
	}
	return det;
}
void cofactor(float _mat[30][30], float _n)
{
	float mini[30][30],cof[30][30];
	int i,j,a1,a2;
	for (i=0; i<_n; i++)
	{
		for (j=0; j<_n; j++)
		{
			a1=0; a2=0;
			for (int k=0; k<_n; k++)
			{
				for (int l=0; l<_n; l++)
				{
					mini[k][l]=0;
					if (k != i && l != j)
					{
						mini[a1][a2]=_mat[k][l];
						if (a2<(_n-2))
							a2++;
						else
						{
							a2=0; a1++;
						}
					}
				}
			}
			cof[i][j]=pow(-1,i+j)*determinant(mini,_n-1);
		}
	}
	transpose(_mat,cof,_n);
}
void transpose(float _mat[30][30], float cof[30][30], float x)
{
	float mini[30][30],inv[30][30],d;
	int i=0,j=0;
	for(i=0; i<x; i++)
		for(j=0; j<x; j++)
			mini[i][j]=cof[j][i];

	d=determinant(_mat,x);
	inv[i][j]=0;
	for (i=0; i<x; i++)
		for (j=0; j<x; j++)
			inv[i][j]=mini[i][j]/d;

	printf("Matrisin inversi:\n\n");
	for (i=0; i<x; i++)
	{
		for(j=0; j<x; j++)
		{
			printf("\t%.3f", inv[i][j]);
		}
		printf("\n");
	}
}