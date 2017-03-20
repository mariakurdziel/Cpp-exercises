//
// Created by lenovo on 2017-03-20.
//

#include "SmartTree.h"

using namespace std;

namespace datastructures
{

    struct SmartTree
    {
        int value;
        struct SmartTree *parent=nullptr;
        struct SmartTree *leftchild=nullptr;
        struct SmartTree *rightchild=nullptr;

    };

    unique_ptr <struct SmartTree> CreateLeaf(int value)
    {
        unique_ptr<struct SmartTree> leaf = make_unique<struct SmartTree>();
        leaf->value=value;
        return leaf;
    }
    unique_ptr <struct SmartTree> InsertLeftChild(unique_ptr<struct SmartTree> tree, unique_ptr<struct SmartTree> left_subtree)
    {
        tree->leftchild=&(*left_subtree);
        left_subtree->parent=&(*tree);

    }
}