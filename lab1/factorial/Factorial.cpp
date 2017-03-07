//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int factorial(int value) {
    if (value>=13)
    {
        return 0;
    }
    int fact = 1;
    if (value > 0) {
        for (int i = 1; i <= value; i++) {
            fact = fact * i;
        }
    } else {
        if (value == 0) fact = 1;
        else {
            for (int i = value; i < 0; i++) {
                fact = fact * i;
            }
        }
    }
    return fact;
}
