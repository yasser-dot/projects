#include "storage.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

void saveDatabase(const std::vector<Student>& students, const std::vector<Course>& courses, const std::string& filename) {
    std::ofstream out(filename);
    if (!out) throw std::runtime_error("Could not open file for saving.");

    out << students.size() << "\n";
    for (auto& s : students) {
        out << s.id << "\n" << s.name << "\n" << s.year << "\n" << s.numcourses << "\n";
        for (auto& cid : s.enrolledCourseIds) out << cid << "\n";
    }


    out << courses.size() << "\n";
    for (auto& c : courses) {
        out << c.id << "\n" << c.title << "\n" << c.credit_hours << "\n" << c.grades.size() << "\n";
        for (auto& g : c.grades) out << g.first << " " << g.second << "\n";
    }
}

// --------------------------------------------------------------------//

void loadDatabase(std::vector<Student>& students, std::vector<Course>& courses, const std::string& filename) {
    std::ifstream in(filename);
    if (!in) throw std::runtime_error("Could not open file for loading.");


    int totalStudents;
    in >> totalStudents;
    in.ignore();
    students.clear();
    for (int i = 0; i < totalStudents; ++i) {
        Student s;
        std::getline(in, s.id);
        std::getline(in, s.name);
        in >> s.year >> s.numcourses;
        in.ignore();
        for (int j = 0; j < s.numcourses; ++j) {
            std::string cid;
            std::getline(in, cid);
            s.enrolledCourseIds.push_back(cid);
        }
        students.push_back(s);
    }


    int totalCourses;
    in >> totalCourses;
    in.ignore();
    courses.clear();
    for (int i = 0; i < totalCourses; ++i) {
        Course c;
        std::getline(in, c.id);
        std::getline(in, c.title);
        in >> c.credit_hours;
        in.ignore();

        int gradeCount;
        in >> gradeCount;
        in.ignore();
        for (int j = 0; j < gradeCount; ++j) {
            std::string sid;
            double grade;
            in >> sid >> grade;
            in.ignore();
            c.grades.push_back({sid, grade});
        }

        courses.push_back(c);
    }

    std::cout << "Database added successfully.\n";
}

// --------------------------------------------------------------------//

void exportCourseCSV(Course* course, std::vector<Student>& students) {
    if (!course) return;
    std::ofstream out(course->id + ".csv");
    out << "StudentID,Grade\n";
    for (auto& g : course->grades) {
        out << g.first << "," << g.second << "\n";
    }
}