//
// Created by maria on 08.04.17.
//

#include "WordCounter.h"

namespace datastructures
{
    Word::Word() {
}


    Word::Word(string word) {
        key = word;
    }

    string Word::GetWord() const
    {
        return key;
    }

    Word::operator string() const{
        return key;
    }
    bool Word::operator==(const Word& word) const {
        return key==word.key;
    }
    bool Word::operator<(const Word& word) const {
        return key<word.key;
    }
    bool Word::operator>(const Word& word) const {
        return key>word.key;
    }
    Word::~Word() {
    }

    Counts::Counts() {
    }
    Counts::Counts(int count) {
        counter = count;
    }

    bool Counts::operator==(const Counts& count) const {
        return counter==count.counter;
    }

    Counts& Counts::operator++(){
        counter++;
        return *this;
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
    WordCounter::WordCounter()
    {
        int count=0;
        bool flag=true;

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
            std::list<std::pair<Word,Counts>>::const_iterator it;
            for (it = index.begin(); it != index.end(); ++it) {
                if(map[i].GetWord()==(*it).first.GetWord())
                {
                    flag=false;
                    break;
                }
            }
            if(flag==true)
                index.push_back(p);

        }
    }

    int WordCounter::operator[](string word)
    {
        int counter=0;
        for(int i=0; i<map.size();i++)
        {
            if(map[i].GetWord()==word)
                counter++;
        }

        return counter;
    }

    int WordCounter::DistinctWords()
    {
     return index.size();
    }

    int WordCounter::TotalWords()
    {
        return map.size();
    }

    std::set <Word> WordCounter::Words()
     {
         set <Word> vec={};

         for(int i=0; i<map.size();i++)
             vec.insert(map[i]);


         return vec;
     }



    WordCounter::~WordCounter() {
    }

}