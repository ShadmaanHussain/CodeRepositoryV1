#include<iostream>
using namespace std;

void printntimes(char c, int n)
{
    if (n == 1)
    {
        cout << c << " ";
        return;
    }
    printntimes(c, n-1);
    cout << c << " ";
}

int main () {

    char c;
    int n;
    cin >> c >> n;
    printntimes(c, n);
    return 0;
}