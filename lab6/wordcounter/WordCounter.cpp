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


   /* WordCounter::WordCounter(string name) {
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
*/
    WordCounter::WordCounter(std::vector <Word> x)
    {
        map=x;
        int count=0;

        for(int i=0; i<map.size();i++)
        {
            for (int j = 0; j < map.size(); j++)
            {
                if(map[i].GetWord()==map[j].GetWord())
                    count++;
            }
            Word w(map[i]);
            Counts c(count);
            auto p=make_pair(w,c);
            std::list<std::pair<Word, Counts>> ::iterator it = find_if( index.begin(), index.end(),&p);
            if(it!=index.end())
                count=0;
            else
            {
                count=0;
                index.push_back(p);
            }

        }
    }



    int WordCounter::DistinctWords()
    {
     return index.size();
    }

    int WordCounter::TotalWords()
    {
        return map.size();
    }

    std::vector <Word> WordCounter::Words()
     {
         vector <Word> vec;


         return vec;
     }



    WordCounter::~WordCounter() {
    }
}