//
// Created by maria on 06.03.17.
//

#include <cstdint>
#include <iostream>
#include "DoubleBasePalindromes.h"

using namespace std;

int main()
{
    uint64_t suma;
    int val=1000000;


        suma=DoubleBasePalindromes(val);

    cout<<"Suma podwojnych palindromow w przedziale od 0 do "<<val<<" wynosi "<<suma<<endl;

    return 0;
}