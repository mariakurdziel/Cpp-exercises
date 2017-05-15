//
// Created by maria on 27.03.17.
//

#include "SimpleTemplateEngine.h"

using namespace std;

int main()
{
    nets::View message=new nets::View::"Hello {{name}}! How are you today? My name is {{program}}";
    std::unordered_map <string,string> l={{"name", "Zbigniew"}, {"program", "Borg"}};
    string decode=message.Render(l);

    return 0;
}
