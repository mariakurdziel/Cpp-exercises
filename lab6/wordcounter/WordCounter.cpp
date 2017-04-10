//
// Created by maria on 08.04.17.
//

#include "WordCounter.h"

namespace datastructures
{

    Word::Word(string word) {
        key = word;
    }

    string Word::GetWord()
    {
        return key;
    }

    Word::~Word() {
    }


    Counts::Counts(int count) {
        counter = count;
    }

    int Counts::GetCounter()
    {
        return counter;
    }

    Counts::~Counts() {
    }


    WordCounter::WordCounter(string name) {
        string onew;
        file = name;
        ifstream myfile(file);

        while(myfile >> word)
        {
            for(int i=0; word[i]!='\0';i++)
                onew+=word[i];
            Word w(onew);
            map.push_back(w);
            onew="";

        }

    }

    WordCounter::WordCounter(std::list <Word> map)
    {



    }

    int WordCounter::DistinctWords()
    {
     return index.size();
    }

    int WordCounter::TotalWords()
    {

    }

    std::list<std::pair<Word, Counts>> WordCounter::Words()
     {

     }



    WordCounter::~WordCounter() {
    }
}