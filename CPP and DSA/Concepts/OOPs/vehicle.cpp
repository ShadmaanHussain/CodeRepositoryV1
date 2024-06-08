using namespace std;
class vehicle
{
    private:
    int numTyres;

    protected:
    int isNew;

    public:
    int hasMotor;

    vehicle() {
        cout << "vehicle constructor called" << endl;
    }

    vehicle(int x) {
        cout << "Vehicle's parametrized constructor." << endl;
        numTyres = x;
    }

    ~vehicle() {
        cout << "vehicle destructor called" << endl;
    }
};