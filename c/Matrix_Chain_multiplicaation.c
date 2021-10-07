#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int *mat;
int **m;
int **s;
void MCM(int *mat, int n)
{
    int i, len, j, temp, cost;
    m = (int **)malloc(sizeof(int *) * n);
    s = (int **)malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++)
    {
        m[i] = (int *)calloc(sizeof(int), n);
        s[i] = (int *)calloc(sizeof(int), n);
    }
    for (len = 1; len < n; len++)
    {
        for (i = 0; i < n - len; ++i)
        {
            j = i + len;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                temp = mat[i] * mat[k + 1] * mat[j + 1];
                cost = m[i][k] + m[k + 1][j] + temp;
                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
}
void print_order(int i, int j)
{
    if (i == j)
        printf("%c", i + 65);
    else
    {
        printf("(");
        print_order(i, s[i][j]);
        print_order(s[i][j] + 1, j);
        printf(")");
    }
}
int main()
{
    int n;
    printf("Enter the total no of matrices to be multiplied\n");
    scanf("%d", &n);
    mat = (int *)malloc(sizeof(int) * (n + 1));
    printf("enter the dimensions\n");
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &mat[i]);
    }
    MCM(mat, (n));

    printf("printing m matrix (printing upper triangular matrix) :\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < i)
            {
                printf("\t");
            }
            else
            {
                printf("%d\t", m[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n printing s matrix (printing upper triangular matrix) \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < i)
            {
                printf("\t");
            }
            else
            {
                printf("%d\t", s[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n minimum cost of multiplication is %d \n\n", m[0][n - 1]);
    printf("optimal order of multiplication is \n");
    print_order(0, n - 1);
    return 0;
}