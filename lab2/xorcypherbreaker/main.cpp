//
// Created by maria on 13.03.17.
//

#include "XorCypherBreaker.h"

using namespace std;

int main() {
    int n;
    int k = 0;
    string word;
    int length;
    string key;

    vector<string> dictionary;
    vector<char> cryptogram;

    cout << "Podaj ilosc wyrazow w slowniku:" << endl;
    cin >> n;
    cout << "Podaj dlugosc klucza:" << endl;
    cin >> length;

    while (n < k)
    {
        cin>>word;
        dictionary.push_back(word);
    }

    key=XorCypherBreaker(cryptogram,length,dictionary);
    return 0;
}