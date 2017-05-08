//
// Created by olga on 05.05.17.
//

#include "MovieSubtitles.h"
using namespace std;
using namespace moviesubs;
int main()
{

        unique_ptr<MovieSubtitles> subs = make_unique<MicroDvdSubtitles>();
        stringstream in {"{0}{250}TEXT\n{260}{300}NEWLINE\n"};
        stringstream out;
        subs->ShiftAllSubtitlesBy(300, 25, &in, &out);
        cout<<out.str();

}