#include<bits/stdc++.h>
using namespace std;

int main() {
    int ar[4] = {5, 4, 1, 2};
    sort(ar, ar+3); // sort(pointer to first element, pointer to last element + 1); This can also be used to sort a certain portion of the array
    for(int i = 0; i < 4; i++) {
        cout << ar[i] << " ";
    }
    cout << endl;
    vector<int> v = {5, 1, 2, 0};
    sort(v.begin(), v.end()); // v.begin() and v.end() are called iterators v.begin() is the iterator for the first element and v.end() is the iterator for the element next to the last element
    for(int i = 0; i < 4; i++) {
        cout << v[i] << " ";
    }
    return 0;
}