#include<stdio.h>
#include<stdlib.h>

#define N 5

void heapify(int *a,int n,int i){
    int large=i,l=2*i+1,r=2*i+2;

    if(l<n && a[l]>a[large]){
        large=l;
    }
    if(r<n && a[r]>a[large]){
        large=r;
    }
    if(large!=i){
        int tmp=a[i];
        a[i]=a[large];
        a[large]=tmp;

        heapify(a,n,i);
    }
}

void heapsort(int *a){
    for(int i=N/2-1;i>=0;i--){
        heapify(a,N,i);
    }
    
    for (int i = N - 1; i >=0; i--) {

        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        
        heapify(a, i, 0);
    }
}

int main()
{
    int a[N];
    printf("Enter elements: ");
    for(int i=0;i<N;i++)
        scanf("%d",&a[i]);
    printf("\nBefore Sorting: ");
    for(int i=0;i<N;i++)
        printf("\t%d",a[i]);
    heapsort(a);
    printf("\nAfter Sorting: ");
    for(int i=0;i<N;i++)
        printf("\t%d",a[i]);
    return 0;
}