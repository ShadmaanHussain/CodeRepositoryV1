#include <bits/stdc++.h>
using namespace std;

void keypad(int input, string output) {
    if (input == 0) {
        cout << output << endl;
        return;
    }
    int unitDigit = input % 10;
    int smallNum = input / 10;
    string container;
    switch (unitDigit)
    {
    case 2:
        container = "abc";
        break;
    case 3:
        container = "def";
        break;
    case 4:
        container = "ghi";
        break;
    case 5:
        container = "jkl";
        break;
    case 6:
        container = "mno";
        break;
    case 7:
        container = "pqrs";
        break;
    case 8:
        container = "tuv";
        break;
    case 9:
        container = "wxyz";
        break;
    }
    for(int i = 0; i < container.size(); i++) {
        keypad(smallNum, container[i] + output);
    }
}

int main() {
    int n;
    string output = "";
    cin >> n;
    keypad(n, output);
    return 0;
}