//
// Created by maria on 04.05.17.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H
#include <iostream>
#include <string>
#include<istream>
#include <sstream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;
namespace moviesubs
{
class MovieSubtitles
{
public:
    MovieSubtitles();
    virtual void ShiftAllSubtitlesBy(int delay, int fps, istream *input, ostream *output)=0;

    ~MovieSubtitles();
};


class MicroDvdSubtitles: public MovieSubtitles
{
public:
    MicroDvdSubtitles(){}
    virtual void ShiftAllSubtitlesBy(int delay, int fps,istream* input, ostream* output) override;
    int delay_(int delay, int framerate);
    ~MicroDvdSubtitles(){}

};

class SubRipSubtitles: public MovieSubtitles
{
public:
    SubRipSubtitles();
    ~SubRipSubtitles();


};

class NegativeFrameAfterShift
{
public:
    NegativeFrameAfterShift(){}
    ~NegativeFrameAfterShift(){}


};

class SubtitleEndBeforeStart{
public:
    SubtitleEndBeforeStart(string &input):input_(input){}
    ~SubtitleEndBeforeStart(){}
    int LineAt();
    string what();
private:
     const string input_;

};

class InvalidSubtitleLineFormat{
public:
    InvalidSubtitleLineFormat(){}
    ~InvalidSubtitleLineFormat(){}

};

class MissingTimeSpecification
{

};

class OutOfOrderFrames
{
};
}
#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
