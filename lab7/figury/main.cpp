//
// Created by olga on 14.04.17.
//

#include "Figury.h"

int main() {
    Trojkat a;
    Kolo b;
    Kwadrat c;
    Ksztalt *tab[10];
    for (int i=0; i<10; i++)
    {
        switch ((rand()%3)+1)
        {
            case 1:
                tab[i]= &a;
                break;

            case 2:
                tab[i] = &b;
                break;

            case 3:
                tab[i] = &c;
                break;

        }

    }
    for (int j=0; j<10; j++)
    {
        tab[j]->rysuj();
    }

}