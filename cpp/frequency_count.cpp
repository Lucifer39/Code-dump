#include<iostream>
#include<string.h>
using namespace std;

int main(){

     int frequency_arr[26];
    char a[]="hellowo";
    cout<<a<<endl;

    for(int i=0;i<26;i++){
        frequency_arr[i]=0;
    }

    for(int i=0;a[i]!='\0';i++){
        frequency_arr[a[i]-'a']+=1;
    }

    for(int i=0;i<26;i++){
        if(frequency_arr[i]!=0){
            cout<<char('a'+i)<<" : "<<frequency_arr[i]<<endl;
        }
    }

    return 0;
}
