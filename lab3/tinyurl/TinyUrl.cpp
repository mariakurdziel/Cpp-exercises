//
// Created by maria on 16.03.17.
//

#include "TinyUrl.h"

using namespace std;

struct TinyUrlCodec
{
    char tab[6];
    string version1;

}TinyUrlCodec;

unique_ptr<TinyUrlCodec> Init()
{
    unique_ptr<TinyUrlCodec> p = make_unique<TinyUrlCodec>();
    return p;
}

void NextHash(array<char, 6> *state) {
    int x = (int) (*state)[5];
    bool end = true;
    int k = 5;
    while (end==true)
    {
        if (x >= 97 && x < 122)
        {
            (*state)[k] = (char) (x + 1);
            end=false;
        }
        if (x >= 0 && x < 9)
        {
            (*state)[k] = (char) (x + 1);
            end=false;
        }
        if (x == 122)
        {
            (*state)[k] ='0';
            k--;
        }
        x = (int) (*state)[k];
    }
}
string Encode(const string &url, unique_ptr<TinyUrlCodec> *codec)
{
    string newurl;
    (*codec)->version1=url;
    NextHash(&((*codec)->tab[]));

    for(int i=0;i<6;i++)
        newurl+=(*codec)->tab[i];

    return newurl;

}

string Decode(const unique_ptr<TinyUrlCodec> &codec, const string &hash)
{
    string dec;

    dec=(*codec)->version1;

    return dec;
}