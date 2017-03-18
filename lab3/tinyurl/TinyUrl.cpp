//
// Created by lenovo on 2017-03-16.
//


#include "TinyUrl.h"


namespace tinyurl
{
    struct TinyUrlCodec
    {
        array<char, 6> *state;

    };

    unique_ptr<TinyUrlCodec> Init()
    {
        unique_ptr<TinyUrlCodec> p = make_unique<TinyUrlCodec>();
        return p;
    }
    void NextHash(array<char, 6> *state)
    {
        for (int i=6; i>=0; i--)
        {
            int a=(int)(*state)[i];
            if (a==57)
            {
                a=65;
                (*state)[i]=(char)a;
                break;
            }
            else if(a==90)
            {
                a=97;
                (*state)[i]=(char)a;
                break;
            }
            else if (a==122) {

                a = 48;
                (*state)[i]=(char)a;
                break;
            }
            else
            {
                a++;
                (*state)[i]=(char)a;
                break;
            }

        }

    cout<<state;
    }}


