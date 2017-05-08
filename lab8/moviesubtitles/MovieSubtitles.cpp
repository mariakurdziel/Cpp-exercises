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
        int time[7], mili = 0, blok = 0, tekst = 0;
        regex pattern2{R"(\d+)"};
        regex pattern{R"((\d+):(\d+):(\d+),(\d+) --> (\d+):(\d+):(\d+),(\d+))"};
        smatch matches;
        string s;
        getline(*input, s);

        if (regex_match(s, pattern2)) {
            if (stoi(s) == nrline) {
                *output << s << endl;
                nrline++;
                getline(*input, s);

                if (regex_search(s, matches, pattern)) {
                    for (int i = 0; i < 8; i++) time[i] = stoi(matches[i + 1].str());
                    mili = 1000 * time[2] + 60000 * time[1] + 3600000 * time[0] + time[3];
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
                    time[7] = mili % 1000;
                    mili = mili / 1000;
                    time[6] = mili % 60;
                    mili = mili / 60;
                    time[5] = mili % 60;
                    mili = mili / 60;
                    time[4] = mili;
                    blok++;
                    *output << setfill('0') << setw(2) << time[0] << ":" << setfill('0') << setw(2)
                            << time[1] << ":" << setfill('0') << setw(2) << time[2] << "," << setfill('0')
                            << setw(3)
                            << time[3] << " --> " << setfill('0') << setw(2) << time[4] << ":" << setfill('0')
                            << setw(2) << time[5] << ":" << setfill('0') << setw(2) << time[6] << ","
                            << setfill('0')
                            << setw(3) << time[7] << endl;

                }
                while (not s.empty()) {
                    getline(*input, s);
                    *output << s;
                    if (not s.empty()) *output<<endl;

                }



            }
        }
    }


}

