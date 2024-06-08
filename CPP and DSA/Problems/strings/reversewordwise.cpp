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

void rev_word_wise (char* str, char* rev_str) {
    int len = str_len(str);
    int rev = 0; // this variable is for traversing the reversed string
    for (int i = len - 1; i >= 0; i--) {
        if ((str[i] == ' ') || (i == 0)) {
            int j = i + 1;
            if (i == 0) {
                j = i;
            }
            while ((str[j] != '\0') && (str[j] != ' ')) {
                rev_str[rev] = str[j];
                rev++;
                j++;
            }
            if (i != 0) {
                rev_str[rev] = ' ';
            }
            rev++;
        }
    }
    rev_str[rev] = '\0';
}

int main () {
    char str[100], rev_str[100];
    cin.getline(str, 100);
    rev_word_wise(str, rev_str);
    cout << rev_str << endl;
    return 0;
}