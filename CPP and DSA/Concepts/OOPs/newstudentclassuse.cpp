#include<bits/stdc++.h>
#include "newstudentclass.cpp"
using namespace std;

int main() {
    // Try running this code for both shallow and deep copy. Dry run the code to understand more.
    int age = 17;
    char name[] = "abcd";
    student s1(age, name);
    s1.display();
    name[3] = 'e';
    student s2(age, name);
    s2.display();
    s1.display(); 
    return 0;
}