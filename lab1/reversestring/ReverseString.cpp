#include "ReverseString.h"

using namespace std;

string reverse(string word)
{
    string reversed="";

    for(int j=word.size()-1;j>=0;j--)
 {
     reversed+=word[j];
 }
    return  reversed;
}
