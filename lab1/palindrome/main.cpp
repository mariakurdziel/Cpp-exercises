//
// Created by maria on 05.03.17.
//

#include <iostream>
#include "Palindrome.h"

using namespace std;

int main()
{   string number;
    string word;

    cout<<"0 - zakoncz program"<<endl;
    cout<<"dowolny inny znak - sprawdz palindrom"<<endl;

    cin>>number;

    while(number!="0")
    {
        cout << "Podaj wyraz:"<<endl;
        cin>>word;
        bool pal = is_palindrome(word);
        if (pal == true)
        {
            cout << "Wyraz jest palindromem" << endl;
        } else
        {
            cout << "Wyraz nie jest palindromem" << endl;
        }
        cout<<"0 - zakoncz program"<<endl;
        cout<<"dowolny inny znak - sprawdz palindrom"<<endl;
        cin>>number;
    }
    return 0;
}
