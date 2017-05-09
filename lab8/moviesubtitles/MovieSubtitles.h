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
#include <stdexcept>
#include <algorithm>

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




    class SubtitlesValidationException : public std::runtime_error
    {
    protected:
        int line;

    public:
        virtual int LineAt() const { return line; }
        SubtitlesValidationException(std::string str, int line) : line(line),  std::runtime_error(str) {}
    };

    class NegativeFrameAfterShift : public SubtitlesValidationException
    {
    public:
        NegativeFrameAfterShift(string str, int line);
    };

    class SubtitleEndBeforeStart : public SubtitlesValidationException
    {
    public:
        SubtitleEndBeforeStart(string str, int line);
    };

    class InvalidSubtitleLineFormat : public SubtitlesValidationException
    {
    public:
        InvalidSubtitleLineFormat(string str, int line);
    };

    class MissingTimeSpecification : public SubtitlesValidationException
    {
    public:
        MissingTimeSpecification(string str, int line);
    };

    class OutOfOrderFrames : public SubtitlesValidationException
    {
    public:
        OutOfOrderFrames(string str, int line);
    };

    bool findchar( std::string & tekst, char szukanyZnak );
    int occurences (string &tekst, string szukany );
};



#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
