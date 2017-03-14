//
// Created by mrozolga on 14.03.17.
//

#ifndef JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
#define JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H

#include <regex>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;
namespace minimaltimedifference {
    unsigned int ToMinutes(string time_HH_MM);

    unsigned int MinimalTimeDifference(std::vector<std::string> times);
}


#endif //JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
