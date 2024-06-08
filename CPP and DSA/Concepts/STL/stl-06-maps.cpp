#include<bits/stdc++.h>
using namespace std;

//Maps (Special types of arrays with key-value pairs)
int main () {
    map<int,int> m;
    cout << m.size() << endl;
    cout << m[15] << endl; //This instantly creates the element and assigns the value 0 to it.
    cout << m.size() << endl;
    //Assigning key-value pairs in map
    m[10] = 13;
    m[-1] = 20;
    cout << m[-1] << endl;
    cout << m.size() << endl;

    // Maps are very convinient for storing frequency of something.
    map<int,int> freq;
    freq[10]++;
    freq[10]++;
    freq[10]++;
    freq[10]++;
    cout << freq[10] << " " << freq[4] << endl;
    return 0;
}