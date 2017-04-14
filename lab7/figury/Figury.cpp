//
// Created by olga on 14.04.17.
//

#include "Figury.h"
using namespace std;
void Trojkat::rysuj()
{
    cout<<"  *  "<<endl;
    cout<<" * * "<<endl;
    cout<<"*****"<<endl;
}
void Kwadrat::rysuj()
{
    cout<<" *** "<<endl;
    cout<<" * * "<<endl;
    cout<<" *** "<<endl;
}
void Kolo::rysuj()
{
    cout<<"  *  "<<endl;
    cout<<"*   *"<<endl;
    cout<<"  *  "<<endl;
}

Kolo::Kolo() {}
Kwadrat::Kwadrat(){}
Trojkat::Trojkat() {}

void Ksztalt::rysuj() {
}
