#include <iostream>
#include <string.h>
using namespace std;

void removeDuplicates(char a[])
{
    int len = strlen(a);
    int j = 1, i = 0;
    while (j < len)
    {
        if (a[i] != a[j])
        {
            i++;
            a[i] = a[j];
        }
        j++;
    }
    a[i + 1] = '\0';
}

int main()
{

    char a[1000];
    cin.getline(a, 1000);
    cout << a << endl;
    removeDuplicates(a);
    cout << a << endl;
    return 0;
}