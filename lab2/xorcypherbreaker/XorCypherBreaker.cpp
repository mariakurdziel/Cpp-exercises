//
// Created by lenovo on 2017-03-13.
//

#include "XorCypherBreaker.h"
using namespace std;

void XorCypherBreaker(const vector<char> &cryptogram, int key_length, const vector<string> &dictionary)
{
    bool first = true;
    for(auto n : dictionary)
    {
        if (n[0]==cryptogram[0]) cout<<n<<endl;
    }
}
void PrintVector(const vector<string> &v) {
    bool first = true;
    for(auto n : v) {
        if (!first) {
            cout<< ", ";
        } else {
            first = false;
        }
        cout << n;

    }
    cout<<endl;
}