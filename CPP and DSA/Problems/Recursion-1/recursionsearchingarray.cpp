#include<iostream>
using namespace std;

bool isPresent(int a[], int size, int key) 
{
    if(size == 1)
    {
        if(a[0] == key)
        {
            return true;
        }
        return false;
    }
    if(a[0] == key)
    {
        return true;
    }
    bool presence = isPresent(a + 1, size - 1, key);
    return presence;
    
}

int main () {
    //Input the number of elements and the array
    int n; 
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int key;
    cin >> key;

    //Calling isPresent
    bool presence = isPresent(a, n, key);
    cout << presence;

    return 0;
}