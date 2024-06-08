#include <iostream>
using namespace std;

void printnum(int n)
{
    if (n == 1)
    {
        cout << 1 << " ";
    }
    else
    {
        printnum(n - 1);
        cout << n << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    printnum(n);
    return 0;
}