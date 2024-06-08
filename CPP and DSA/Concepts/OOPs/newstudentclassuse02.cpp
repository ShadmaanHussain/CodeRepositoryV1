#include<bits/stdc++.h>
#include "newstudentclass.cpp"
using namespace std;

int main() {
    // Do this using both the default copy constructor and using the new copy constructor
    char name[] = "Shadmaan";
    student s1(17, name);
    s1.display();
    student s2(s1);
    s2.name[0] = 'Z';
    s1.display();
    s2.display();
    return 0;
}
