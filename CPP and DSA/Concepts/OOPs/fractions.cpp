using namespace std;

class Fraction
{
private:
    int num;
    int den;

public:
    Fraction() {

    }

    Fraction(int num, int den)
    {
        this->num = num;
        this->den = den;
    }

    // Prints the fraction on the console
    void print()
    {
        cout << num << "/" << den << endl;
    }

    // Adds the fraction f to the current object
    Fraction add(Fraction const &f) const
    {
        int lcm = den * f.den;
        int x = num * f.den;
        int y = f.num * den;
        // num = x + y;
        // den = lcm;
        Fraction fnew(x + y, lcm);
        fnew.simplify();
        return fnew;
    }

    // Operator Overloading
    Fraction operator+(Fraction const &f) const
    {
        int lcm = den * f.den;
        int x = num * f.den;
        int y = f.num * den;
        // num = x + y;
        // den = lcm;
        Fraction fnew(x + y, lcm);
        fnew.simplify();
        return fnew;
    }

    // Simplifying the fractions
    void simplify()
    {
        int max = (num > den) ? num : den;
        int hcf = 1;
        for (int i = 2; i <= max; i++)
        {
            if ((num % i == 0) && (den % i == 0))
            {
                hcf = i;
            }
        }
        num = num / hcf;
        den = den / hcf;
    }

    Fraction multiply(Fraction const &f) const
    {
        Fraction ans;
        ans.num = num * f.num;
        ans.den = den * f.den;
        ans.simplify();
        return ans;
    }

    Fraction operator*(Fraction const &f) const
    {
        Fraction ans;
        ans.num = num * f.num;
        ans.den = den * f.den;
        ans.simplify();
        return ans;
    }

    bool operator==(Fraction const &f) const {
        Fraction f1(num, den);
        Fraction f2(f);
        f1.simplify();
        f2.simplify();
        if(f1.num == f2.num && f1.den == f2.den) {
            return true;
        }
        return false;
    }

    Fraction& operator++() {
        num = num + den;
        simplify();
        return *this;
    }

    Fraction operator++(int) {
        Fraction fNew(num, den);
        num = num + den;
        simplify();
        fNew.simplify();
        return fNew;
    }

    Fraction& operator+=(Fraction const& f) {
        int lcm = den * f.den;
        int x = num * f.den;
        int y = f.num * den;
        num = x + y;
        den = lcm;
        simplify();
        return (*this);
    }
};