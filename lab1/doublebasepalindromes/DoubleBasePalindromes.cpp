//
// Created by maria on 06.03.17.
//
#include <cstdint>
#include <string>
#include <iostream>
#include "DoubleBasePalindromes.h"

using namespace std;

uint64_t DoubleBasePalindromes(int max_vaule_exculsive)
{
    string dzies;
    string bin;
    int k=0;
    int s=0;
    int dz;
    int liczba;
    int licz;
    uint64_t suma=0;
    bool pal=false;
    bool pal2=false;

    for(int i=1; i<=max_vaule_exculsive; i++)
    {
        liczba=i;
        licz=i;
        dz=i;
        while (dz > 0)
        {
            dzies+= to_string(dz% 10);
            dz= dz/10;
        }
        cout<<dzies<<endl;

        for (int i =dzies.size()-1; i >= 0; i--)
        {
            if (dzies[i] == dzies[k])
            {
                pal = true;
                k++;
            }
            else
            {
                pal = false;
                break;
            }
        }

        if (pal == true)
        {
                while (liczba > 0)
                {
                    bin+=to_string(liczba % 2);
                    liczba = liczba / 2;
                }

                if (bin[0] == 0)
                    break;

                for (int i = bin.size()-1; i >= 0; i--)
                {
                    if (bin[i] == bin[s])
                    {
                        pal2 = true;
                        s++;
                    } else
                    {
                        pal2 = false;
                        break;
                    }
                }
                if (pal2 == false)
                    break;
                else
                    suma+=licz;
                }
         pal=false;
         pal2=false;
         s=0;
         k=0;
         dzies="";
         bin="";
       }
       return suma;
      }