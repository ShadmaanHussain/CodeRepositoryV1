#include <iostream>
using namespace std;

int no_of_zeros(int n)
{
    if (n / 10 == 0)
    {
        if (n == 0)
        {
            return 1;
        }
        return 0;
    }

    int sm_ans = no_of_zeros(n / 10);

    if (n % 10 == 0)
    {
        return 1 + sm_ans;
    }
    else
    {
        return sm_ans;
    }
}

int main()
{
    int n;
    cin >> n;

    int zeros = no_of_zeros(n);
    cout << zeros;
    return 0;
}