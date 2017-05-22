//
// Created by olga on 19.05.17.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

namespace academia
{
    class SchedulingItem
    {
    public:
        SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year);
        int CourseId() const;
        int TeacherId() const;
        int RoomId() const;
        int TimeSlot() const;
        int Year() const;

        ~SchedulingItem();
    private:
        int course_id_;
        int teacher_id_;
        int room_id_;
        int time_slot_;
        int year_;

    };

    class Schedule
    {
    public:
        Schedule();
        ~Schedule();
        Schedule(initializer_list <SchedulingItem> &vec):schedule_vec(vec){};
        void InsertScheduleItem(const SchedulingItem &item);
        size_t Size() const;
        SchedulingItem operator[](int x) const;
        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots)const;

    private:
        vector <SchedulingItem> schedule_vec;

    };

    class Scheduler
    {
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year,int n_time_slots)=0;
    };

    class GreedyScheduler: public Scheduler
    {
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year,int n_time_slots);

    };

    class NoViableSolutionFound
    {
    public:
        NoViableSolutionFound();
        ~NoViableSolutionFound();
    };
}


#endif //JIMP_EXERCISES_SCHEDULER_H
