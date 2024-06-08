#include<iostream>
using namespace std;

int main () {
    char name[100];
    cout << "Enter your name: " << endl;
    // Taking string input using cin.
    cin >> name; 
    cout << name << endl;

    char str[100] = "abc";
    // Now the 3rd index will have a null character. Let's store some character on the 4th index and print the string.
    str[4] = 'x';
    cout << str << endl;
    // Since cout will print the string up until it reaches the null char it won't print x.
    cout << str[4] << endl;
    cout << str[3] << endl;
    // Now what if we replace the null char with some other character. cout should print all the garbage values until it encounters another null character
    str[3] = 'z';
    str[5] = 'n';
    cout << str << endl;
    str[1] = '\0'; // Putting the null char in the first index
    cout << str << endl; // It prints a and then stops
    return 0;
}