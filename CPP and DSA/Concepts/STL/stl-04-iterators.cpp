#include<bits/stdc++.h>
using namespace std;

int main () {
    vector<int> v = {10, 15, 20, 25};
    //Creating an iterator it (They are similar to pointers)
    auto it = v.begin(); //auto keyword automatically deduces the data type of the iterator.
    cout << *it << endl;
    cout << *(it+3) << endl;
    return 0;
}