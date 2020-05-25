#include <iostream>
#include <cmath>
#include <sstream>
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

bool operator==(const Rational& lhs, const Rational& rhs) {
    return ((lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator()));
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    int p_lhs = lhs.Numerator();
    int q_lhs = lhs.Denominator();
    int p_rhs = rhs.Numerator();
    int q_rhs = rhs.Denominator();

    int res_p, res_q;

    if(q_lhs != q_rhs) {
        res_q = q_lhs * q_rhs;
        res_p = p_lhs * q_rhs + p_rhs * q_lhs;
    }
    else {
        res_p = p_lhs + p_rhs;
        res_q = q_lhs;
    }

    Rational answer(res_p, res_q);

    return answer;
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    int p_lhs = lhs.Numerator();
    int q_lhs = lhs.Denominator();
    int p_rhs = rhs.Numerator();
    int q_rhs = rhs.Denominator();

    int res_p, res_q;

    if(q_lhs != q_rhs) {
        res_q = q_lhs * q_rhs;
        res_p = p_lhs * q_rhs - p_rhs * q_lhs;
    }
    else {
        res_p = p_lhs - p_rhs;
        res_q = q_lhs;
    }

    Rational answer(res_p, res_q);

    return answer;
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    int p_lhs = lhs.Numerator();
    int q_lhs = lhs.Denominator();
    int p_rhs = rhs.Numerator();
    int q_rhs = rhs.Denominator();

    int res_p, res_q;

    res_p = p_lhs * p_rhs;
    res_q = q_lhs * q_rhs;

    Rational answer(res_p, res_q);

    return answer;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    int p_lhs = lhs.Numerator();
    int q_lhs = lhs.Denominator();
    int p_rhs = rhs.Numerator();
    int q_rhs = rhs.Denominator();

    int res_p, res_q;

    res_p = p_lhs * q_rhs;
    res_q = q_lhs * p_rhs;

    Rational answer(res_p, res_q);

    return answer;
}

istream& operator>>(istream& is, Rational& input) {
    int p, q;
    
    if((is >> p) && (is.ignore(1)) && (is >> q)) {
        input = {p, q};
    }

    return is;
}

ostream& operator<<(ostream& os, const Rational& output) {
    os << output.Numerator() << '/' << output.Denominator(); 
    
    return os;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}