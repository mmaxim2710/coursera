#include <iostream>
#include <cmath>
using namespace std;

int NOD(int a, int b) {
    
    while(a != 0 && b != 0) {
        if(a > b) a %= b;
        else b %= a;
    }
    
    return a + b;
}

class Rational {
public:
    Rational() : p(0), q(1) {
    }

    Rational(int numerator, int denominator) {
        if(numerator == 0) {
            p = numerator;
            q = 1;
        }
        else {
            int get_nod = NOD(std::abs(numerator), std::abs(denominator));
            p = numerator / get_nod;
            q = denominator / get_nod;
            if((p >= 0 && q < 0) || (p < 0 && q < 0)) {
                p *= -1;
                q *= -1;
            }
        }
    }

    int Numerator() const {
        return p;
    }

    int Denominator() const {
        return q;
    }

private:
    int p, q;
};

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}