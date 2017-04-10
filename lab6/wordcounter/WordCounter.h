//
// Created by maria on 08.04.17.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <map>


using std::pair;
using namespace std;

namespace datastructures
{
    class Word {
    public:
        Word(string word);
        string GetWord();
        ~Word();

    private:
        string key;

    };

    class Counts {
    public:
        Counts(int count);
        int GetCounter();
        ~Counts();

    private:
        int counter;
    };

    class WordCounter
    {
    public:
        std::list<std::pair<Word, Counts>> index;
        WordCounter();
        WordCounter(string name);
        WordCounter(std::list <Word> x);
        std::list<std::pair<Word, Counts>> Words();
        int DistinctWords();
        int TotalWords();
        ~WordCounter();

    private:
        string file;
        char word[50];
        int count=0;
        std::list <Word> map;


    };
}
#endif //JIMP_EXERCISES_WORDCOUNTER_H
