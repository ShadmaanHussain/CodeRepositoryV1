#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int si, int ei) {
    int x = a[si], count = 0;
    for (int i = si + 1; i <= ei; i++) {
        if (a[i] < x) {
            count++;
        }
    }
    swap(a[si], a[count]);
    int p = si, q = count + 1;
    for (; p < count; p++) {
        if(a[p] >= x) {
            for (; q <= ei; q++) {
                if (a[q] < x) {
                    swap(a[p], a[q]);
                    q++;
                    break;
                }
            }
        }
    }
    return count;
}

void quick_sort (int a[], int si, int ei) {
    if (si >= ei) {
        return;
    }
    int i = partition(a, si, ei);
    quick_sort(a, si, i - 1);
    quick_sort(a, i + 1, ei);
}

int main()
{
    int a[] = {5, 2, 3, 7, 9, 1, 4, 10};
    quick_sort(a, 0, 7);
    for (int i = 0; i < 8; i++) {
        cout << a[i] << " ";
    }
    return 0;
}