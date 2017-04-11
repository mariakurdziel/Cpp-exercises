//
// Created by mrozolga on 11.04.17.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <memory>
#include <cstdlib>
#include <initializer_list>
#include <ctime>
#include <random>


namespace arrays {
    class ArrayFill {
    public:
        virtual int Value(int index) const =0;
    };

    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v);

    class UniformFill : public ArrayFill {
    public:
        UniformFill(int value = 0) : value_{value} {};

        virtual int Value(int index) const override;

    private:
        int value_;
    };

    class IncrementalFill : public ArrayFill {
    public:
        IncrementalFill(int value = 0, int step = 1) : value_{value}, step_{step} {};

        virtual int Value(int index) const override;

    private:
        int value_;
        int step_;

    };

    class RandomFill : public ArrayFill {
    public:
        RandomFill(std::unique_ptr<std::default_random_engine> a, std::unique_ptr<std::uniform_int_distribution<int>> b)
                : a_{move(a)}, b_{move(b)} {};

        virtual int Value(int index) const override;

    private:
        std::unique_ptr<std::default_random_engine> a_;
        std::unique_ptr<std::uniform_int_distribution<int>> b_;

    };

    class SquaredFill : public ArrayFill {
    public:
        SquaredFill(int a = 1, int b = 0) : a_{a}, b_{b} {};

        virtual int Value(int index) const override;

    private:
        int a_, b_;
    };
}
#endif //JIMP_EXERCISES_ARRAYFILL_H
