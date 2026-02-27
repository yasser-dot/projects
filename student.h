#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct Student {
    std::string id;
    std::string name;
    int year;
    int numcourses;
    std::vector<std::string> enrolledCourseIds;
};

//------------------------------ FUNCTIONS ----------------------------------------//

void addStudent(std::vector<Student>& students);
Student* findStudentById(std::vector<Student>& students, const std::string& id);
void printStudentGPA(std::vector<Student>& students, std::vector<class Course>& courses);

#endif