//
// Created by mrozolga on 07.03.17.
//

#ifndef JIMP_EXERCISES_ARRAY2D_H
#define JIMP_EXERCISES_ARRAY2D_H
#include <iostream>


int ** NewArray2D(int n_rows, int n_columns);
void PrintArray2D (int** tab, int row, int col);
void DeleteArray2D(int **array, int n_rows, int n_columns);
void FillArray2D (int row, int col, int** tab);

#endif //JIMP_EXERCISES_ARRAY2D_H
