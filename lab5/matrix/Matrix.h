//
// Created by maria on 03.04.17.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <string>
#include <cstring>
#include <iostream>
#include <cmath>
#include <cstdint>
#include <algorithm>
#include <initializer_list>
#include <complex>
#include <vector>




using namespace std;

namespace algebra
{
    class Matrix
    {
    public:

        Matrix(int a, int b);

        Matrix();

        Matrix(const Matrix &matrix);

        void Copy(const Matrix &matrix);

        void **Build();

        Matrix &operator=(const Matrix &matrix);
        Matrix(const std::initializer_list<std::vector<std::complex<double>>> &elements);
        ~Matrix();
        Matrix Add (Matrix matrix) const;
        Matrix Sub(Matrix matrix) const;
        Matrix Mul(Matrix matrix) const;
        Matrix Mul(std::complex<double> n);
        Matrix Pow(int n);
        string Print() const;

        std::pair<int, int> Size();


    private:
        int a, b;
        complex<double> **tab;
        std::vector<std::complex<double>> elements;


    };
}
#endif //JIMP_EXERCISES_MATRIX_H

