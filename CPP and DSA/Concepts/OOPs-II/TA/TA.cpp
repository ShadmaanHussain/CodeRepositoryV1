using namespace std;

class TA : public teacher, public student {
    public:
    void print() {
        cout << "TA" << endl;
    }
};