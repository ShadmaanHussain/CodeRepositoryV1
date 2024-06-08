#include<iostream>
using namespace std;

int arr_sum(int a[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += a[i];
    }
    return sum;
}

int main () {
    
    int a[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum = arr_sum(a, n);
    cout << sum;
    return 0;
}