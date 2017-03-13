//
// Created by maria on 13.03.17.
//
#include "GreatestProduct.h"

using namespace std;

int main() {
    int n, k,product,x;
    int i = 0;

    vector <int> number;


    cout << "Podaj ilosc elementow wektora:" << endl;
    cin >> n;
    cout << "Podaj ilosc czynnikow:" << endl;
    cin >> k;

    cout<<endl;

    while (i<n)
    {
        cin>>x;
        number.push_back(x);
        i++;
    }

    cout<<endl;

    for (int v : number)
    {
        cout<<v<<endl;
    }

    product=GreatestProduct(number,k);

    cout<<endl;
    cout<<product<<endl;

    return 0;
}
