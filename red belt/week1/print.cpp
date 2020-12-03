#include "test_runner.h"

#include <ostream>
using namespace std;

#define PRINT_VALUES(out, x, y) out << (x) << endl << (y) << endl

int main() {
    TestRunner tr;
    tr.RunTest([] {
        ostringstream output;
        PRINT_VALUES(output, 5, "red belt");
        ASSERT_EQUAL(output.str(), "5\nred belt\n");
    }, "PRINT_VALUES usage example #1");

    tr.RunTest([] {
        ostringstream output;
        PRINT_VALUES(output, 5+6, "red belt");
        ASSERT_EQUAL(output.str(), "11\nred belt\n");
    }, "PRINT_VALUES usage example #2");

    tr.RunTest([] {
        ostringstream output;

        PRINT_VALUES(output, min(1,3)*7, "red belt");
        ASSERT_EQUAL(output.str(), "7\nred belt\n");
    }, "PRINT_VALUES usage example #3");

    tr.RunTest([] {
        ostringstream output;

        PRINT_VALUES(output, min(1,3)*7, "red belt");
        PRINT_VALUES(output, min(1,3)*7, "red belt");
        ASSERT_EQUAL(output.str(), "7\nred belt\n7\nred belt\n");
    }, "PRINT_VALUES usage example #4");

    tr.RunTest([] {
        ostringstream output;
        if (false) PRINT_VALUES(output, 7, "red belt");

        ASSERT_EQUAL(output.str(), "");
    }, "PRINT_VALUES usage example #5");
}