#include<iostream>
using namespace std;

void arrange_nums(int a[], int n)
{
    int s = 0;
    int e = n - 1;
    int flag = 0;
    int val = s + 1;
    while (s <= e)
    {
        if (flag == 0)
        {
            a[s] = val;
            s++;
            val++;
            flag = 1;
        }
        else
        {
            a[e] = val;
            e--;
            val++;
            flag = 0;
        }
    }
}

void arr_print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main () {

    int a[100];
    int n;
    cin >> n;
    arrange_nums(a, n);
    arr_print(a, n);

    return 0;
}