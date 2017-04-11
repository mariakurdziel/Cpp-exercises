//
// Created by mrozolga on 11.04.17.
//
#include "ArrayFill.h"

namespace arrays {
    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (size_t i = 0; i < size; i++) {
            v->emplace_back(filler.Value(i));
        }
    }

    int UniformFill::Value(int index) const {
        return value_;
    }

    int IncrementalFill::Value(int index) const {
        return value_ + index * step_;
    }

    int RandomFill::Value(int index) const {
        int liczba =
        return liczba;
    }

    int SquaredFill::Value(int index) const {
        return a_ * pow(index, 2) + b_;
    }
}