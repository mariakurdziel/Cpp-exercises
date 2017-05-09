//
// Created by olga on 05.05.17.
//

#include "MovieSubtitles.h"

namespace moviesubs {
    using namespace std;


    void moviesubs::MovieSubtitles::ShiftAllSubtitlesBy(int delay, int fps, istream *input, ostream *output) {
        int nrline=1;
        while (not input->eof()) {
            Delay(delay, fps, input, output, nrline);
            nrline++;
        }

    }

    void MicroDvdSubtitles::Delay(int delay, int fps, istream *input, ostream *output, int nrline) {
        int time = 0, dif = 0;
        dif = fps * delay / 1000;
        string s;
        getline(*input, s);
        regex pattern{R"(\{(\d+)\})"};
        smatch matches;
        while (regex_search(s, matches, pattern)) {
            time = stoi(matches[1].str());
            time += dif;
            if (time<0)
                throw NegativeFrameAfterShift(s, nrline);
            *output << "{" << time << "}";

            s = matches.suffix().str();
        }
        if (s != "")
            *output << s << "\n";

    }


    string inputtostring(istream &input) {
        std::string s;
        std::ostringstream os;
        os << input.rdbuf();
        s = os.str();
        return s;
    }

    void SubRipSubtitles::Delay(int delay, int fps, istream *input, ostream *output, int nrline) {
        int time[7], mili = 0, blok = 1, oldmili = 0;
        regex pattern2{R"(\d+)"};
        regex pattern{R"((\d+):(\d+):(\d+),(\d+) --> (\d+):(\d+):(\d+),(\d+))"};
        smatch matches;
        string s;
        getline(*input, s);

//        if (nrline>1) *output<<endl;
        if (fps < 0)
            throw invalid_argument("FPS cannot be negative");
        if (regex_match(s, pattern2)) {
            if (stoi(s) == nrline) {
                *output << s << endl;
                blok++;
                getline(*input, s);

                if (regex_search(s, matches, pattern)) {


                    for (int i = 0; i < 8; i++) time[i] = stoi(matches[i + 1].str());


                    mili = 1000 * time[2] + 60000 * time[1] + 3600000 * time[0] + time[3];
                    oldmili = mili;
                    mili += delay;
                    time[3] = mili % 1000;
                    mili = mili / 1000;
                    time[2] = mili % 60;
                    mili = mili / 60;
                    time[1] = mili % 60;
                    mili = mili / 60;
                    time[0] = mili;

                    mili = 1000 * time[6] + 60000 * time[5] + 3600000 * time[4] + time[7];
                    mili += delay;
                    oldmili += delay;
                    if (mili < oldmili)
                        throw SubtitleEndBeforeStart(s, nrline);
                    time[7] = mili % 1000;
                    mili = mili / 1000;
                    time[6] = mili % 60;
                    mili = mili / 60;
                    time[5] = mili % 60;
                    mili = mili / 60;
                    time[4] = mili;


                    *output << setfill('0') << setw(2) << time[0] << ":" << setfill('0') << setw(2)
                            << time[1] << ":" << setfill('0') << setw(2) << time[2] << "," << setfill('0')
                            << setw(3)
                            << time[3] << " --> " << setfill('0') << setw(2) << time[4] << ":" << setfill('0')
                            << setw(2) << time[5] << ":" << setfill('0') << setw(2) << time[6] << ","
                            << setfill('0')
                            << setw(3) << time[7] << endl;

                }else {
                    if (findchar(s, '.') == true)
                        throw InvalidSubtitleLineFormat(s, nrline - 1);
                    if (findchar(s, ';') == true)
                        throw InvalidSubtitleLineFormat(s, nrline - 1);
                    if (findchar(s, '--->') == true)
                        throw InvalidSubtitleLineFormat(s, nrline - 1);
                    if (occurences(s, "-->") != 1)
                        throw InvalidSubtitleLineFormat(s, nrline - 1);
                }
                while (not s.empty()) {
                    getline(*input, s);
                    *output << s << endl;

                }
                *output;


            } else throw OutOfOrderFrames(s, nrline-1);
            if (nrline==2) {
                if (delay < 0)
                    throw NegativeFrameAfterShift(s, nrline - 1);
            }
        }
    }




    NegativeFrameAfterShift::NegativeFrameAfterShift(string str, int line) : SubtitlesValidationException
        ("At line " + std::to_string(line) + ": " + str, line) {};


    SubtitleEndBeforeStart::SubtitleEndBeforeStart(string str, int line) : SubtitlesValidationException
        ("At line " + std::to_string(line) + ": " + str, line) {};


    MissingTimeSpecification::MissingTimeSpecification(string str, int line) : SubtitlesValidationException
        ("At line " + std::to_string(line) + ": " + str, line) {};


    OutOfOrderFrames::OutOfOrderFrames(string str, int line) : SubtitlesValidationException
        ("At line " + std::to_string(line) + ": " + str, line) {};




    InvalidSubtitleLineFormat::InvalidSubtitleLineFormat(string str, int line) : SubtitlesValidationException
         ("At line " + std::to_string(line) + ": " + str, line) {};

    bool findchar( std::string & tekst, char szukanyZnak )
    {
        size_t znalezionaPozycja = tekst.find( szukanyZnak );
        if( znalezionaPozycja == std::string::npos )
            return false;
        else
            return true;

    }

    int occurences (string & tekst, string szukany )
    {
        int occurrences1 = 0;
        string::size_type start = 0;

        while ((start = tekst.find(szukany, start)) != string::npos) {
            ++occurrences1;
            start += szukany.length(); // see the note
        }
        return occurrences1;
    }

}
