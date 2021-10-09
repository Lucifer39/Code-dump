#include <stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubleSort(int ar[],int n){
    int i,j;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(ar[j]>ar[j+1])
                swap(&ar[j],&ar[j+1]);
}
void arrayPrint(int ar[],int n){
    int i;
    for(i=0;i<n;i++)    
        printf("%d ",ar[i]);
    printf("\n");
}
int arrayRead(int array[]){
    int length;
    printf("Enter Length Of Array : ");
    scanf("%d",&length);
    for(int i=0;i<length;i++){
        printf("Enter %d th Element : ",i+1);
        scanf("%d",&array[i]);
    }
    return length;
}
void main(){
    int length;
    int array[100];
    length=arrayRead(array);
    printf("Unsorted Array is : ");
    arrayPrint(array,length);
    printf("Sorted Array  is : ");
    bubleSort(array,length);
    arrayPrint(array,length);
    
}