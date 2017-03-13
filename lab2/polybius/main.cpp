//
// Created by maria on 11.03.17.
//

#include "Polybius.h"

using namespace std;

int main(int argc, const char* argv[])
{
    string message;
    string crypted;
    string decrypted;
    char word[80];
    int n;

    if(argc==4) {
        n = atoi(argv[3]);

        ifstream myfile1(argv[1]);
        ofstream myfile2(argv[2], ios_base::in | ios_base::app);
        if (!myfile1)
            cout << "Nie można otworzyć pliku 1!" << endl;

        if (!myfile2)
            cout << "Nie można otworzyć pliku 2!" << endl;

        if (n == 1) {
            while (myfile1 >> word) {
                crypted = PolybiusCrypt(word);
                myfile2 << crypted << endl;
            }
        }
        if (n == 0) {
            while (myfile1 >> word) {
                decrypted = PolybiusDecrypt(word);
                myfile2 << decrypted << endl;
            }
        }

        myfile1.close();
        myfile2.close();
    }
    else
        cout<<"Za malo argumentow!"<<endl;
    return 0;
}

