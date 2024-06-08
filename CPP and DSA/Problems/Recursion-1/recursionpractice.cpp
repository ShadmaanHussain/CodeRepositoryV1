#include <iostream>
using namespace std;

bool pow_two(int n)
{
    if (n % 2 == 0)
    {
        if (n == 2)
        {
            return true;
        }

        pow_two(n / 2);
    }
    else 
    {
        return false;
    }
}

int main()
{

    int n;
    cin >> n;
    bool istrue = pow_two(n);
    cout << istrue;
    return 0;
}