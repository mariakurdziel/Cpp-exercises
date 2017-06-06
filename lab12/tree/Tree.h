//
// Created by maria on 03.06.17.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <initializer_list>


namespace tree {
    template<typename T>
    class InOrderTreeIterator;

    template<class T>
    class Tree {
    public:
        Tree();

        Tree(const T &e);

        ~Tree();

        bool operator<(const Tree<T> &e) const;
        std::unique_ptr<Tree<T>> Right_child()
        {
            return std::move(right_);
        }
        Tree* Root() {return root_;}
        void Insert(const T &e) {
            if (value < e) {
                if (left_ == nullptr) {
                    left_ = std::make_unique<Tree<T>>(e);
                } else {
                    left_->Insert(e);
                }
            } else {
                if (right_ == nullptr) {
                    right_ = std::make_unique<Tree<T>>(e);
                } else {
                    right_->Insert(e);
                }

            }
            size_++;
        }

        bool Find(const Tree<T> &e) {
            if (value == e) return true;
            if (value < e) {
                if (left_ == nullptr) return false;
                else left_->Find(e);
            } else {
                if (right_ == nullptr) return false;
                else right_->Find(e);
            }
        }

        size_t Depth() {
            size_t l = 0, max = 0;
            if (left_ != nullptr && right_ != nullptr) {
                return 1 + std::max(left_->Depth(), right_->Depth());
            } else {
                if (left_ != nullptr)
                    return 1 + left_->Depth();
                if (right_ != nullptr)
                    return 1 + right_->Depth();
                return 1;
            }


        }

        size_t Size() {
            return size_;
        }
        std::unique_ptr<Tree<T>> Left_child()
        {
            return std::move(left_);
        }
        int Value() {
            return value;
        }



    private:
        std::unique_ptr<Tree<T>> left_;
        std::unique_ptr<Tree<T>> right_;
        T value;
        size_t size_;
        Tree* root_;

    };

    template<class T>
    Tree<T>::Tree(): root_(this){}

    template<class T>
    Tree<T>::Tree(const T &e) :value(e) {
        left_ = nullptr;
        right_ = nullptr;
        size_ = 1;
        root_ = this;
    }

    template<class T>
    Tree<T>::~Tree() {
    }

    template<class T>
    bool Tree<T>::operator<(const Tree<T> &e) const {
        if (value < e.value) return true;
        else return false;
    }



}


#endif //JIMP_EXERCISES_TREE_H
