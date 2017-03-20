//
// Created by maria on 16.03.17.
//

#include "TinyUrl.h"

using namespace std;
using namespace tinyurl;


    int main() {

        auto codec =Init();
        string url;
        string bla;
        string newurl;
        string decode;

        cout << "Podaj 6-znakowy adres URL:" << endl;
        cin >> url;
        newurl = Encode(url, &codec);
        cout<<"Nowy URL: "<<newurl;
        decode = Decode(codec,newurl);
        cout<<endl;
        cout<<"Stary URL: "<<decode<<endl;


        return 0;

    }
