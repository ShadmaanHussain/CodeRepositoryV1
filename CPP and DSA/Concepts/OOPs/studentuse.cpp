#include<bits/stdc++.h>
#include "student.cpp"
using namespace std;

int main () {
    //Creating object Statically
    Student s1;
    s1.Rno = 101;
    s1.setAge(15, 123);
    s1.display();

    //Creating objects dynamically
    Student *s2 = new Student;
    s2->Rno = 102;
    s2->setAge(21, 123);
    s2->display();

    Student s3(21);
    s3.display();

    // Calling Parametrised Constructor for a Dynamic Object
    Student *s4 = new Student(15);
    s4->display();

    Student s5(15, 100);
    s5.display();

    // this keyword
    Student s6(21, 98);
    cout << "Address of s6: " << &s6 << endl;
    s6.display();

    delete s2;
    delete s4;
    return 0;
}