#include <iostream>
#include<stdio.h>
#include<math.h>

/*
 Завдання:
1) Знайти максимальне та мінімальне значення методом скалярних добутків
(aka Find the maximum and the minimum eigenvalues for a matrix by using the method
of scalar products)

Для лабораторної реалізував на репозиторії https://github.com/Dunridge/numerical-methods-lab3-univ
за допомогою do while циклу
*/

// TODO: define a matrix here

void Input(int n,int A[][100])
{
    int i,j;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            scanf("%d",&A[i][j]);
}

void Matr(int A[][100],int n)
{
    float w0[100],w[100],summ=0,w0norm[100],e,d,d0;
    int i,j,k;
    for (i=0;i<n;i++)
        w0[i]=0;
    w0[0]=1;
    do
    {
        for (i=0;i<n;i++)
            summ=summ+w0[i]*w0[i];
        d0=sqrt(summ);
        for (i=0;i<n;i++)
            w0norm[i]=w0[i]/d0;
        for (i=0;i<n;i++)
        {
            w[i]=0;
            for (j=0;j<n;j++)
                w[i]=w[i]+A[i][j]*w0norm[j];
        }
        summ=0;
        for (i=0;i<n;i++)
            summ=summ+w[i]*w[i];
        d=sqrt(summ);
        e=fabs(d-d0);
        for (i=0;i<n;i++)
            w0[i]=w[i];
        summ=0;
    }
    while(e>0.001);
    printf("%f\n",d);
    for (i=0;i<n;i++)
        printf("%f\n",w0norm[i]);
}

void main()
{
    int n,A[100][100];
    scanf("%d",&n);
    Input(n,A);
    Matr(A,n);
}