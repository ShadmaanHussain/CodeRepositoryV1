#include<iostream>
using namespace std;

int size_of_string(char a[])
{
    int size = 0;
    int i = 0;
    while (a[i] != '\0')
    {
        size++;
        i++;
    }
    return size;
}

int main () {

    char ch[100];
    cin >> ch;
    cout << "Size of the string : " << size_of_string(ch) << endl;
    return 0;
}