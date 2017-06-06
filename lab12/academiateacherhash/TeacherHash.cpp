//
// Created by maria on 03.06.17.
//

#include "TeacherHash.h"

namespace academia
{
    TeacherId::TeacherId(){}
    TeacherId::TeacherId(int id)
    {
        id_=id;
    }
    TeacherId::~TeacherId(){}
    int TeacherId::GetId() const
    {
        return id_;
    }

    bool TeacherId::operator==(const TeacherId &id) const
    {
        return id_==id.id_;
    }

    bool TeacherId::operator!=(const TeacherId &id) const
    {
        return id_!=id.id_;
    }

    Teacher::Teacher(TeacherId id, string name, string department)
    {
        name_=name;
        department_=department;
        id_=id;
    }
    Teacher::~Teacher(){}

    string Teacher::Department() const
    {
        return department_;
    }
    string Teacher::Name() const
    {
        return name_;
    }
    TeacherId Teacher::Id() const
    {
        return id_;
    }

    bool Teacher::operator==(const Teacher &teacher) const
    {
        return id_.GetId()==teacher.Id().GetId() || name_ == teacher.Name() || department_ == teacher.Department();
    }

    bool Teacher::operator!=(const Teacher &teacher) const
    {
        return id_.GetId()!=teacher.Id().GetId() || name_ != teacher.Name() || department_ != teacher.Department();
    }

    TeacherHash::TeacherHash(){}
    TeacherHash::~TeacherHash(){}

}