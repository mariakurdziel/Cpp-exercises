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
        bool flag=true;
        int i;
        std::list<std::pair<Word, Counts>>:: iterator it;
        for( i=0; i<map.size();i++)
        {
            for (it=index.begin();it!=index.end();it++)
            {
                if(map[i].GetWord()==(*it).first.GetWord())
                {
                    (*it).second = Counts((*it).second.GetCounter() + 1);
                    flag=false;
                    break;
                }

            }
            if(flag==true)
            {
                auto p = make_pair(map[i],Counts(1));
                index.push_back(p);
            }

        flag=true;
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
        int c=0;
        int i;
        vector <Word> s;
        for(int i=0; i<map.size();i++) {
            if (std::find(s.begin(), s.end(), map[i]) != s.end())
                c++;

            if (c == 0)
                s.push_back(map[i]);
            c = 0;
        }
        return s.size();
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