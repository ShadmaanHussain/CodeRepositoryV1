#include <iostream>
using namespace std;

int all_indices(int a[], int size, int key, int opt[])
{
    if (size == 0)
    {
        return 0;
    }

    int sizesmall = all_indices(a + 1, size - 1, key, opt);
    
    for (int i = 0; i < sizesmall; i++)
    {
        opt[i]++;
    }
    if (a[0] == key)
    {
        for (int i = sizesmall - 1; i >= 0; i--)
        {
            opt[i + 1] = opt[i];
        }
        opt[0] = 0;
        return 1 + sizesmall;
    }
    else
    {
        return sizesmall;
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
    int x;
    cin >> x;
    int opt[100];

    int size = all_indices(a, n, x, opt);

    //Printing an array
    for (int i = 0; i < size; i++)
    {
        cout << opt[i] << " ";
    }

    return 0;
}

// ----------------------------------------------Alternate Solution----------------------------------------------

// #include <bits/stdc++.h>
// using namespace std;

// int ret_all_indices(int *a, int si, int ei, int key, int *opt, int osi = 0)
// {
//     if (si > ei)
//     {
//         return osi;
//     }
//     if (a[si] == key)
//     {
//         opt[osi] = si;
//         osi++;
//     }
//     si++;
//     return ret_all_indices(a, si, ei, key, opt, osi);
// }

// int main()
// {
//     int a[100], n, key;
//     cin >> n;
//     int opt[100];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     cin >> key;
//     int size = ret_all_indices(a, 0, n - 1, key, opt);
//     for (int i = 0; i < size; i++)
//     {
//         cout << opt[i] << " ";
//     }
//     return 0;
// }