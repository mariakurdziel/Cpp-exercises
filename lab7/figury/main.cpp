//
// Created by maria on 22.04.17.
//

#include "Geometry.h"

int main() {
    Trojkat a;
    Kolo b;
    Kwadrat c;
    std::list <Ksztalt*> vec;
    for (int i=0; i<10; i++)
    {
        switch ((rand()%3)+1)
        {
            case 1:
                vec.push_back(&a);
                break;

            case 2:
                vec.push_back(&b);
                break;

            case 3:
                vec.push_back(&c);
                break;

        }

    }
    std::list<Ksztalt*>::iterator it;

    for (it=vec.begin(); it!=vec.end(); it++)
    {
        (*it)->rysuj();
    }

}



