//
// Created by maria on 27.03.17.
//

#include "SimpleJson.h"


namespace nets
{
    JsonValue::JsonValue(const string name)
    {
        word=name;
        type='s';
    }


    JsonValue::JsonValue(int numberc) {
        number1=numberc;
        type='c';
    }

    JsonValue::JsonValue(double numberz) {
        number2=numberz;
        type='z';
    }

    JsonValue::JsonValue(bool value) {
        val=value;
        type='b';

    }

    JsonValue::JsonValue(vector<JsonValue> v)
    {
      tab=v;
      type='v';
    }

    JsonValue::JsonValue(map<string, JsonValue> obj)
    {
     object=obj;
     type='m';
    }

    JsonValue::~JsonValue()
    {}


    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const
    {

        return experimental::optional<JsonValue>();
    }

    std::string JsonValue::ToString() const {

        string string1;

        if(type=='s')
        {

            return string1;
        }

        if(type=='c')
            return to_string(number1);
        if(type=='z')
            return to_string(number2);
        if(type=='b')
        {
            if (val==1)
                return "true";
            else
                return "false";
        }

    }


}