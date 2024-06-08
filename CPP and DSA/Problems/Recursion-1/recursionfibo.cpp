#include <iostream>
using namespace std;

int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    int sopt1 = fib(n-1);
    int sopt2 = fib(n-2);
    return sopt1 + sopt2;
}

int main()
{
    int n;
    cin >> n;
    int f = fib(n);
    cout << f;
    return 0;
}