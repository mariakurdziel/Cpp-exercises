//
// Created by maria on 11.03.17.
//
#include "Polybius.h"
using namespace std;


string PolybiusCrypt(string message)
{
    string crypt;
    string alphabet1="ABCDEFGHIKLMNOPQRSTUVWXYZ";
    string alphabet2="abcdefghiklmnopqrstuvwxyz";
    int tab[]={11,12,13,14,15,21,22,23,24,25,31,32,33,34,35,41,42,43,44,45,51,52,53,54,55};
    int s;
    for(int i=0; i<message.size();i++)
    {
        s=(int)message[i];
        if(s>=65 && s<=90)
        {
            if(message[i]=='J')
                crypt+="24";
            else
            {
                for (int j = 0; j < alphabet1.size(); j++)
                {
                    if (message[i] == alphabet1[j])
                    {
                        crypt += to_string(tab[j]);
                    }
                }
            }
        }
        if(s>=97 && s<=122)
        {
            if(message[i]=='j')
                crypt+="24";
            else
            {

                for(int j=0;j<alphabet2.size();j++)
                {
                    if (message[i] == alphabet2[j])
                    {
                    crypt+=to_string(tab[j]);
                    }
                }
            }
        }
    }
    return crypt;

}
string PolybiusDecrypt(string crypted)
{
    string decrypt;
    int k=0;
    string alphabet1="abcdefghiklmnopqrstuvwxyz";
    char tab[][2]={{'1','1'},{'1','2'}, {'1','3'},{'1','4'},{'1','5'},{'2','1'},{'2','2'},{'2','3'},{'2','4'},{'2','5'},{'3','1'},{'3','2'},{'3','3'},{'3','4'},{'3','5'},{'4','1'},{'4','2'},{'4','3'},{'4','4'},{'4','5'},{'5','1'},{'5','2'},{'5','3'},{'5','4'},{'5','5'}};

    if(crypted=="")
        return decrypt;

    while(k<=crypted.size()-2)
    {
        for (int j=0;j<25;j++)
        {
            if(tab[j][0]==crypted[k] && tab[j][1]==crypted[k+1])
            {
                decrypt += alphabet1[j];
                k = k + 2;
                break;
            }
        }

    }
    return decrypt;
}
