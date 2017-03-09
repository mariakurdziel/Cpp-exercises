//
// Created by maria on 05.03.17.
//

#include "Palindrome.h"

using namespace std;

bool is_palindrome(string word)
{
    bool pal;
    int m=0;

    if (word=="")
        return true;
    else
    {
        for (int i = word.size() - 1; i >= 0; i--)
        {
            if (word[i] == word[m])
            {
                pal = true;
                m++;
            }
            else
            {
                pal = false;
                break;
            }
        }
        return pal;
    }
}
