//
// Created by maria on 09.03.17.
//
#include <Array2D.h>
#include <iostream>

using namespace std;

void DeleteArray2D(int **array,int n_rows, int n_columns)
{
    for(int i=0; i<n_rows;i++)
        delete [] array[i];
    delete [] array;
}

void PrintArray(int**tab, int n_rows,int n_columns)
{
   for(int i=0; i<n_rows;i++)
   {
      for(int j = 0;j<n_columns;j++)
      {
          cout<<tab[i][j];
          cout<<" ";
      }
   cout<<"\n";
   }
}
void FillArray2D(int **tab, int n_rows, int n_columns)
{
   int n=0;
   for(int i=0; i<n_rows;i++)
   {
      for(int j = 0;j<n_columns;j++)
         {
            tab[i][j]=n;
            n++;
         }
   }
}

int **Array2D(int n_rows, int n_columns)
{
    if(n_rows<=0 || n_columns<=0)
        return nullptr;
    else
    {
        int **tab = new int *[n_rows];
        for (int i = 0; i < 10; i++)
            tab[i] = new int[n_columns];
        return tab;
    }
}

