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
        Word();
        operator string() const;
        bool operator==(const Word& word) const;
        bool operator<(const Word& word) const;
        bool operator>(const Word& word) const;
        Word(string word);
        string GetWord() const;
        ~Word();

    private:
        string key;

    };

    class Counts {
    public:
        Counts();
        operator string() const;
        bool operator==(const Counts& counts) const;
        Counts &operator++();
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
        WordCounter(std::initializer_list<Word> vec):map(vec){};
        int operator[](string word);
        std::vector <Word> Words();
        int DistinctWords();
        int TotalWords();
        ~WordCounter();

    private:
        string file;
        char word[50];
        int count=0;
        std::vector <Word> map;


    };


}
#endif //JIMP_EXERCISES_WORDCOUNTER_H
