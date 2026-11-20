#include <iostream>
using namespace std;

class Assessment {
public:
    virtual void calculateMarks() = 0;
    virtual ~Assessment() = default;
};

class Quiz : public Assessment {
    int marks;
public:
    explicit Quiz(int m) : marks(m) {}

    void calculateMarks() override {
        cout << "Quiz Marks: " << marks << endl;
    }
};

class Assignment : public Assessment {
    int marks;
public:
    explicit Assignment(int m) : marks(m) {}

    void calculateMarks() override {
        cout << "Assignment Marks: " << marks << endl;
    }
};

class Marks {
    int value;
public:
    Marks(int v = 0) : value(v) {}

    Marks operator+(const Marks& m) const {
        return Marks(value + m.value);
    }

    int getValue() const {
        return value;
    }
};

int main() {
    Quiz q(15);
    Assignment a(25);

    q.calculateMarks();
    a.calculateMarks();

    Marks m1(15), m2(25);
    Marks total = m1 + m2;

    cout << "Total Assessment Marks: " << total.getValue() << endl;

    return 0;
}
