//
// Created by maria on 13.03.17.
//
#include "GreatestProduct.h"

using namespace std;

int GreatestProduct(const vector<int> &numbers, int k)
{
    vector<int> greatest;
    int n=0;
    int m;
    int tmp;
    int il=1;
    while(n<k)
    {
        greatest.emplace_back(0);
        n++;
    }
    for (int v: numbers)
    {
        m=v;
        for(int &x: greatest)
        {
            if(m>x)
            {
            tmp=x;
            x=m;
            m=tmp;
            }

        }
    }

    for (int v : greatest)
    {
        cout<<v<<endl;
        il*=v;
    }

    return il;

}
