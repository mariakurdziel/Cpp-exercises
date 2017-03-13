//
// Created by mrozolga on 07.03.17.
//

#include "Array2D.h"
using namespace std;


void PrintArray2D (int** tab, int row, int col)
{
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            std::cout<<tab[i][j]<<" ";
            if (j==col-1)
            {
                cout<<endl;
            }
        }
    }
}
void FillArray2D (int row, int col, int** tab)
{
    int n=1;
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            tab[i][j]=n;
            n++;
        }
    }
}
int** NewArray2D(int n_rows, int n_columns)
{
    if (n_rows<=0 || n_columns<=0) return nullptr;
    else {
        int **tab = new int *[n_rows];
        for (int i = 0; i < n_rows; i++) {
            tab[i] = new int[n_columns];
        }
        FillArray2D(n_rows, n_columns, tab);
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
