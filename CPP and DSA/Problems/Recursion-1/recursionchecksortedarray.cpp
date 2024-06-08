#include <iostream>
using namespace std;

bool isSorted(int a[], int size)
{
    if(size == 0 || size == 1)
    {
        return true;
    }
    if(a[0] > a[1])
    {
        return false;
    }
    bool isSmallerTrue = isSorted(a + 1, size - 1);
    return isSmallerTrue;
}

int main()
{
    //Input the number of elements and the array
    int n; 
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool checkarray = isSorted(a, n);
    cout << checkarray;
    return 0;
}