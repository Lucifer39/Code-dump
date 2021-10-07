#include<stdio.h>
#include<stdlib.h>

#define N 5

int a[N];

void merge(int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int r1[n1],r2[n2];
    for(int i=0;i<n1;i++)
        r1[i]=a[i+l];
    for(int i=0;i<n2;i++)
        r2[i]=a[i+m+1];

    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(r1[i]<r2[j]){
            a[k]=r1[i];
            i++;
        }
        else{
            a[k]=r2[j];
            j++;
        }
        k++;
    }
    if(i<n1){
        a[k]=r1[i];
        i++;
        k++;
    }
    if(j<n2){
        a[k]=r2[j];
        j++;
        k++;
    }
}

void mergesort(int l,int h){
    if(l<h){
        int m=(l+h)/2;
        mergesort(l,m);
        mergesort(m+1,h);
        merge(l,m,h);
    }
}
int main()
{
    printf("Enter numbers: ");
    for(int i=0;i<N;i++)
        scanf("%d",&a[i]);

    printf("Array before sorting: ");
    for(int i=0;i<N;printf("\t%d",a[i]),i++);
    mergesort(0,N-1);
    printf("\nArray after sorting: ");
    for(int i=0;i<N;printf("\t%d",a[i]),i++);
    return 0;
}