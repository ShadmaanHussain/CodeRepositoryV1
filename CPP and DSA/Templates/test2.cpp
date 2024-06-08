#include <bits/stdc++.h>
using namespace std;

int ret_all_indices(int *a, int si, int ei, int key, int *opt, int osi = 0)
{
    if (si > ei)
    {
        return osi;
    }
    if (a[si] == key)
    {
        opt[osi] = si;
        osi++;
    }
    si++;
    return ret_all_indices(a, si, ei, key, opt, osi);
}

int main()
{
    int a[100], n, key;
    cin >> n;
    int opt[100];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> key;
    int size = ret_all_indices(a, 0, n - 1, key, opt);
    for (int i = 0; i < size; i++)
    {
        cout << opt[i] << " ";
    }
    return 0;
}