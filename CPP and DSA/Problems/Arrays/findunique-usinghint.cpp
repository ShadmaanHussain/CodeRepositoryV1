#include<iostream>
using namespace std;

int findUnique(int *arr, int size)

{
    for (int i = 0; i < size; i++)
    {
        int j;
        for (j = 0; j < size; j++)
        {
            if ((i == j) || (arr[i] != arr[j]))
            {
                continue;
            }
            else
            {
                break;
            }
        }
        if (j < size)
        {
            continue;
        }
        else
        {
            return arr[i];
        }
    }
}

int main()
{
    
}