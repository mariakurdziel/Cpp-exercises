//
// Created by maria on 16.03.17.
//

#include "TinyUrl.h"

using namespace std;

namespace tinyurl {


    unique_ptr<struct TinyUrlCodec> Init()
    {
        return make_unique<struct TinyUrlCodec>();
    }

    void NextHash(array<char, 6> *state)
    {
        int x = (int) (*state)[5];
        bool end = false;
        int k = 5;
        while (end == false) {
            if (k == 0)
                end = true;

            if (x >= 97 && x < 122) {
                (*state)[k] = (char) (x + 1);
                end = true;
            }
            if (x >= 48 && x < 57) {
                (*state)[k] = (char) (x + 1);
                end = true;
            }
            if (x >= 65 && x < 90) {
                (*state)[k] = (char) (x + 1);
                end = true;
            }
            if (x == 57) {
                (*state)[k] = 'A';
                end = true;
            }
            if (x == 90) {
                (*state)[k] = 'a';
                end = true;
            }
            if (x == 122) {
                (*state)[k] = '0';
                k--;
            }
            x
            x = (int) (*state)[k];
        }
    }

    string Encode(const string &url, unique_ptr<struct TinyUrlCodec> *codec)
    {
        string newurl;

        for(int i=0; i<6;i++)
            (*codec)->tab[i]=url[i];

        NextHash(&(*codec)->tab);

        for (int i = 0; i < 6; i++)
            newurl += (*codec)->tab[i];

        (*codec)->url_map[newurl] = url;
        (*codec)->url_map["000000"]="000000";

        return newurl;

    }

    string Decode(const unique_ptr<struct TinyUrlCodec> &codec, const string &hash)
    {
        string decode;
        map <string,string>::iterator pos;
        pos=(*codec).url_map.end();

        map<string, string>::iterator prev = pos;

        prev--;

        decode=prev->second;
        (*codec).url_map.erase ("000000");

           return decode;

    }
}