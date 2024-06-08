#include<iostream>
using namespace std;

int str_len(char str[]) {
    if (str[0] == '\0')
    {
        return 0;
    }
    int smallStrLen = str_len(str + 1);
    return 1 + smallStrLen;
}

int main () {
    char str[100];
    cin.getline(str, 100);
    int len = str_len(str);
    cout << len << endl;
    return 0;
}