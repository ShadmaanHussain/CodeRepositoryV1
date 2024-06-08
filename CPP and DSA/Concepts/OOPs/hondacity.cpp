using namespace std;
class hondacity : public car
{   public:
    hondacity(int x) : car(x) {
        cout << "HondaCity's Const Called." << endl;
    }

    ~hondacity() {
        cout << "Hondacity dest called" << endl;
    }
};