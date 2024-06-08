#include<bits/stdc++.h>
#include "student.cpp"
using namespace std;

int main () {
    // Using the copy constructor
    Student s1(10, 500);
    Student s2(s1);
    s2.display();

    Student *s3 = new Student(s1);
    s3->display();

    Student s4(*s3);
    s4.display();

    Student s5;
    s5 = s4; // Using the copy assignment operator
    s5.display();

    Student s6(20, 511);
    Student *s7 = new Student;
    *s7 = s6;
    s7->display();

    delete s3;
    delete s7;
    return 0;
}