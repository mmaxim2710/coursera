#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>

class Figure {
public:
    virtual std::string Name() const = 0;
    virtual double Perimeter() = 0;
    virtual double Area() = 0;
};

class Rect : public Figure {
public:
    Rect() : a_(0), b_(0), name("RECT") {}
    Rect(const double& a, const double& b) : a_(a), b_(b), name("RECT") {}

    std::string Name() const override {
        return name;
    }

    double Perimeter() override {
        return a_ * 2 + b_ * 2;
    }

    double Area() override {
        return a_ * b_;
    }

private:
    double a_, b_;
    std::string name;
};

class Triangle : public Figure {
public:
    Triangle() : a_(0), b_(0), c_(0), name("TRIANGLE") {}
    Triangle(const double& a, const double& b, const double& c) : a_(a), b_(b), c_(c), name("TRIANGLE") {}

    std::string Name() const override {
        return name;
    }

    double Perimeter() override {
        return a_ + b_ + c_;
    }

    double Area() override {
        double p = Perimeter() / 2;
        return sqrt(p * (p - a_) * (p - b_) * (p - c_));
    }

private:
    double a_, b_, c_;
    std::string name;
};

class Circle : public Figure {
public:
    Circle() : r_(0), name("CIRCLE") {}
    Circle(const double& r) : r_(r), name("CIRCLE") {}

    std::string Name() const override {
        return name;
    }

    double Perimeter() override {
        return 2 * 3.14 * r_;
    }

    double Area() override {
        return 3.14 * r_ * r_;
    }

private:
    double r_;
    std::string name;
};

std::shared_ptr<Figure> CreateFigure(std::istringstream& is) {
    std::string name;
    is >> name;
    if(name == "TRIANGLE") {
        double a = 0, b = 0, c = 0;
        is >> a >> b >> c;
        return std::make_shared<Triangle>(a, b, c);
    } else if(name == "RECT") {
        double a = 0, b = 0;
        is >> a >> b;
        return std::make_shared<Rect>(a, b);
    } else if(name == "CIRCLE") {
        double r = 0;
        is >> r;
        return std::make_shared<Circle>(r);
    }
    throw std::logic_error("invalid name of figure");
}

int main() {
    std::vector<std::shared_ptr<Figure>> figures;
    for (std::string line; getline(std::cin, line); ) {
        std::istringstream is(line);

        std::string command;
        is >> command;
        if (command == "ADD") {
            // Пропускаем "лишние" ведущие пробелы.
            // Подробнее об std::ws можно узнать здесь:
            // https://en.cppreference.com/w/cpp/io/manip/ws
            is >> std::ws;
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                std::cout << std::fixed << std::setprecision(3)
                     << current_figure->Name() << " "
                     << current_figure->Perimeter() << " "
                     << current_figure->Area() << std::endl;
            }
        }
    }
    return 0;
}