#include<iostream>
#include<vector>
#include "templateclass.cpp"

using namespace std;

int main() {
    // Pair<int,char> newP;
    // newP.setX(5);
    // newP.setY('&');
    // cout << newP.getX() << " " << newP.getY() << endl;
    Pair<Pair<int,int>,int> p1;
    Pair<int,int> p2;
    p2.setX(10);
    p2.setY(20);
    p1.setY(30);
    p1.setX(p2);
    cout << p1.getX().getX() << " " << p1.getX().getY() << " " << p1.getY() << endl;
    return 0;
}