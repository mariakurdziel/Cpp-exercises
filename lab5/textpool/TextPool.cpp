//
// Created by maria on 02.04.17.
//

#include "TextPool.h"

namespace pool
{


    TextPool::TextPool(){
    };


    TextPool::TextPool(TextPool &&newlist)
    {
        list={};
        swap(list,newlist.list);
    }

    TextPool & TextPool::operator=(TextPool &&newlist) {
        if (this == &newlist) {
            return newlist;
        }
        list={};
        swap(list,newlist.list);
    }

    std::experimental::string_view TextPool::Intern(const std::string &str)
    {
        auto result = list.find(str);
        if( result!=list.end())
            return std::experimental::string_view(str);
        else
        {
            list.insert(std::experimental::string_view(str));
            return std::experimental::string_view(str);
        }
    }

    size_t TextPool::StoredStringCount() const
    {
        size_t counter=0;

        for(auto it=list.begin(); it!=list.end(); ++it)
            counter++;

        return counter;
    }

    TextPool::~TextPool() {

    }

}