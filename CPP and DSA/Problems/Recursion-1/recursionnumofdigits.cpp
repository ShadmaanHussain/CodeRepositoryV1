#include <iostream>
using namespace std;

int count(int n)
{   
    if (n / 10 == 0) {
        return 1;
    }
    
    int ct = 1 + count (n/10);
    return ct;
}

int main()
{
    int n;
    cin >> n;
    int opt = count(n);
    cout << opt << endl;
    return 0;
}