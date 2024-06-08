using namespace std;

class car : virtual public vehicle {
    public: 
    car() {
        cout << "car's default constructor called" << endl;
    }
    car(int x) : vehicle(x) {
        cout << "car's parametrized Constructor Called." << endl;
    }

    // void print() {
    //     cout << "Vehicle's print function." << endl;
    // }
};