#include <iostream>

class Incognizable {
    private:
        int a, b;
    public:
        Incognizable() {}
        Incognizable(int arg1) : a(arg1) {}
        Incognizable(int arg1, int arg2) : a(arg1), b(arg2) {}
};

int main() {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}
