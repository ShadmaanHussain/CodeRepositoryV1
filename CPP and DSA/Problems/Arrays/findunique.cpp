#include <iostream>
using namespace std;

void arr_init(int *, int);
void arr_print(int *, int);

// First Attempt - Not working for many test cases
int findunique(int *a, int n)
{
    int smar[100];
    int p, q, flag;
    p = q = 0;
    for (int i = 0; i < n; i++)
    {
        flag = 0;
        for (int j = 0; j < p; j++)
        {
            if (a[i] == smar[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            smar[p] = a[i];
            p++;
        }
        else
        {
            if (a[i] == smar[q])
            {
                q++;
            }
        }
    }
    return smar[q];
}

int main()
{
    int n;
    int ar[100];
    cin >> n;
    arr_init(ar, n);
    int unique = findunique(ar, n);
    cout << unique;
    return 0;
}

void arr_init(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void arr_print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}