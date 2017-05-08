//
// Created by maria on 04.05.17.
//

#include "MovieSubtitles.h"

namespace moviesubs {
    MovieSubtitles::MovieSubtitles() {

    }

    MovieSubtitles::~MovieSubtitles() {

    }

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, istream *in, ostream *out)
    {

        int del = delay_(delay, fps);
        bool flag=true;
        int licz1=0,licz2=0,licz3=0,licz4=0;
        int j=0,k=0,m=0;
        int counter=0;
        string output,tmp;
        string numbers,words;
        vector<string> vec={};
        vector<string> tmp2;
        vector <string> num;
        ostringstream os;


        os << (*in).rdbuf();
        string input = os.str();

        if(input[input.size()-1]!='\n')
            input+="\n";

        if(delay<0)
            throw NegativeFrameAfterShift();

        while (k < input.size())
        {
            if (input[k] == '{')
            {
                vec.push_back(words);
                words="";
                while (input[k]!='}' && k<input.size())
                {
                    numbers+= input[k];
                    k++;

                }
                numbers+='}';
                k++;
                vec.push_back(numbers);
                numbers = "";
            }
            else
            {
                words+=input[k];
                k++;
            }
        }
            vec.push_back(words);

        for(int i=0; i<vec.size();i++)
        {
            counter=0;

            if(vec[i][0]=='{')
            {
                for(int n=1;n<vec[i].size()-1;n++)
                {
                    if(int(vec[i][n])>=48 && int(vec[i][n])<=57)
                        counter++;
                }

                if(counter==vec[i].size()-2)
                    flag=true;
                else
                    flag=false;

               if(flag==false || (j==vec[i].size()-1) && vec[i][vec[i].size()-1]!='}')
                   throw InvalidSubtitleLineFormat();

                   output +='{';
                   for(int k=1; k<vec[i].size()-1;k++)
                       tmp+=vec[i][k];

                   if(tmp.size()>0 && flag==true)
                   {
                       tmp2.push_back(tmp);
                       output+=to_string(stoi(tmp)+del);
                   }
                   else
                       output+=tmp;
                   output +='}';
                   tmp="";
            }
            else
                output+=vec[i];
        }

        if(tmp2.size()<4)
            throw InvalidSubtitleLineFormat();
        else
        {
            licz1=stoi(tmp2[0]);
            licz2=stoi(tmp2[1]);
            licz3=stoi(tmp2[2]);
            licz4=stoi(tmp2[3]);

            if(licz1>licz2 || licz3>licz4)
                throw SubtitleEndBeforeStart(input);

        }

        *out<<output;

    }

    int MicroDvdSubtitles::delay_(int del, int framerate) {
        double permili = (framerate*del) / 1000;
        return permili;
    }


    int SubtitleEndBeforeStart::LineAt()
    {
    }

}
