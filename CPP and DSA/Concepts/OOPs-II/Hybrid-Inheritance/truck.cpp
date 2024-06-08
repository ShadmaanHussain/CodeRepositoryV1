using namespace std;

class truck : virtual public vehicle {
    public:
    truck() {
        cout << "truck's default constructor called." << endl;
    }
    truck(int x) : vehicle(x) {
        cout << "truck's parametrized Constructor Called." << endl;
    }

    // void print() {
    //     cout << "truck's print function." << endl;
    // }
};