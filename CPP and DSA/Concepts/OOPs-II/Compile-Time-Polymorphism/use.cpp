#include<iostream>
#include "vehicle.cpp"
#include "car.cpp"


using namespace std;

int main() {
    vehicle v1;
    car c;
    v1.print();
    c.print();

    vehicle *v2 = new vehicle;
    v2->print();
    v2 = &c;
    v2->print();
    return 0;
}