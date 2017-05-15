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

    JsonValue::~JsonValue() {
    }


    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const
    {

        return experimental::optional<JsonValue>();
    }

    std::string JsonValue::ToString() const {

        string string1;
        string tmp;
        int i=0;

        if(type=='s')
        {
            return "";
        }

        if(type=='c')
        {
            string1=to_string(number1);
            return string1;
        }
        if(type=='z')
        {
            tmp=to_string(number2);

            while(tmp[i]!='.')
            {
                string1+=tmp[i];
                i++;
            }
            string1+='.';
            i++;
            string1+=tmp[i];
            string1+=tmp[i+1];
            return string1;
        }
        if(type=='b')
        {
            if (val==1)
                return "true";
            else
                return "false";
        }
        if(type=='v')
        {
            string1+='[';
            for(int i=0;i<tab.size();i++)
            {
                string1+=tab[i].ToString();
                string1+=", ";
            }
            string1.erase(string1.size()-2,string1.size()-1);
            string1+="]";
            return string1;
        }
        if(type=='m')
        {
            string1+='{';

            auto it=object.begin();
            for (it; it != object.end(); it++)
            {
                string1+=JsonValue(it.first)->To_String();
                string1+=": ";
                string1+=JsonValue(it.second)->To_String();
                string1+=", ";
                //How do I access each element without knowing any of its string-int values?
            }
            string1.erase(string1.size()-2,string1.size()-1);
            string1+='}';
            return string1;
        }

    }


}
