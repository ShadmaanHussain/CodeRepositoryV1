#include<bits/stdc++.h>
#include "fractions.cpp"
using namespace std;

int main () {
    Fraction f1(5, 4);
    // Fraction f2(10, 8);
    // f1.print();
    // f2.print();
    // f1.add(f2);
    // f1.print();
    // f1.multiply(f2);

    // Fraction f3 = f1 + f2;
    // f3.print();
    // Fraction f4 = f1 * f2;
    // f4.print();
    // // f1.print();
    // bool areEqual = (f1 == f2);
    // cout << areEqual << endl;

    // f1.print();
    // Fraction f2 = ++(++f1);
    // f1.print();
    // f2.print();
    f1.print();
    // Fraction f2 = f1++;
    Fraction f2(3, 4);
    (f1 += f2) += f2;
    f1.print();
    f2.print();

    return 0;
}