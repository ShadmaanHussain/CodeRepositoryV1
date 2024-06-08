#include <iostream>
using namespace std;

int pow(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    int Output = x * pow(x, n - 1);
    return Output;
}

int main()
{
    int x, n;
    cin >> x >> n;
    int p = pow(x, n);
    cout << p << endl;
    return 0;
}