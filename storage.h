#ifndef STORAGE_H
#define STORAGE_H

#include <string>
#include <vector>
#include "student.h"
#include "course.h"

// --------------------------------------------------------------------//

void saveDatabase(const std::vector<Student>& students, const std::vector<Course>& courses, const std::string& filename);
void loadDatabase(std::vector<Student>& students, std::vector<Course>& courses, const std::string& filename);
void exportCourseCSV(Course* course, std::vector<Student>& students);

#endif