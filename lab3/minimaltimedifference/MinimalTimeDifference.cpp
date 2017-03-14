//
// Created by mrozolga on 14.03.17.
//

#include "MinimalTimeDifference.h"

using namespace std;
namespace minimaltimedifference {
    unsigned int ToMinutes(string time_HH_MM) {
        regex pattern{R"((\d{1,2}):(\d{2}))"};
        int minutes = 0;
        string h, m;
        smatch matches;
        if (regex_match(time_HH_MM, matches, pattern)) {
            h = matches[1];
            m = matches[2];
        }
        int a = atoi(h.c_str());
        int b = atoi(m.c_str());
        minutes = 60 * a + b;
        return minutes;

    }

    unsigned int MinimalTimeDifference(vector<string> times) {
        int x, y;
        int mini = 10000000, d, e, f;
        for (int i = 0; i < times.size(); i++) {
            for (int j = 0; j < times.size(); j++) {
                if (i != j) {
                    x = ToMinutes(times[i]);
                    y = ToMinutes(times[j]);

                    d = min(abs(x - y), 24 * 60 - max(x, y) + min(x, y));


                    if (d < mini) mini = d;

                }
            }

        }
        return mini;
    }

}


