#include<bits/stdc++.h>
using namespace std;

int main () {
    //Set is a container that contains unique copy of every element in sorted order
    //You can't access the set elements using [] operators
    set<int> s;
    s.insert(10);
    s.insert(10); //inserting an element more than once does nothing if the element is already present in the set
    s.insert(13);
    s.insert(13);
    cout << s.count(13) << endl; //Checks if the element is present in the set or not.
    s.erase(13); //It will delete the element 13. It does not matter how many times it was inserted in the set. Only one value gets stored.
    cout << s.count(13) << endl;

    //Set Iterators
    set<int> p;
    p.insert(13);
    p.insert(1);
    p.insert(5);
    p.insert(12);
    p.insert(20);
    cout << *p.begin() << endl; // begin always returns the iterator to the smallest element in the set (This tells us that the set always keeps the elements in sorted order)
    p.erase(p.begin());
    cout << *p.begin() << endl;
    return 0;
}