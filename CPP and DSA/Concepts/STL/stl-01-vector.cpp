#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Vectors - Dynamic Sized Arrays
    // vector<int> v;
    // v.push_back(5);
    // v.push_back(6);
    // v.push_back(7);
    // Vectors can be used exaclty like arrays.
    // cout << v.size() << endl;
    // cout << v[0] << " " << v[1] << " " << v[2] << endl;
    // v.pop_back();
    // cout << v.size() << endl;
    // v.push_back(0);
    // v.clear();
    // cout << v.size() << endl;
    // cout << v[0] << " " << v[1] << " " << v[2] << endl;

    vector<int> v(50); // 50 elements all initialized to 0 i.e. {0, 0, 0, ......}
    vector<int> p(50, 7); // 50 elements all initialized to 7
    cout << v.size() << endl << p.size() << endl;
    vector<int> v[50]; // This is an array of 50 vectors
    return 0;
}