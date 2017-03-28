//
// Created by maria on 27.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H


#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <experimental/optional>
#include <sstream>
namespace nets
{
    using namespace std;

    class JsonValue
    {
        string obj;
    public:
        JsonValue(const int x);
        JsonValue(const double x);
        JsonValue(const bool x);
        JsonValue(const std::string &name);
        JsonValue(const std::vector<JsonValue> &array);
        JsonValue(const std::map<std::string, JsonValue> &map1);

        ~JsonValue();

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;

        void replace_substr(string &str, const string &pattern1, const string &pattern2) const;
    };

}

#endif //JIMP_EXERCISES_SIMPLEJSON_H


