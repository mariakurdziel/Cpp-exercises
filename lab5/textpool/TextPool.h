//
// Created by maria on 02.04.17.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <vector>
#include <experimental/string_view>
#include <set>
#include <iostream>

using namespace std;
namespace pool
{

    class TextPool
    {
    public:
        std::set<std::experimental::string_view> list;
        TextPool();
        TextPool(TextPool &&newlist);
        TextPool &operator=(TextPool &&newlist);
        TextPool(std::initializer_list<std::experimental::string_view>list1):list(list1){};
        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;
        ~TextPool();

    };
}


#endif //JIMP_EXERCISES_TEXTPOOL_H
