//
// Created by maria on 05.03.17.
//


#include "Show.h"
#include <iostream>

using namespace std;

void Show(int tab[][10])
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            cout<<tab[i][j];
            cout<<" ";
        }
        cout<<"\n";
    }
}