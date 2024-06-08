#include <iostream>
using namespace std;

int lin_Search(int a[], int n, int x)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int no_of_tests;
    cin >> no_of_tests;
    for (int i = 0; i < no_of_tests; i++)
    {
        int a[100];
        int size;
        cin >> size;
        for (int j = 0; j < size; j++)
        {
            cin >> a[j];
        }
        int key;
        cin >> key;
        int index = lin_Search(a, size, key);
        cout << index << endl;
    }
    return 0;
}