#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <vector>
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

bool operator<(const Rational& lhs, const Rational& rhs) {
    int p_lhs = lhs.Numerator();
    int q_lhs = lhs.Denominator();
    int p_rhs = rhs.Numerator();
    int q_rhs = rhs.Denominator();

    int res_p_lhs, res_p_rhs;

    res_p_lhs = p_lhs * q_rhs;
    res_p_rhs = p_rhs * q_lhs;

    return res_p_lhs < res_p_rhs;
}

bool operator>(const Rational& lhs, const Rational& rhs) {
    int p_lhs = lhs.Numerator();
    int q_lhs = lhs.Denominator();
    int p_rhs = rhs.Numerator();
    int q_rhs = rhs.Denominator();

    int res_p_lhs, res_p_rhs;

    res_p_lhs = p_lhs * q_rhs;
    res_p_rhs = p_rhs * q_lhs;

    return res_p_lhs > res_p_rhs;
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}