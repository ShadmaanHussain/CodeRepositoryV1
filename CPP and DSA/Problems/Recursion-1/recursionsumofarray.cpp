#include<iostream>
using namespace std;

int arraySum(int a[], int size)
{
    if(size == 1)
    {
        return a[0];
    }

    // Current Sum = 0th element + Sum of the smaller array
    int smallerSum = a[0] + arraySum(a + 1, size -1);
    return smallerSum;
}

int main () {
    //Input the number of elements and the array
    int n; 
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    //Calling arraySum function
    int sum = arraySum(a, n);
    cout << sum;

    return 0;
}