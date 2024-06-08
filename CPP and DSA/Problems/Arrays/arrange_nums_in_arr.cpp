#include <iostream>
using namespace std;

void arr_print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void arrange(int a[], int n)
{
    a[0] = 1;
    if (n % 2 == 0)
    {
        for (int i = 1; i < n / 2; i++)
        {
            a[i] = a[i - 1] + 2;
        }
        a[n / 2] = n;
        for (int i = n / 2 + 1; i < n; i++)
        {
            a[i] = a[i - 1] - 2;
        }
    }
    else
    {
        for (int i = 1; i <= n / 2; i++)
        {
            a[i] = a[i - 1] + 2;
        }
        a[n / 2 + 1] = n - 1;
        for (int i = n / 2 + 2; i < n; i++)
        {
            a[i] = a[i - 1] - 2;
        }
    }
}

int main()
{

    int a[100];
    int no_of_tests;
    cin >> no_of_tests;
    int n[100];
    for (int i = 0; i < no_of_tests; i++)
    {
        cin >> n[i];
    }
    for (int i = 0; i < no_of_tests; i++)
    {
        arrange(a, n[i]);
        arr_print(a, n[i]);
        cout << endl;
    }
    return 0;
}