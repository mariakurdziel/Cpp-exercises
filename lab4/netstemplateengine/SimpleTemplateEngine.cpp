//
// Created by maria on 25.03.17.
//
#include "SimpleTemplateEngine.h"

using std::string;
namespace nets
{
    string View::Render(const unordered_map <string,string> &model) const
    {
        string message2;
        string word;
        int k;
        for(int i=0; i<s1.size()-2;i++)
        {

            if (s1[i] == s1[i + 1] == '{') {
                k = i + 2;
                while (s1[k] != '}')
                {
                    word += s1[k];
                    k++;
                }
                for( const auto& n : model ) {
                    word+=n.second;
                }

                word = "";

            }
            else
            {
                if (s1[i] != '}')
                    message2 += s1[i];
            }
        }
            return message2;
    }
        View::View() {

        }

        View::View(const string message) {
            this->s1=message;
        }

        View::~View() {

        }



}