#include <iostream>
using namespace std;

int bin_search(int a[], int n, int key)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (key == a[mid])
        {
            return mid;
        }
        else if (key > a[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter Key: " << endl;
    int key;
    cin >> key;
    cout << bin_search(arr, n, key);
    return 0;
}