//
// Created by maria on 09.03.17.
//

#include <iostream>
#include "Array2D.h"


using namespace std;

int main()
{
    int **tab;
    int x,y;
    cout<<"Podaj ilosc wierszy:"<<endl;
    cin>>x;
    cout<<"Podaj ilosc kolumn:"<<endl;
    cin>>y;

    tab=Array2D(x,y);
    FillArray2D(tab,x,y);
    PrintArray(tab,x,y);
    DeleteArray2D(tab,x,y);
    return 0;
}
