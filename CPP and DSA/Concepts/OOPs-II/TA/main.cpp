#include<iostream>
#include "teacher.cpp"
#include "student.cpp"
#include "TA.cpp"
using namespace std;

int main() {
    TA t;
    t.teacher::print();
    return 0;
}