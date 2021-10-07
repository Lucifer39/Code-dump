//rotating an matrix 90deg anti-clockwise
#include<iostream>
using namespace std;

int main(){

    int n=4;
    int arr[n][n]={{1,2,3,10},{4,5,6,11},{7,8,9,12},{13,14,15,16}};
    

    //initial matrix
    cout<<"\n\nInitial Matrix\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }

    //step 1 :  take transpose
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }

    //matrix after transpose
    cout<<"\n\nmatrix after transpose\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }

    // invert the matrix 180deg about horizontal axis
    for(int i=0;i<((n-1)/2);i++){
        for(int j=0;j<n;j++){
            int temp=arr[i][j];
            arr[i][j]=arr[n-1-i][j];
            arr[n-1-i][j]=temp;
            
        }
    } 

    //matrix after inverting and hence the final matrix
    cout<<"\n\nmatrix after inverting and hence the final matrix\n";   
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }

    return 0;
}