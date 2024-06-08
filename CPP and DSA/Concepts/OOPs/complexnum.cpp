using namespace std;

class Complex {
    private:
    int real;
    int imag;

    public:
    Complex(int r, int i) {
        real = r;
        imag = i;
    }

    // Addition
    void add(Complex const &c) {
        real = real + c.real;
        imag = imag + c.imag;
    }

    // Multiply
    void multiply(Complex const &c) {
        int treal = real * c.real - imag * c.imag;
        int timag = real * c.imag + c.real * imag;
        real = treal;
        imag = timag;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};