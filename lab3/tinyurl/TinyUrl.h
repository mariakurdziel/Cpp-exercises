//
// Created by lenovo on 2017-03-16.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H
#include <iostream>
#include <string>
#include <utility>
#include <string>
#include <array>
#include <memory>
#include <algorithm>

using namespace std;
namespace tinyurl {

    struct TinyUrlCodec;
    unique_ptr<TinyUrlCodec> Init();
    void NextHash(array<char, 6> *state);

    string Encode(const string &url, unique_ptr<string> *codec);

    string Decode(const unique_ptr<string> &codec, const string &hash);
}



#endif //JIMP_EXERCISES_TINYURL_H
