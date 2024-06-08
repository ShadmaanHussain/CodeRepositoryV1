#include<iostream>
using namespace std;

// #naileditonmyfirsttry
void merge_sorted (int a[], int si, int mid, int ei) {
    int temp[100];
    int p = si;
    int q = mid + 1;
    int i = 0;
    while ((p <= mid) && (q <= ei)) {
        if (a[p] < a[q]) {
            temp[i] = a[p];
            p++; i++;
        }
        else {
            temp[i] = a[q];
            q++; i++;
        }
    }
    
    while (q <= ei) {
        temp[i] = a[q];
        i++; q++;
    }

    while (p <= mid) {
        temp[i] = a[p];
        i++; p++;
    }

    i = 0;
    for(int q = si; q <= ei; q++) {
        a[q] = temp[i];
        i++;
    }
}

void merge_sort(int a[], int si, int ei) {
    if (si >= ei) {
        return;
    }
    int mid = (si + ei) / 2;
    merge_sort(a, si, mid);
    merge_sort(a, mid+1, ei);
    merge_sorted(a, si, mid, ei);    
}

int main () {
    int a[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    merge_sort(a, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}