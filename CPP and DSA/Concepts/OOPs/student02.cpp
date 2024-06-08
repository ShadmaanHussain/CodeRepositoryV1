using namespace std;

class Student {
    public:
    int age;
    const int Rno;
    int &x;

    Student(int age, int Rno) : age(age), Rno(Rno), x(this->age) {

    }

    void display() {
        cout << age << " " << Rno << " " << x << endl;
    }
};