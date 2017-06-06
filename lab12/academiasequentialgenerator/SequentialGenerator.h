//
// Created by maria on 05.06.17.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

#include <iostream>
using namespace std;

template<class Id, class Y>
class SequentialIdGenerator
{
    public:

        SequentialIdGenerator(const Y &counter =Y()) {
           counter_=counter;
        }
        ~SequentialIdGenerator(){}
        Id NextValue();


    private:
        Y counter_;

};

template<class Id, class Y>
Id SequentialIdGenerator<Id,Y>::NextValue()
{
    Id new_=Id(counter_);
    ++counter_;
    return new_;

}




#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
