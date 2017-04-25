//
// Created by maria on 08.04.17.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <iostream>
#include <fstream>
#include <list>
#include <set>
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
        std::set <Word> Words();
        WordCounter();
        WordCounter(std::initializer_list<Word> vec):map(vec){};
        int operator[](string word);
        ostream & operator<< (ostream &wyjscie);
        void FromInputStream(ifstream &is);
        int DistinctWords();
        int TotalWords();
        ~WordCounter();

    private:
        string file;
        std::vector <Word> map;
        ifstream *is_;

    };

}
#endif //JIMP_EXERCISES_WORDCOUNTER_H
