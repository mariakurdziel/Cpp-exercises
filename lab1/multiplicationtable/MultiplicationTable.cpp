//
// Created by maria on 05.03.17.
//

#include "MultiplicationTable.h"
#include <iostream>

using namespace std;

void MultiplicationTable(int tab[][10])
{
    for(int i=0;i<10; i++)
        for(int j=0;j<10;j++)
        tab[i][j]=(i+1)*(j+1);

}