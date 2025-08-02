#include <iostream>
#include <vector>
using namespace std;
// MAKING CGPA CALCULATOR
class Subject {
public:
    string subjectname;
    int credit;
    float gradepoint;

    // Constructor
    Subject(string name, int c, float gp) {
        subjectname = name;
        credit = c;
        gradepoint = gp;
    }
};

class Student {
public:
    string name;
    vector<Subject> subjects;

    // Constructor
    Student(string studentname) {
        name = studentname;
    }

    void addSubject(string subjectname, int credit, float gradepoint) {
        Subject newSubject(subjectname, credit, gradepoint);
        subjects.push_back(newSubject);
    }

    float calculateCGPA() {
        int totalCredit = 0;
        float weightedGradePoint = 0;

        for (const Subject &subject : subjects) {
            totalCredit += subject.credit;
            weightedGradePoint += subject.credit * subject.gradepoint;
        }

        return (totalCredit > 0) ? (weightedGradePoint / totalCredit) : 0.0;
    }

    void displayCGPA() {
        cout << "\nStudent Name: " << name << endl;
        float cgpa = calculateCGPA();
        cout << "CGPA: " << cgpa << endl;
    }
};

int main() {
    string studentName;
    int numSubjects;

    cout << "Enter student's name: ";
    getline(cin, studentName);

    cout << "Enter the number of subjects: ";
    cin >> numSubjects;

    Student student(studentName);

    for (int i = 0; i < numSubjects; i++) {
        string subjectName;
        int credit;
        float gradepoint;

        cout << "\nEnter subject name: ";
        cin.ignore(); 
        getline(cin, subjectName);

        cout << "Enter credits for " << subjectName << ": ";
        cin >> credit;

        cout << "Enter grade point for " << subjectName << ": ";
        cin >> gradepoint;

        student.addSubject(subjectName, credit, gradepoint);
    }

    student.displayCGPA();

    return 0;
}
