using namespace std;
class car : public vehicle {
    private:
    int numGears;

    public:
    char color;

    car() {
        cout << "car constructor called" << endl;
    }

    car(int x) : vehicle(x) {
        cout << "Car's constructor with initialization list." << endl;
    }

    ~car() {
        cout << "car destructor called" << endl;
    }
};