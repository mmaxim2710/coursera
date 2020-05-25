#include <iostream>
#include <string>

struct Specialization {
    std::string value;
    explicit Specialization(std::string new_value) {
        value = new_value;
    }
};

struct Course {
    std::string value;
    explicit Course(std::string new_value) {
        value = new_value;
    }
};

struct Week {
    std::string value;
    explicit Week(std::string new_value) {
        value = new_value;
    }
};

struct LectureTitle {
    std::string specialization;
    std::string course;
    std::string week;
    LectureTitle(Specialization spec, Course cour, Week wee) {
        specialization = spec.value;
        course = cour.value;
        week = wee.value;
    }
};