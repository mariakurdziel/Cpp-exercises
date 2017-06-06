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
#include <string>
namespace nets {
    using namespace std;

    class JsonValue {
    public:
        JsonValue(int numberc);

        JsonValue(double numberz);

        JsonValue(std::string word);

        JsonValue(bool value);

        JsonValue(vector<JsonValue> v);

        JsonValue(map<string, JsonValue> obj);

        ~JsonValue();

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;

        std::string ToString() const;

    private:
        int number1;
        double number2;
        string word;
        bool val;
        vector<JsonValue> tab;
        map<string, JsonValue> object;
        char type;
    };
}
#endif //JIMP_EXERCISES_SIMPLEJSON_H
