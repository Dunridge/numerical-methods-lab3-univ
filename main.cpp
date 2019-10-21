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

/*
A = np.array([[8., 1., -4.],
              [2., -6., 1.],
              [-1., 1., 4.]])
 * */


int A[3][3] = {{8, 1, -4},
               {2, -6, 1},
               {-1, 1, 4}};

//you don't need this method
//void Input(int n,int A[][100])
//{
//    int i,j;
//    for (i=0;i<n;i++)
//        for (j=0;j<n;j++)
//            scanf("%d",&A[i][j]);
//}

void Matr(int A[][3],int n)
{
    float w0[3],w[3],summ=0,w0norm[3],e,d,d0;
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
    printf("%f\n",d); //determinant???
    //finding the minimum values
    double max = w0norm[0];
    for(int it1 = 1; it1 < 4; it1++) {
        if(w0norm[i] > max) {
            max = w0norm[it1];
        }
    }

    std::cout << "the maximum eigenvalue is: " << max << std::endl;

    //finding the minimum values
    double min = w0norm[0];

    for(int it2 = 1; it2 < 3; it2++) {
        if(w0norm[it2] < max) {
            min = w0norm[it2];
        }
    }

    std::cout << "the minimum eigenvalue is: " << min << std::endl;

    //print all of the numbers:
    //for (i=0;i<n;i++)
    //    printf("%f\n",w0norm[i]);
}

void main()
{
    //int n,A[100][100];
    int n = 3;
    //scanf("%d",&n);
    //Input(n,A);
    Matr(A,n);
}