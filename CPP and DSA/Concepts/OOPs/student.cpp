using namespace std;

class Student {
    private:
    int age;
    

    public:
    int Rno;
    // Default Constructor (Comment this out and try to create an object with no arguments and see what happens. Can you explain what happened?)
    Student() {
        cout << "Constructor Called!" << endl;
    }

    // Parametrised Constructors
    Student(int a) {
        cout << "Parametrised Constructor 1 called!" << endl;
        age = a;
    }

    Student(int a, int r) {
        cout << "Parametrised Constructor 2 called!" << endl;
        age = a;
        Rno = r;
    }

    // Creating a display method
    void display() {
        cout << age << " " << Rno << endl;
        // cout << "this: " << this << endl;
    }

    // Getter
    int getAge() {
        return age;
    }

    // Setter
    void setAge(int n, int pass) {
        if ((pass == 123) && (n >= 0)) {
            age = n;
        }
    }

    ~Student() {
        cout << "Destructor Called!" << endl;
    }

};