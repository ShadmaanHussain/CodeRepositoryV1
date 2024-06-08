using namespace std;

class vehicle {
    int tyres;
    public:
    vehicle() {
        cout << "vehicle's default constructor called" << endl;
    }
    vehicle(int x) {
        tyres = x;
        cout << "Vehicle's parametrized Constructor Called." << endl;
    }

    void print() {
        cout << "Vehicle's print function." << endl;
    }
};