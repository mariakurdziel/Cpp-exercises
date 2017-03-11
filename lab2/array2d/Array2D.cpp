//
// Created by mrozolga on 07.03.17.
//

#include "Array2D.h"
using namespace std;


void printArray (int** tab, int row, int col)
{
    for (int i=0; i<col; i++)
    {
        for (int j=0; j<row; j++)
        {
            std::cout<<tab[i][j]<<" ";
            if (j==row-1)
            {
                cout<<endl;
            }
        }
    }
}
int** Array2D(int n_rows, int n_columns)
{
    if (n_rows<=0 || n_columns<=0) return nullptr;
    else {
        int **tab = new int *[n_rows];
        int n = 1;
        for (int i = 0; i < n_rows; i++) {
            tab[i] = new int[n_columns];
            for (int j = 0; j < n_columns; j++) {
                tab[i][j] = n;
                n++;
                if (j == (n_columns - 1)) cout << endl;
            }
        }
        return tab;
    }
}

void DeleteArray2D(int** array, int n_rows, int n_columns)
{
    for (int i=0; i<n_rows; i++)
    {
        delete [] array[i];
    }
    delete [] array;
}
