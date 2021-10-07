#include <iostream>
#include <string.h>
using namespace std;

void rotate_array(char a[], int n)
{
    //move every element n position ahead , starting from end
    int len = strlen(a);
    int i = len - 1;
    // to reduce steps
    if(n>=len){
        n=n%len;
    }
    while (i >= 0)
    {
        a[i + n] = a[i];
        i--;
    }

    //bringing required elements in the start
    i = 0;
    int j = len;
    while (i < n)
    {
        a[i] = a[j];
        i++;
        j++;
    }
    a[len] = '\0';
}

int main()
{

    char a[2*5] = "hello";
    int shift = 8;
    cout << "initial array\n";
    cout << a << endl;
    rotate_array(a, shift);
    cout << "\nfinal rotated array\n";
    cout << a << endl;
    return 0;

}