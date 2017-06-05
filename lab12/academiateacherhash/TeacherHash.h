//
// Created by maria on 03.06.17.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <iostream>

using namespace std;

namespace academia
{

    class TeacherId
    {
    public:
        TeacherId();
        TeacherId(int id);
        ~TeacherId();
        int GetId() const;
        operator int()const {
            return id_;
        }
        bool operator==(const TeacherId &id) const;
        bool operator!=(const TeacherId &id) const;

    private:
        int id_;
    };


    class Teacher
    {
    public:
        Teacher(TeacherId id, string name, string department);
        string Department() const;
        string Name() const;
        TeacherId Id() const;
        ~Teacher();
        bool operator==(const Teacher &teacher)const;
        bool operator!=(const Teacher &teacher)const;

    private:
        string department_;
        string name_;
        TeacherId id_;


    };

    class TeacherHash
    {
    public:
        TeacherHash();
        ~TeacherHash();
        size_t operator()(const Teacher &t) const {
            int h_id=t.Id().GetId();
            size_t id_h = hash<int> ()(h_id);
            size_t name_h = hash<string>()(t.Name());
            size_t department_h = hash<string>()(t.Department());

            return id_h * name_h + department_h;
        }

    };
}

#endif //JIMP_EXERCISES_TEACHERHASH_H
