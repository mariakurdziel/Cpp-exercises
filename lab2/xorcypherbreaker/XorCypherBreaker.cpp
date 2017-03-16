//
// Created by maria on 13.03.17.
//

#include "XorCypherBreaker.h"

using namespace std;

string XorCypherBreaker(const vector<char> &cryptogram,int key_length, const vector <string> &dictionary) {
    vector<char> key;
    string word;
    vector<string> message;
    int n = 0;
    int m= 0;
    char x;
    int max = 0;
    string decode;


    for (int i = 97; i <= 122; i++)
        for (int j = 97; j <= 122; j++)
            for (int k = 97; k <= 122; k++)
            {
                key.push_back(char(i));
                key.push_back(char(j));
                key.push_back(char(k));

                for (int l = 0; l < cryptogram.size(); l++)
                {
                    if (n < 3)
                    {
                        if ((key[n] ^ cryptogram[l])>= 97 && (key[n] ^ cryptogram[l]) <= 122)
                        {
                            x =key[n] ^ cryptogram[l];
                            word += x;
                            n++;
                        }

                        if ((key[n] ^ cryptogram[l])>= 65 && (key[n] ^ cryptogram[l]) <= 90)
                        {
                            x =key[n] ^ cryptogram[l];
                            word += x;
                            n++;
                        }
                       if((key[n] ^ cryptogram[l])<65 || (key[n] ^ cryptogram[l]) >90 && (key[n] ^ cryptogram[l])<97 || (key[n] ^ cryptogram[l])>122)
                        {
                            message.emplace_back(word);
                            word = "";
                        }

                    }
                    if (n == 3)
                        n = 0;
                }

                message.emplace_back(word);
                word = "";

    for (int i = 0; i < dictionary.size(); i++)
    {
        if (find(message.begin(), message.end(), dictionary[i]) != message.end())
            m++;
    }
     if (m > max)
     {
         max = m;
         decode = "";
         for (int i =0; i<key.size(); i++)
             decode +=key[i];
     }

    key.clear();
    message.clear();
    m=0;
    n=0;
  }

    return decode;
}
