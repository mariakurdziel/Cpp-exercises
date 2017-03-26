//
// Created by maria on 25.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>
#include <iostream>
#include <regex>

namespace nets
{
#include <unordered_map>
#include <string>
 using namespace std;


    class View
    {
    public:
        View();

        View(const string message);

        ~View();

        string Render(const unordered_map <string,string> &model) const;

    private:
        string s1;

    };
}

#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
