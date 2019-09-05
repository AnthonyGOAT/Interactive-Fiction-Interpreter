#include "link.h"
using namespace std;

Link::Link(PartToken& in){

    type = in.getType();
    stype = "Link";

    string temp = in.getText();

    //create the links when the display and target is the same
    if(temp.find("-&gt;") == string::npos)
    display = target = temp.substr(2, temp.length()-4);
    //create the display and value separately when -&gt; delimiter is found.
    else
    {
        int loc = temp.find("-&gt;");
        display = temp.substr(2, loc-2);
        loc += 5;
        target = temp.substr(loc, temp.length() - loc-2);
    }

    //trim begining whitespace on both display and target
    while(display.at(0) == ' ')
        display = display.substr(1);
    while(target.at(0) == ' ')
        target = target.substr(1);

    //trim whitespace off the end of the display and target
    while(display.at(display.length()-1) == ' ')
        display = display.substr(0,display.length() - 2);
    while(target.at(target.length()-1) == ' ')
        target = target.substr(0,target.length() - 2);


}

void Link::print(){
    cout << stype<<":  display=" << display <<", target="<<target<<endl;
}
