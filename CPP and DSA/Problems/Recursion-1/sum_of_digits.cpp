#include<iostream>
using namespace std;

int sumdig(int n)
{
    if (n / 10 == 0)
    {
        return n;
    }

    int sum = (n % 10) + sumdig(n / 10);
    return sum;
}

int main () {

    int n;
    cin >> n;

    int sum = sumdig(n);

    cout << sum;
    return 0;
}