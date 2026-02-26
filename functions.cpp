#include <bits\stdc++.h>
#include "course.h"
#include "student.h"
using namespace std;

void addStudent(std::vector<Student>& students) {
   Student s1 ;
   cout << "Enter name: ";
   getline( cin,s1.name);
   cin.ignore();
   cout << "enter id: ";
   cin >> s1.id;
   cout << "enter academic year: ";
   cin>>s1.year;
   cout << "enter number of courses: ";
   cin >> s1.numcourses;
cout << "enter courses IDs: ";
   for (int i = 0; i < s1.numcourses;++i) {
      string idcourse;
      cin >> idcourse;
      s1.enrolledCourseIds.push_back(idcourse);
   }
   students.push_back(s1);
cout << "student added"<< endl;;
}
//+++++++++++++++++++++++++++++++++++++

Student* findStudentById(std::vector<Student>& students, const std::string& id) {
   for (int i = 0;i<students.size();++i) {
      if (id == students[i].id) {
         return &students[i];
      }
   }
   return nullptr;
}
//+++++++++++++++++++++++++++++++++++++

void addCourse(std::vector<Course>& courses) {
   Course c1;
   cout << "Enter name: ";
   getline( cin,c1.title);
   cin.ignore();
   cout << "enter id: ";
   cin >> c1.id;
   cout << "enter credit hours: ";
   cin >> c1.credit_hours;

   courses.push_back(c1);
   cout << "Course added"<< endl;
}
//+++++++++++++++++++++++++++++++++++++
Course* findCourseById(std::vector<Course>& courses, const std::string& courseid) {
   for (int i = 0; i < courses.size(); ++i) {
      if (courses[i].id == courseid) {
         return (&courses[i]);
      }
   }
   return nullptr;
}

//+++++++++++++++++++++++++++++++++++++
void recordGrade(std::vector<Course>& courses, std::vector<Student>& students) {
cout << "enter course id and your id: "<< endl;
   string Sid,Cid;
   cin >> Cid >> Sid;
   Student* s1 =findStudentById(students,Sid);
   if (s1==nullptr) {
      cout << "student not found";
      return;
   }
   Course* c1 = findCourseById(courses,Cid);
   if (c1==nullptr) {
      cout << "course not found";
      return;
   }
   double grade;
   cout << "enter grade: ";
   cin >> grade;
   c1->grades.push_back({Sid,grade});
   vector<double>grades;

cout << "grade added"<< endl;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++
void printStudentGPA(std::vector<Student>& students, std::vector<Course>&
courses) {

   cout << "enter your id: "<< endl;
   string Sid;
   cin >> Sid;
   Student* s1 =findStudentById(students,Sid);
   if (s1==nullptr) {
      cout << "student not found";
      return;
   }
   double sum=0,sumcredit=0;
float x = 0;
   for (int i =0;i<s1->numcourses;++i) {
      Course* c1= findCourseById(courses,s1->enrolledCourseIds[i]);
      for (int i = 0; i < c1->grades.size();++i) {
         if (c1->grades[i].first== Sid) {
if (c1->grades[i].second>= 90) {
   x = 4;
}
else if (c1->grades[i].second>= 85) {
   x = 3.7;
}
else if (c1->grades[i].second>= 80) {
               x = 3.3;
            }
else if (c1->grades[i].second>= 75) {
   x = 3;
}
else if (c1->grades[i].second>= 70) {
   x = 2.7;
}
else if (c1->grades[i].second>= 65) {
   x = 2.3;
}
else if (c1->grades[i].second>= 60) {
   x = 2;
}
else if (c1->grades[i].second>= 50) {
   x = 1;
}
else x = 0;
            sum+=(x*c1->credit_hours);
         }
      }
      sumcredit+=c1->credit_hours;
   }
cout << "gpa= " << sum/sumcredit;
}
//++++++++++++++++++++++++++++

void printCourseReport(std::vector<Course>& courses, std::vector<Student>&
students) {
   cout << "enter course id: ";
   string courseid;
   cin >> courseid;
   Course* c1= findCourseById(courses,courseid);
   if (c1 == nullptr) {
      cout << "unfound course";
      return;
   }
   for (int i = 0; i < c1->grades.size();++i) {
     cout<< c1->grades[i].first << ' ' << c1->grades[i].second << endl;
   }
}

int main() {


}



