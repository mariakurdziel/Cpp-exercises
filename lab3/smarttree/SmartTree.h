//
// Created by lenovo on 2017-03-20.
//

#ifndef JIMP_EXERCISES_SMARTTREE_H
#define JIMP_EXERCISES_SMARTTREE_H

#include <ostream>
#include <string>
#include <memory>
#include <utility>

using namespace std;
namespace datastructures {

    struct SmartTree
    {
        int value;
        struct SmartTree *parent=nullptr;
        struct SmartTree *leftchild=nullptr;
        struct SmartTree *rightchild=nullptr;

    };

    unique_ptr<SmartTree> CreateLeaf(int value);
    unique_ptr <SmartTree> InsertLeftChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> left_subtree);
}

#endif //JIMP_EXERCISES_SMARTTREE_H
