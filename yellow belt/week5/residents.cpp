#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human {
public:
    Human() : Name("null") {}

    Human(const string& name, const string& type) : Name(name), Type(type) {}

    virtual void Walk(const string& destination) {
        cout << this->Type << ": " << GetName() << " walks to: " << destination << endl;
    };

    string GetName() {
        return Name;
    }

    string GetType() {
        return Type;
    }

private:
    string Name;
    string Type;
};

class Student : public Human {
public:

    Student(const string& name, const string& favouriteSong, const string& type = "Student") :
            Human(name, type), FavouriteSong(favouriteSong) {
    }


    void Learn() {
        cout << "Student: " << GetName() << " learns" << endl;
    }

    void Walk(const string& destination) override {
        cout << "Student: " << GetName() << " walks to: " << destination << endl;
        SingSong();
    }

    void SingSong() {
        cout << "Student: " << GetName() << " sings a song: " << FavouriteSong << endl;
    }

public:
    string FavouriteSong;
};


class Teacher : public Human {
public:

    Teacher(const string& name, const string& subject, const string& type = "Teacher") :
            Human(name, type), Subject(subject) {}

    void Teach() {
        cout << "Teacher: " << GetName() << " teaches: " << Subject << endl;
    }

public:
    string Subject;
};


class Policeman : public Human {
public:
    Policeman(const string& name, const string& type = "Policeman") : Human(name, type) {}

    void Check(Human& human) {
        cout << "Policeman: " << GetName() << " checks "<< human.GetType() << ". "
             << human.GetType() << "'s name is: " << human.GetName() << endl;
    }
};


void VisitPlaces(Human& human, const vector<string>& places) {
    for (auto p : places) {
        human.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    VisitPlaces(s, {"Moscow", "London"});
    VisitPlaces(p, {"Moscow", "London"});
    p.Check(t);
    p.Check(s);

    Policeman p2("Maxim");
    p.Check(p2);

    s.Learn();
    s.SingSong();

    t.Teach();

    p.Check(p);
    return 0;
}

/*
 * tests:

Teacher: Jim walks to: Moscow
Teacher: Jim walks to: London
Policeman: Bob checks Student. Student's name is: Ann
Student: Ann walks to: Moscow
Student: Ann sings a song: We will rock you
Student: Ann walks to: London
Student: Ann sings a song: We will rock you

 */