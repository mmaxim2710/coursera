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

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}