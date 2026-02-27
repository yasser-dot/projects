#include "student.h"
#include "course.h"
#include <iostream>
#include <limits>

using namespace std;

void addStudent(std::vector<Student>& students) {
    Student s1;

    cout << "Enter name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s1.name);

    cout << "Enter ID: ";
    cin >> s1.id;

    cout << "Enter academic year: ";
    cin >> s1.year;

    cout << "Enter number of courses: ";
    cin >> s1.numcourses;

    cout << "Enter course IDs: ";
    for (int i = 0; i < s1.numcourses; ++i) {
        string idcourse;
        cin >> idcourse;
        s1.enrolledCourseIds.push_back(idcourse);
    }

    students.push_back(s1);
    cout << "Student added successfully.\n";
}


////////////////////////////////////////////////////////////////////


Student* findStudentById(std::vector<Student>& students, const std::string& id) {
    for (auto& s : students) {
        if (s.id == id) return &s;
    }
    return nullptr;
}

// --------------------------------------------------------------------//

void printStudentGPA(std::vector<Student>& students, std::vector<Course>& courses) {
    cout << "Enter student ID: ";
    string Sid;
    cin >> Sid;
    Student* s1 = findStudentById(students, Sid);
    if (!s1) {
        cout << "Student not found.\n";
        return;
    }

    // --------------------------------------------------------------------//

    double sum = 0, sumcredit = 0;
    for (auto& cid : s1->enrolledCourseIds) {
        Course* c1 = findCourseById(courses, cid);
        if (!c1) continue;

        for (auto& g : c1->grades) {
            if (g.first == Sid) {
                double x;
                if (g.second >= 90) x = 4;
                else if (g.second >= 85) x = 3.7;
                else if (g.second >= 80) x = 3.3;
                else if (g.second >= 75) x = 3;
                else if (g.second >= 70) x = 2.7;
                else if (g.second >= 65) x = 2.3;
                else if (g.second >= 60) x = 2;
                else if (g.second >= 50) x = 1;
                else x = 0;
                sum += x * c1->credit_hours;
                sumcredit += c1->credit_hours;
            }
        }
    }
    if (sumcredit == 0) cout << "No grades found.\n";
    else cout << "GPA = " << sum / sumcredit << endl;
}