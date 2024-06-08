#include <iostream>
using namespace std;

int ans[100];
int i = 0;

void all_indices(int a[], int size, int key)
{
    if (size == 0)
    {
        return;
    }
    if (a[size - 1] == key)
    {
        ans[i] = size - 1;
        i++;
    }
    all_indices(a, size - 1, key);
}

int main()
{
    //Input the number of elements and the array
    for(int i = 0; i < 100; i++)
    {
        ans[i] = -1;
    }
    int n;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int key;
    cin >> key;

    all_indices(a, n, key);

    int j = 0;
    while (ans[j] != -1)
    {
        cout << ans[j] << " ";
        j++;
    }

    return 0;
}