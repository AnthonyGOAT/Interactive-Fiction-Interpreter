#include "gotocomm.h"
using namespace std;


GoToComm::GoToComm(PartToken& in){

    type = in.getType();
    stype = "Go-to";

    string temp = in.getText();
    int beginloc = temp.find("&quot;");
    beginloc += 6;
    int endloc = temp.find("&quot;", beginloc);

    target = temp.substr(beginloc, endloc - beginloc);


}

void GoToComm::print(){
    cout << stype << ":  target="<< target << endl;
}
