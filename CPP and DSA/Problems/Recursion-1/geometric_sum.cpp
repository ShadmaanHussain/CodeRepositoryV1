#include <iostream>
#include <cmath>
using namespace std;

//function for calculating geometric sum of 1 + 1/2 + 1/4 + 1/8 + ...... + 1/(2^k) recursively
float geo_sum(int k)
{
    if (k == 0)
    {
        return 1.0;
    }

    float sm_ans = geo_sum(k - 1);
    float c_val = pow(0.5, k);
    return c_val + sm_ans;
}

int main()
{
    int k;
    cin >> k;
    float ans = geo_sum(k);
    cout << ans;
    return 0;
}