//Selection Sort Algorithm
#include <iostream>
using namespace std;

//Selection Sort Function
void selec_sort(int a[], int n)
{
    //This for loop iterates and seperates the sorted part from the unsorted part
    for (int i = 0; i < n - 1; i++)
    {
        int minindex = i;
        //Finding the minimum index in the unsorted part
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[minindex])
            {
                minindex = j;
            }
        }
        //Swapping the minimum value with the value at the start of unsorted array
        int temp = a[i];
        a[i] = a[minindex];
        a[minindex] = temp;
    }
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
    //Function call and printing the sorted array
    selec_sort (a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}