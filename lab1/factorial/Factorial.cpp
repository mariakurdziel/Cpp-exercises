//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int factorial(int value)
{
    int il=1;

    if (value==0 || value==1)
        return 1;
    if (value+13<=0 || value>=13)
        return 0;
    else
    {
        if(value>0)
        {
            for (int i = 2; i <= value; i++)
                il = il * i;
        }
        else
        {
            for(int i=value; i<0;i++)
                il=il*i;
        }
        return il;
    }
}
