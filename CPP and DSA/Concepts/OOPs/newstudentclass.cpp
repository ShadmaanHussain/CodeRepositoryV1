using namespace std;

class student {
    private:
    int age;
    
    public:
    char *name;
    student(int age, char *name) {
        this->age = age;
        // Shallow Copy
        // this->name = name; 

        // Deep Copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    student(student& s) {    
        this->age = s.age;
        // this->name = s.name; // Shallow Copy
        // Deep Copy
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
    }

    void display() {
        cout << age << " " << name << endl;
    }
};