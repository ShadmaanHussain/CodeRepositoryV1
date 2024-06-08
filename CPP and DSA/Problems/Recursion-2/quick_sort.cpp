#include <iostream>
using namespace std;
void swap(int &, int &);

int partition(int a[], int si, int ei)
{
    int x = a[si], count = 0;
    for (int i = si + 1; i <= ei; i++)
    {
        if (a[i] < x)
        {
            count++;
        }
    }
    int c = si + count;
    swap(a[si], a[c]);
    int i = si, j = ei;
    while ((i < c) || (j > c))
    {
        if ((a[i] >= x) && (a[j] < x))
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
        if (a[i] < x)
        {
            i++;
        }
        if (a[j] >= x)
        {
            j--;
        }
    }
    return c;
}

void quick_sort(int a[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int c = partition(a, si, ei);
    quick_sort(a, si, c - 1);
    quick_sort(a, c + 1, ei);
}

int main()
{
    int a[100], n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quick_sort(a, 0, n-1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}