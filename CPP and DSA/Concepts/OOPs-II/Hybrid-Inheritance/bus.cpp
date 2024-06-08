using namespace std;

class bus : public car, public truck {
    public:
    bus(int x) : vehicle(x) {
        cout << "bus's Constructor Called." << endl;
    }

    // void print() {
    //     cout << "bus's print function." << endl;
    // }
};