#include<iostream>
using namespace std;

int mult(int m, int n)
{
    if (m == 1)
    {
        return n;
    }
    int smallans = mult(m - 1, n);

    return n + smallans;
}

int main () {
    int m, n;
    cin >> m >> n;
    
    int mul = mult(m, n);
    cout << mul;

    return 0;
}