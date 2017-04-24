//
// Created by maria on 22.04.17.
//

#include "Geometry.h"
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


