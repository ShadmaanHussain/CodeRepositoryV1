#include <iostream>
using namespace std;

int last_index(int a[], int size, int key)
{
    if (size == 0)
    {
        return -1;
    }
    if (a[size - 1] == key)
    {
        return size - 1;
    }

    int rcall = last_index(a, size - 1, key);

    if (rcall == -1)
    {
        return -1;
    }
    else
    {
        return rcall;
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

    int key;
    cin >> key;

    //Calling the function last_index
    int index = last_index(a, n, key);
    cout << index;

    return 0;
}