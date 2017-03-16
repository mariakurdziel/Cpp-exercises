//
// Created by lenovo on 2017-03-13.
//
#include <iostream>
#include <fstream>
#include "XorCypherBreaker.h"
using namespace std;

int main(void){
    string line, v;
    vector<string> dictionary {"ania", "basia"};
    vector<char> cryptogram {"the", "of"};
    ifstream myfile("p059_cipher.txt");

    if(!myfile)
        cout << "Nie można otworzyć pliku!" << endl;

    while(myfile >> line)
    {
        dictionary.push_back(line);
        cout<<line;
    }
    myfile.close();

    dictionary.push_back("trolololo");
    for (string v : cryptogram)
    {
        cout<<v<<endl;
    }
    PrintVector(dictionary);
    XorCypherBreaker(cryptogram, 3, dictionary);


return 0;
}