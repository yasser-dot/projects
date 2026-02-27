#include <iostream>
#include <vector>
#include "student.h"
#include "course.h"
#include "utils.h"
#include "storage.h"

using namespace std;

void showMenu() {
    cout << "\n---------- Student Grades & Course Management System ----------\n";
    cout << "1. Add Student\n";
    cout << "2. Add Course\n";
    cout << "3. Record Grade\n";
    cout << "4. Print Student GPA\n";
    cout << "5. Print Course Report\n";
    cout << "6. Save Database\n";
    cout << "7. Load Database\n";
    cout << "8. Export Course CSV\n";
    cout << "0. Exit Program\n";
    cout << "------------------------------------------------\n";
}

int main() {
    vector<Student> students;
    vector<Course> courses;

    while (true) {
        showMenu();
        int choice = getIntInput("Enter your choice: ");

        switch (choice) {
            case 1: addStudent(students); break;
            case 2: addCourse(courses); break;
            case 3: recordGrade(courses, students); break;
            case 4: printStudentGPA(students, courses); break;
            case 5: printCourseReport(courses, students); break;
            case 6: {
                string filename = getStringInput("Enter filename to save: ");
                saveDatabase(students, courses, filename);
                cout << "Database saved successfully.\n";
                break;
            }
            case 7: {
                string filename = getStringInput("Enter filename to load: ");
                loadDatabase(students, courses, filename);
                cout << "Database loaded successfully.\n";
                break;
            }
            case 8: {
                string courseId = getStringInput("Enter course ID to export: ");
                Course* c = findCourseById(courses, courseId);
                if (c) {
                    exportCourseCSV(c, students);
                    cout << "Course exported to CSV.\n";
                } else cout << "Course not found.\n";
                break;
            }

            case 0:
                saveDatabase(students, courses, "database.txt");
                cout << "Database saved. Exiting program...\n";
                return 0;


            default: cout << "Invalid choice. Please try again.\n";
        }
    }
}