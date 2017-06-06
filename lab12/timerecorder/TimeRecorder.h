//
// Created by maria on 06.06.17.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H
#include <iostream>
#include <string>
#include <chrono>
#include <utility>

namespace profiling
{

    template<typename T>
    auto TimeRecorder(T a);

    template<typename T>
    auto TimeRecorder(T a) {
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
        //C object = arg();
        auto object = (a)();
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        return std::make_pair( object, elapsed_seconds.count()*1000) ;
    }

}


#endif //JIMP_EXERCISES_TIMERECORDER_H
