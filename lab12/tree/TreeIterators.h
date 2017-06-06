//
// Created by maria on 06.06.17.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H_H
#define JIMP_EXERCISES_TREEITERATORS_H_H

#include <Tree.h>
#include <vector>
namespace tree {
    template<class el>
    class InOrderTreeView;

    template<class el>
    InOrderTreeView<el> InOrder(Tree <el> *tree);

    template<class el>
    InOrderTreeView<el> InOrder(Tree <el> *tree) {
        return InOrderTreeView<el>(tree);
    }

    template<class el>
    void InOrderVector(std::vector<el> &v_, Tree <el> *tree) {
//        if (tree->Left_child()) {
//            InOrderVector(v_, tree->Left_child().get());
//        }
//        v_.emplace_back(tree->Value());
//        if (tree->Right_child()) {
//            InOrderVector(v_, tree->Right_child().get());
//        }
    }

    template<class el>
    class InOrderTreeIterator {
    public:
        InOrderTreeIterator() {}

        InOrderTreeIterator(Tree <el> *tree) : v_(std::vector<el>()) {
            InOrderVector<el>(v_, tree);
            iter = v_.begin();
        }

        InOrderTreeIterator &operator++() {
            ++iter;
            return *this;
        }

        el operator*() { return *iter; }

        bool operator!=(const InOrderTreeIterator &one) const { return iter != one.iter; }

        friend class InOrderTreeView<el>;

    private:
        void SetToEnd(void) { iter = v_.end(); };
        std::vector<el> v_;
        typename std::vector<el>::iterator iter;

    };


    template<class el>
    class InOrderTreeView {
    public:
        InOrderTreeView(Tree<int> *cos) : tree_(cos) {}

        InOrderTreeIterator<el> begin() { return tree_->Root(); }

        InOrderTreeIterator<el> end() {
            InOrderTreeIterator<el> new_iterator(this->tree_->Root());
            new_iterator.SetToEnd();
            return new_iterator;

        }

    private:
        Tree <el> *tree_;
    };

    template<class el>
    class PreOrderTreeView;

    template<class el>
    PreOrderTreeView<el> PreOrder(Tree <el> *tree);

    template<class el>
    PreOrderTreeView<el> PreOrder(Tree <el> *tree) {
        return PreOrderTreeView<el>(tree);
    }

    template<class el>
    void PreOrderVector(std::vector<el> &v_, Tree <el> *tree) {
        /* if (tree->Left_child()) {
             PreOrderVector(v_, tree->Left_child().get());
         }
         v_.emplace_back(tree->Value());
         if (tree->Right_child()) {
             PreOrderVector(v_, tree->Right_child().get());
         }*/
    }

    template<class el>
    class PreOrderTreeIterator {
    public:
        PreOrderTreeIterator() {}

        PreOrderTreeIterator(Tree <el> *tree) : v_(std::vector<el>()) {
            PreOrderVector<el>(v_, tree);
            iter = v_.begin();
        }

        PreOrderTreeIterator &operator++() {
            if (iter!=v_.end())
                ++iter;
        }

        el operator*() const{ if (iter!=v_.end()) return *iter;}

        bool operator!=(const PreOrderTreeIterator &one) const {
            auto a=one;
            return one.iter != iter;
        }

        friend class PreOrderTreeView<el>;

    private:
        void SetToEnd(void) { iter = v_.end(); };
        std::vector<el> v_;
        typename std::vector<el>::iterator iter;

    };


    template<class el>
    class PreOrderTreeView {
    public:
        PreOrderTreeView(Tree<int> *cos) : tree_(cos) {}

        PreOrderTreeIterator<el> begin() { return tree_->Root(); }

        PreOrderTreeIterator<el> end() {
            PreOrderTreeIterator<el> new_iterator(this->tree_->Root());
            new_iterator.SetToEnd();
            return new_iterator;

        }

    private:
        Tree <el> *tree_;
    };
}
#endif //JIMP_EXERCISES_TREEITERATORS_H_H
