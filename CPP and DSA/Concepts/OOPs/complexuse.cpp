#include<bits/stdc++.h>
#include "complexnum.cpp" 
using namespace std;

int main() {
    Complex c1(5, 4), c2(3, 8);
    c1.display();
    c2.display();
    c1.add(c2);
    c1.display();
    c2.multiply(c1);
    c2.display();
    return 0;
}