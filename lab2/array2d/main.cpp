//
// Created by mrozolga on 07.03.17.
//

#include <iostream>
#include "Array2D.h"
using namespace std;

int main(void){
    int a,b;
    cout<<"Give me 2 numbers: "<<endl;
    cin>>a;
    cin>>b;
    int **tab=Array2D(a, b);
    printArray(tab, a, b);
    DeleteArray2D(tab, a, b);
}