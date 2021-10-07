#include<iostream>
#include<string.h>
using namespace std;

int main(){

char a[]="ababa";

// int len=0;
// for(int i=0;a[i]!='\0';i++){
//     len++;
// }
// cout<<len;

int len=strlen(a);



bool isPalindrome=true;

for(int i=0;i<len/2;i++){
    if(a[i]!=a[len-1-i]){
        isPalindrome=false;
        break;
    } 
}

if(isPalindrome){
    cout<<"YES";
}
else{
    cout<<"NO";
}


    return 0;
}