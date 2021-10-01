#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <limits.h>

int MatrixChain(int *);
void optimal(int,int);
int *dp,*s,n;

int main(){
    int *a;
    printf("Enter number of matrices\n");
    scanf("%d",&n);
    a=(int *)malloc((n+1)*sizeof(int));
    printf("Enter matrix sizes\n");
    for(int i=0;i<=n;i++){
        scanf("%d",(a+i));
    }
    int cost = MatrixChain(a);
    printf("\n");
    optimal(0, n-1);
    printf("\nCost of multiplications is %d ",cost);
    return 0;
}

void optimal(int i, int j)
{
    if (i == j)
    {
        printf(" M%d ", (i+1));
    }
    else
    {
        printf("(");
        optimal(i, *(s+(i*n)+j)-1);
        optimal((*(s+(i*n)+j)), j);
        printf(")");
    }
}

int MatrixChain(int *a){
    dp=(int *)malloc(n*n*sizeof(int));
    s=(int *)malloc(n*n*sizeof(int));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            *(dp+(i*n)+j)=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            *(s+(i*n)+j)=0;
        }
    }
    for(int d= 0;d<n;d++){
        for(int i=0,j=i+d;j<n;i++,j++){
            if(d==0){
                *(dp+(i*n)+j)=0;
            }
            else
            {
                int min=INT_MAX,c=0;
                for(int k=i;k<j;k++){
                    int lc = *(dp+((i)*n)+k);
                    int rc = *(dp+((k+1)*n)+j);
                    int mul = a[i]*a[k+1]*a[j+1];
                    c=lc+rc+mul;
                    if(c<min){
                        min=c;
                        *(s+((i)*n)+j)=k+1;
                    }
                }
                *(dp+((i)*n)+j)=min;
            }
        }
    }
    printf("\n\nM Matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>j){
                printf("-\t");
                continue;
            }
            printf("%d\t",*(dp+(i*n)+j));
        }
        printf("\n");
    }
    printf("\n\nS Matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>j){
                printf("-\t");
                continue;
            }
            printf("%d\t",*(s+(i*n)+j));
        }
        printf("\n");
    }
    return *(dp+n-1);
}