#include<iostream>
using namespace std;

int str_len(char* str) {
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

void shiftleft (char* str) {
    int len = str_len(str);
    for (int i = 0; i < len; i++) {
        str[i] = str[i+1];
    }
}

void trim_spaces (char* str) {
    int len = str_len(str);
    for (int i = 0; i < len; i++)
    {
        while(str[i] == ' ') {
            shiftleft(str + i);
        }
    }
}


int main () {
    char str[100];
    cin.getline(str, 100);
    trim_spaces(str);
    cout << str << endl;
    return 0;
}