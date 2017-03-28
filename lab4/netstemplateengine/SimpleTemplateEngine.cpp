//
// Created by maria on 27.03.17.
//

#include "SimpleTemplateEngine.h"

namespace nets
{
    View::View(string message)
    {
        s1=message;
    }

    View::~View() {

    }

    string View::Render(const unordered_map <string,string> &model) const
    {
        string message2;
        string word;
        int licz=0;
        int n=0;
        int s;
        while(n<s1.size())
        {
            while (s1[n] != '{')
            {
                if (n >= s1.size())
                    break;

                message2 += s1[n];
                n++;

            }

            if (s1[n] == '{' && s1[n + 1] == '{' && s1[n+2]!='{')
            {
                s=n;

                while(s1[s]!='}')
                    s++;
                while(s1[s]=='}')
                {
                    s++;
                    licz++;
                }
                if(licz==2) {
                    n = n + 2;

                    while (s1[n] != '}')
                    {
                        word += s1[n];
                        n++;
                    }
                    for (const auto &m : model)
                    {
                        if (m.first == word)
                        {
                            message2 += m.second;
                        }

                    }

                    n = n + 2;
                    word = "";
                }
                if(licz==1)
                {
                    while(s1[n]!='}')
                    {
                        if (n >= s1.size())
                            break;

                        message2 += s1[n];
                        n++;
                    }
                    message2+='}';
                    n++;
                }
                licz=0;
            }
            if(s1[n]=='{'&& s1[n+1]!='{')
            {
                while(s1[n]!='}')
                {
                    if (n >= s1.size())
                        break;

                    message2 += s1[n];
                    n++;
                }
                message2+='}';
                n++;
            }
            if(s1[n]=='{'&& s1[n+1]=='{' && s1[n+1]=='{')
            {
                message2+='{';
                n=n+3;


                while (s1[n] != '}') {
                    word += s1[n];
                    n++;
                }
                for (const auto &m : model) {
                    if (m.first == word) {
                        message2 += m.second;
                    }

                }
                message2+='}';
                n = n + 3;
                word = "";

            }
        }


        return message2;
    }




}