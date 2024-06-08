#include <iostream>
using namespace std;

int indx_of_num(int a[], int size, int key)
{
    //if the element is not found the size of array will be 0
    if (size == 0)
    {
        return -1;
    }

    //if the element is found at index 0 (even for a subarray or the array) we return 0
    if (a[0] == key)
    {
        return 0;
    }

    //Checking what subarray returns
    int rval = indx_of_num(a + 1, size - 1, key);

    //if it returns -1 we propagate the return value
    if (rval == -1)
    {
        return -1;
    }
    //if it returns 0 we add 1 at every step so that the final value coming out of the function call is the correct index of the element.
    else
    {
        return 1 + rval;
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
    int k;
    cin >> k;

    //Calling the function
    int found = indx_of_num(a, n, k);
    cout << found;

    return 0;
}