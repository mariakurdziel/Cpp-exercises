//
// Created by maria on 05.03.17.
//
#include <iostream>
#include <MultiplicationTable.h>
#include <Show.h>

using namespace std;

int main()
{
    int tab[10][10];
    MultiplicationTable(tab);
    Show(tab);

    return 0;
}