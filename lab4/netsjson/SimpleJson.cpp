//
// Created by maria on 27.03.17.
//

#include "SimpleJson.h"


namespace nets
{
    JsonValue::JsonValue(const string name)
    {
        word=name;
    }


    JsonValue::JsonValue(int numberc) {
        number1=numberc;

    }

    JsonValue::JsonValue(double numberz) {
        number2=numberz;

    }

    JsonValue::JsonValue(bool value) {
        val=value;

    }

    JsonValue::JsonValue(vector<JsonValue> v)
    {
      tab=v;
    }

    JsonValue::JsonValue(map<string, JsonValue> obj)
    {
     object=obj;
    }

    JsonValue::~JsonValue()
    {}


    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const
    {
        return experimental::optional<JsonValue>();
    }

    std::string JsonValue::ToString() const {
        return std::__cxx11::string();
    }


}