//
// Created by maria on 20.03.17.
//

#include "SmartTree.h"


using namespace std;
using namespace datastructures;

int main()
{
    string tree="[99 [100 [1234 [none] [none]] [4321 [none] [none]]] "
            "[88 [897 [none] [none]] [761 [none] [none]]]]";
    cout << datastructures::DumpTree(datastructures::RestoreTree(tree));
    return 0;
}