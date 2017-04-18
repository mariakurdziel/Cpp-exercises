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
        WordCounter(istream &is);
        WordCounter(string name);
        WordCounter(std::initializer_list<Word> vec):map(vec){};
        int operator[](string word);
        ostream & operator<< (ostream &wyjscie);
        void FromInputStream();
        int DistinctWords();
        int TotalWords();
        ~WordCounter();

    private:
        string file;
        char word[50];
        istream *is_;
        std::vector <Word> map;


    };

}
#endif //JIMP_EXERCISES_WORDCOUNTER_H
