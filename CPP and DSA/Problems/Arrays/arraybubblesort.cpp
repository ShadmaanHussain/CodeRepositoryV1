#include <iostream>
using namespace std;

void bubble_sort(int a[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            if (a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
            }
        }
    }
}

int main()
{
    //Input the number of elements and the array
    int n;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    //Calling Bubble Sort
    bubble_sort (a, n);

    //Printing an array
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}