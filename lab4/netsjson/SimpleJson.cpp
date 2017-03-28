//
// Created by maria on 27.03.17.
//


#include "SimpleJson.h"

namespace nets
{
    JsonValue::JsonValue(const int x) : obj(to_string(x)) {}
    JsonValue::JsonValue(const double x) {
        stringstream stream;
        stream << x;
        obj = stream.str();
    }
    JsonValue::JsonValue(const bool x) {
        obj = (x ? "true" : "false");
    }
    JsonValue::JsonValue(const std::string &name) {
        string str = name;
        obj += "\"";
        replace_substr(str, "\\", "\\\\");
        replace_substr(str, "\"", "\\\"");
        obj += str;
        obj += "\"";
    }

    void JsonValue::replace_substr(string &str, const string &pattern1, const string &pattern2) const
    {
        size_t index = 0;
        while (true) {
            index = str.find(pattern1, index);
            if (index == string::npos)
                break;

            str.replace(index, pattern1.length(), pattern2);
            index += pattern2.length();
        }
    }

    JsonValue::JsonValue(const std::vector<JsonValue> &array)
    {
        obj += "[";
        obj += array[0].ToString();
        for (auto i = array.begin() + 1; i < array.end(); ++i)
        {
            obj += ", ";
            obj += (*i).ToString();
        }
        obj += "]";
    }

    JsonValue::~JsonValue()
    {

    }

    JsonValue::JsonValue(const map<string, JsonValue> &map1)
    {
        obj += "{";
        auto el = (*map1.begin());
        obj += JsonValue(el.first).ToString() + ": ";
        obj += el.second.ToString();

        for (auto i = next(map1.begin()); i != map1.end(); ++i)
        {
            obj += ", ";
            obj += JsonValue((*i).first).ToString() + ": ";
            obj += (*i).second.ToString();
        }
        obj += "}";
    }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const
    {
        return std::experimental::optional<JsonValue>();
    }

    std::string JsonValue::ToString() const { return obj; }
}