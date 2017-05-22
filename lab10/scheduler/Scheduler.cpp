//
// Created by olga on 19.05.17.
//

#include "Scheduler.h"

namespace academia
{
    SchedulingItem::SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year)
    {
        course_id_=course_id;
        teacher_id_=teacher_id;
        room_id_=room_id;
        time_slot_=time_slot;
        year_=year;
    }

    int SchedulingItem::CourseId() const
    {
        return course_id_;
    }
    int SchedulingItem::TeacherId() const
    {
        return teacher_id_;
    }
    int SchedulingItem::RoomId() const
    {
        return room_id_;
    }
    int SchedulingItem::TimeSlot() const
    {
        return time_slot_;
    }
    int SchedulingItem::Year() const
    {
        return year_;
    }
    SchedulingItem::~SchedulingItem(){}

    Schedule::Schedule(){}
    Schedule::~Schedule(){}

    void Schedule::InsertScheduleItem(const SchedulingItem &item)
    {
        schedule_vec.push_back(item);
    }


    SchedulingItem Schedule::operator[](int x) const
    {
        return schedule_vec[x];
    }

    size_t Schedule::Size() const
    {

        return schedule_vec.size();
    }


    Schedule Schedule::OfTeacher(int teacher_id) const
    {
        Schedule teacher_;
        copy_if(schedule_vec.begin(),schedule_vec.end(),back_inserter(teacher_.schedule_vec),[teacher_id](SchedulingItem id){return (id.TeacherId()==teacher_id);} );
        return teacher_;
    }

    Schedule Schedule::OfYear(int year) const
    {
        Schedule year_;
        copy_if(schedule_vec.begin(),schedule_vec.end(),back_inserter(year_.schedule_vec),[year](SchedulingItem y){return (y.Year()==year);} );
        return year_;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule room_;
        copy_if(schedule_vec.begin(),schedule_vec.end(),back_inserter(room_.schedule_vec),[room_id](SchedulingItem r){return (r.RoomId()==room_id);} );
        return room_;
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const
    {
        vector <int> t_slots1;
        vector <int> t_slots2;
        vector <int> final_vec;

        for(int i=1;i<=n_time_slots;i++)
            t_slots1.emplace_back(i);

        transform(schedule_vec.begin(), schedule_vec.end(), back_inserter(t_slots2), [](SchedulingItem t){return (t.TimeSlot());});
        std::set_difference(t_slots1.begin(), t_slots1.end(), t_slots2.begin(), t_slots2.end(), std::inserter(final_vec, final_vec.begin()));

        return final_vec;
    }




    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year,int n_time_slots)
    {
        int teacher_=0;
        int course_=0;
        int size=0;
        int year_=0;
        int room_=0;
        int r_iter=0;
        int s_iter=1;
        int counter=0;
        int time_slot=0;
        auto iter1=teacher_courses_assignment.begin();
        auto iter2=courses_of_year.begin();
        Schedule new_schedule;
        int p_course_=0;
        int p_room=0;
        for(iter1; iter1!=teacher_courses_assignment.end();iter1++)
        {
            teacher_=iter1->first;
            size=iter1->second.size();

            for(int i=0; i<size;i++)
            {
                course_ = iter1->second[i];
                auto iter2=courses_of_year.begin();

                for(iter2;iter2!=courses_of_year.end();iter2++)
                {
                    auto it=iter2->second.begin();
                    for (it; it!= iter2->second.end(); it++)
                    {
                        if (*it == course_)
                            year_ = iter2->first;
                    }
                }
                room_ = rooms[r_iter];
                time_slot = s_iter;

                if (s_iter==n_time_slots)
                {
                    s_iter = 0;
                    r_iter++;
                }


                new_schedule.InsertScheduleItem({course_, teacher_, room_, time_slot, year_});

                if(room_!=p_room && p_course_==course_)
                    throw NoViableSolutionFound();

                p_course_=course_;
                p_room=room_;
                s_iter++;

            }

        }



        auto iter=teacher_courses_assignment.begin();
        for(iter; iter!=teacher_courses_assignment.end();iter++)
        {
            counter+=iter->second.size();
        }

        if(rooms.size()*n_time_slots<counter)
            throw NoViableSolutionFound();

        return new_schedule;
    }
    NoViableSolutionFound::NoViableSolutionFound() {}
    NoViableSolutionFound::~NoViableSolutionFound(){}


}