//
// Created by olga on 14.04.17.
//

#ifndef JIMP_EXERCISES_FIGURY_H
#define JIMP_EXERCISES_FIGURY_H
#include <iostream>
#include <string>
#include <cmath>
#include <ostream>
#include <random>

class Ksztalt {
public:
    virtual void rysuj();
};

class Trojkat : public Ksztalt
{
public:
    Trojkat();
    void rysuj();
};
class Kwadrat : public Ksztalt
{
public:
    Kwadrat();
    void rysuj();
};
class Kolo : public Ksztalt
{
public:
    Kolo();
    void rysuj();
};

#endif //JIMP_EXERCISES_FIGURY_H
