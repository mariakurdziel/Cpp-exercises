//
// Created by olga on 05.05.17.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <stdexcept>
#include <iostream>
#include <string>
#include <iomanip>
#include <regex>
#include <sstream>
#include <memory>

using std::ostream;
using std::istream;
namespace moviesubs
{
    using namespace std;
    class MovieSubtitles
    {
    public:
        void ShiftAllSubtitlesBy(int delay, int fps, istream *input, ostream *output);
        virtual void Delay (int delay, int fps, istream *input, ostream *output, int nrline)=0;

    };

    class MicroDvdSubtitles : public MovieSubtitles
    {
    public:
        virtual void Delay (int delay, int fps, istream *input, ostream *output, int nrline);

    };
    class SubRipSubtitles : public MovieSubtitles
    {
    public:
        virtual void Delay (int delay, int fps, istream *input, ostream *output, int nrline);
    };
    string inputtostring(istream &input);
}


#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
