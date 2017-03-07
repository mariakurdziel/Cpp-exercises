//
// Created by mrozolga on 07.03.17.
//

#include "Array2D.h"
using namespace std;
void get_number (int** tab, int row, int col)
{
    int i, j, n=1;
    for (i=0; i<col; i++)
    {
        for (j=0; j<row; j++)
        {
            tab[i][j]=n;
            n++;
        }
    }
}

void printN (int** tab, int row, int col)
{
    int n;
    for (int i=0; i<col; i++)
    {
        for (int j=0; j<row; j++)
        {
            std::cout<<tab[i][j]<<" ";
            if (j==row-1)
            {
                std::cout<<endl;
            }
        }
    }
}
int **Array2D(int n_rows, int n_columns)
{
    int* tab=new int*[n_rows];
    for (int i=0; i<n_columns; i++)
    {
        int tab=new int[i];
    }
    get_number(tab, n_rows, n_columns);


}


