//
// Created by maria on 07.04.17.
//

#ifndef JIMP_EXERCISES_STUDENT_H
#define JIMP_EXERCISES_STUDENT_H

#include <iostream>
#include <string>
#include <ostream>
using namespace std;
class StudyYear
{
    public:
        StudyYear(int x);
        int Year(int year);
        ~StudyYear();
    private:
        int year=x;

};

class Student {
    public:
        Student(string stid);
        Student(string stfirst_name);
        Student(string stlast_name);
        Student(string stprogram);
        Student(StudyYear styear);
        string GetId(string id);
        string GetFirstName(string first_name);
        string GetLastName(string last_name);
        string GetProgram(string last_name);
        string GetYear(StudyYear year);
        ~Student();
    private:
        string id,first_name,last_name,program;
        StudyYear year;
};

int &operator++(StudyYear year);
int operator++(StudyYear year);
std::istream& operator>>(std::istream &is, Student &student);
std::ostream& operator<<(std::ostream &is,Student &student);
#endif //JIMP_EXERCISES_STUDENT_H
