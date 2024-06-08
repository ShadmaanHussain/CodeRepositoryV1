#include<iostream>
using namespace std;

void swap (char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

int str_len(char* str) {
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

void str_reverse(char* str) {
    int len = str_len(str);
    int start = 0;
    int end = len - 1;
    while (start < end) {
        swap(str[start], str[end]);
        start++;
        end--;
    }
}

int main () {
    char str[100];
    cin.getline(str, 100);
    str_reverse(str);
    cout << str << endl;
    return 0;
}