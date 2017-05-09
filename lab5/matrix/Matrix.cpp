//
// Created by maria on 03.04.17.
//
#include "Matrix.h"


namespace algebra
{
    using namespace std;
    Matrix::Matrix(int a, int b)
    {

        this->a = a;
        this->b = b;

    }

    Matrix::Matrix()
    {}

    Matrix::Matrix(const Matrix &matrix)
    {
        Build();
        Copy(matrix);

    }


    void Matrix::Copy(const Matrix &matrix)
    {
        for (int i = 0; i < matrix.a; i++)
        {
            for (int j = 0; j < matrix.b; j++)
                tab[i][j] = matrix.tab[i][j];
        }

    }

    void **Matrix::Build()
    {
        this->a = a;
        this->b = b;
        tab = new complex<double> *[a];
        for (int i = 0; i < a; i++)
        {
            tab[i] = new complex<double>[b];
        }

    }

    Matrix &Matrix::operator=(const Matrix &matrix)
    {
        if (this == &matrix)
            return *this;

    }

    Matrix::~Matrix()
    {

        for (int i = 0; i < b; i++)
        {
            delete[] tab[i];
        }
        delete[] tab;
        tab = nullptr;
        a = 0;
        b = 0;



    }

    std::pair<int, int> Matrix::Size() {
        std::pair<int, int> size;
        size = {a, b};

        return size;
    }

    Matrix::Matrix(const std::initializer_list<std::vector<std::complex<double>>> &elements)
    {
        auto it_tab = elements.begin();
//        this->a=elements.size();
//        this->b= (*(it_tab)).size();
//        Build();
        for (/*;  it_tab != it_tab++; it_tab++*/ auto i=0; i<elements.size(); i++)
        {
            auto vec = *(it_tab + i);
            for (int j=0; j<vec.size(); j++)
            {
                tab[i][j]=vec[j];

            }
        }
    }


    Matrix Matrix::Add(Matrix matrix) const
    {
        Matrix c(a, b);
        c.a = a;
        c.b = b;
        c.tab = new complex<double> *[a];
        for (auto i = 0; i < a; i++)
            c.tab[i] = new complex<double>[b];
        if (matrix.a == a && matrix.b == b)
        {

            for (int i = 0; i < a; i++)
            {
                for (int j = 0; j < b; j++)
                {
                    c.tab[i][j] = tab[i][j] + matrix.tab[i][j];

                }
            }

        }
        return c;

    }


    Matrix Matrix::Mul(Matrix matrix) const
    {
        complex<double> sum;
        Matrix c;
        if (b == matrix.a && a > 0 && b > 0)
        {
            c.a=a;
            c.b=matrix.b;
            c.tab = new complex<double> *[a];
            for (auto i = 0; i < a; i++)
                c.tab[i] = new complex<double>[b];

            for (int i = 0; i < a; i++)
            {
                sum = 0.0;
                for (int j = 0; j < matrix.b; j++)
                {
                    sum = 0.0;
                    for (int k = 0; k < b; k++)
                        sum = sum + tab[i][j] * matrix.tab[j][i];
                    c.tab[i][j] = sum;
                }

            }

        }
        return c;

    }
    Matrix Matrix::Mul(std::complex<double> n)
    {
        Matrix c(a,b);
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                c.tab[i][j] = c.tab[i][j]*n;
                std::cout<<c.tab[i][j]<<std::endl;
            }
        }
        return c;
    }
//    Matrix Matrix::Pow(int n) {
//        int k=1;
//        Matrix result;
//        if(a==b && a>=0) {
//            result.a = a;
//            result.b = b;
//            result.tab = new complex<double> *[a];
//            for (auto i = 0; i < a; i++) {
//                result.tab[i] = new complex<double>[b];
//            }
//            for (auto i = 0; i < a; i++) {
//                for (auto j = 0; j <b; j++)
//                    result.tab[i][j] = tab[i][j];
//            }
//            if(a==1)
//                return result;
//            if(a>0)
//            {
//                while(k!=a) {
//                    result = this->Mul(result);
//                    k++;
//                }
//            }
//            else
//            {
//                for (auto i = 0; i < a; i++) {
//                    for (auto j = 0; j < b; j++) {
//                        if (i == j && a==0) {
//                            result.tab[i][j] = complex<double>(1, 0);
//                        } else {
//                            result.tab[i][j] = complex<double>(0, 0);
//                        }
//                    }
//                }
//            }
//        }
//        else
//        {
//            result.a=0;
//            result.b=0;
//            result.tab= nullptr;
//        }
//        return result;
//    }
//    Matrix Matrix::Pow(int n) const
//    {
//        if (a==b)
//        {
//            if (n==0)
//            {
//                Matrix c(a, b);
//                for (int i = 0; i < a; i++)
//                {
//                    for (int j = 0; j < b; j++)
//                    {
//                        if (i == j) c.tab[i][j] = 1;
//                        else c.tab[i][j] = 0;
//                    }
//                }
//                return c;
//            }
//            else
//            {
//                Matrix c = *this;
//                for (int i=0; i<n; i++)
//                {
//                    c=c.Mul(*this);
//                }
//                return c;
//            }
//
//        }
//
//    }

    Matrix Matrix::Sub(const Matrix matrix) const
    {
        Matrix c(a, b);
        if (matrix.a==a && matrix.b==b)
        {

            for (int i = 0; i < a; i++)
            {
                for (int j = 0; j < b; j++)
                {
                    c.tab[i][j] = tab[i][j]-matrix.tab[i][j];

                }
            }

        }

        return c;

    }

    string Matrix::Print() const
    {
        string output;
        output+="[";
        for (int i=0; i<a; i++)
        {
            for (int j=0; j<b; j++)
            {
                output+=(tab[i][j]).imag();
                output+="i";
                output+=(tab[i][j]).real();
                if (j==(b-1) && i!=(a-1)) output+="; ";
                else output+=", ";
            }

        }
        output+="]";
        return output;
    }
}