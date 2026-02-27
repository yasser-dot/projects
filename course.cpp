#include "course.h"
#include "student.h"
#include <iostream>
#include <limits>
using namespace std;

void addCourse(std::vector<Course>& courses) {
    Course c1;
    cout << "Enter course title: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, c1.title);

    cout << "Enter course ID: ";
    cin >> c1.id;

    cout << "Enter credit hours: ";
    cin >> c1.credit_hours;

    courses.push_back(c1);
    cout << "Course added successfully.\n";
}

Course* findCourseById(std::vector<Course>& courses, const std::string& id) {
    for (auto& c : courses) {
        if (c.id == id) return &c;
    }
    return nullptr;
}

// --------------------------------------------------------------------//

void recordGrade(std::vector<Course>& courses, std::vector<Student>& students) {
    cout << "Enter course ID and student ID: ";
    string Cid, Sid;
    cin >> Cid >> Sid;

    Student* s1 = findStudentById(students, Sid);
    if (!s1) {
        cout << "Student not found.\n";
        return;
    }

    Course* c1 = findCourseById(courses, Cid);
    if (!c1) {
        cout << "Course not found.\n";
        return;
    }

    double grade;
    cout << "Enter grade: ";
    cin >> grade;
    c1->grades.push_back({Sid, grade});
    cout << "Grade recorded successfully.\n";
}

// --------------------------------------------------------------------//

void printCourseReport(std::vector<Course>& courses, std::vector<Student>& students) {
    cout << "Enter course ID: ";
    string courseid;
    cin >> courseid;

    Course* c1 = findCourseById(courses, courseid);
    if (!c1) {
        cout << "Course not found.\n";
        return;
    }

    cout << "Course Report for " << c1->title << ":\n";
    for (auto& g : c1->grades) {

        Student* s1 = findStudentById(students, g.first);
        if (s1) {
            cout << s1->name << " (" << g.first << ") : " << g.second << endl;
        } else {
            cout << g.first << " " << g.second << endl;
        }
    }
}