//
// Created by maria on 07.04.17.
//

#include "Student.h"

#include <iomanip>
using namespace std;
using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using ::std::istream;
using ::std::ws;

    Student::Student(string stid)
    {
        id=stid;
    }
    Student::Student(string stfirst_name)
    {
        first_name=stfirst_name;
    }
    Student::Student(string stlast_name)
    {
        last_name=stlast_name;
    }

    Student::Student(string stprogram)
    {
        program=stprogram;
    }

    Student::Student (StudyYear styear)
    {
        year=styear;
    }

    Student::~Student() {

    }

    string Student::GetId(string id)
    {
        return id;
    };

    string Student::GetFirstName(string first_name)
    {
        return first_name;
    }

    string Student::GetLastName(string last_name)
    {
        return last_name;
    }

    string Student::GetProgram(string program)
    {
        return program;
    }

    string Student::GetYear(StudyYear year)
    {
        string x=to_string(year);
        return year;
    }

istream& operator>>(istream & input, Student& s){
    CheckNextChar('{', &input);
    CheckNextChar('id: ', &input);
    s.GetId(&input);
    CheckNextChar('', &input);

    IgnoreWhitespace(&input);
    p.SetY(ReadNumber(&input));
    CheckNextChar(')', &input);
    return input;      // Umożliwia cin >> a >> b >> c;
}
{id: „2030001234”, first_name: „Arkadiusz”, last_name: „Kowalski”, program: „informatyka”, year: 2}