//
// Created by maria on 13.03.17.
//

#include "XorCypherBreaker.h"

using namespace std;

string XorCypherBreaker(const vector<char> &cryptogram,int key_length, const vector <string> &dictionary) {
    vector<int> key;
    string word;
    vector<string> message;
    int n = 0;
    int m= 0;
    char x;
    int max = 0;
    string decode;


    for (int i = 97; i <= 122; i++)
    {
        for (int j = 97; j <= 122; j++)
        {
            for (int k = 97; k <= 122; k++)
            {
                key.emplace_back(i);
                key.emplace_back(j);
                key.emplace_back(k);


                for (int l = 0; l < cryptogram.size(); l++)
                {
                    if (n < 3)
                    {
                        if ((key[n]^(int)cryptogram[l])>= 97 && (key[n]^(int)cryptogram[l]) <= 122)
                        {
                            x =char (key[n] ^ (int)cryptogram[l]);
                            word += x;
                            n++;
                        }
                        if ((key[n]^(int)cryptogram[l])>= 65 && (key[n]^(int)cryptogram[l]) <= 90)
                        {
                            x =char (key[n] ^ (int)cryptogram[l]);
                            word += x;
                            n++;
                        }
                        else
                        {
                            message.emplace_back(word);
                            word = "";
                        }

                    }
                    if (n == 3)
                        n = 0;
                }


    for (int i = 0; i < dictionary.size(); i++)
    {
        if (find(message.begin(), message.end(), dictionary[i]) != message.end())
            m++;
    }
     if (m > max)
     {
         max = m;
         decode = "";
         for (int i = 0; i < key.size(); i++)
             decode += char(key[i]);
     }

    key.clear();
    message.clear();
    word="";
    m=0;
    n=0;
  }
 }
}
    return decode;
}
