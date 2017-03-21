//
// Created by maria on 20.03.17.
//

#include "SmartTree.h"


using namespace std;

namespace datastructures
{

    unique_ptr<struct SmartTree> CreateLeaf(int value) {

        unique_ptr<struct SmartTree> leaf=make_unique<struct SmartTree>();
        leaf->value = value;
        leaf->right = nullptr;
        leaf->left = nullptr;
        return leaf;
    }

    unique_ptr<struct SmartTree> InsertLeftChild(unique_ptr<struct SmartTree> tree, unique_ptr<struct SmartTree> left_subtree)
    {

        if(tree->left==nullptr)
        tree->left=move(left_subtree);

        return tree;

    }

    unique_ptr <SmartTree> InsertRightChild(unique_ptr<struct SmartTree> tree, unique_ptr<struct SmartTree> right_subtree)
    {
        if(tree->right==nullptr)
            tree->right=move(right_subtree);

        return tree;

    }

    void PrintTreeInOrder(const unique_ptr<struct SmartTree> &unique_ptr, ostream *out)
    {
     if(unique_ptr->left!=nullptr)
     {
         PrintTreeInOrder(unique_ptr->left,out);
     }
        (*out)<<unique_ptr->value<<", ";

     if(unique_ptr->right!=nullptr)
     {
            PrintTreeInOrder(unique_ptr->right,out);
     }

    }

    string DumpTree(const unique_ptr<struct SmartTree> &tree)
    {
        string tmp;

        if(tree==nullptr)
        {
            return "[none]";
        }
        else {
            tmp += "[";
            tmp += to_string(tree->value);
            tmp += " ";

            tmp += DumpTree(tree->left);
            tmp += " ";
            tmp += DumpTree(tree->right);
            tmp += "]";
        }
        return tmp;
    }

    unique_ptr<SmartTree> RestoreTree(const string &tree)
    {
        int l = 0;
        regex pattern {R"(\[(-*\d+|none)\s(.*))"};
        smatch matches;
        unique_ptr<SmartTree> tree2, tree3;
        if (regex_match(tree, matches, pattern)) {
            string children = matches[2].str();
            for (int i=0; i<children.size(); i++)
            {
                if (children[i]=='[')
                    l++;
                else if (children[i] == ']')
                    l--;
                else if (l == 0) {
                    l = i;
                    break;
                }
            }
            string left = children.substr(0,l);
            string right = children.substr(l + 1,children.size() - 1);
            tree2 = CreateLeaf(stoi(matches[1]));

            tree3 = RestoreTree(left);
            tree2 = InsertLeftChild(move(tree2), move(tree3));

            tree3 = RestoreTree(right);
            tree2 = InsertRightChild(move(tree2), move(tree3));
        }
        return tree2;
    }
}