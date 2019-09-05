#include "set.h"
using namespace std;

Set::Set(PartToken& in){

    type = in.getType();
    stype = "Set";

    istringstream iss(in.getText());
    iss.ignore(10, ':');
    iss >> variable;

    string temp;
    iss >> temp; //temp should now be "to"
    if(temp == "to")
    iss >> temp; //temp should now be true or false

    if(temp.find("true") != string::npos)
        value = true;
    else
        value = false;
}

void Set::print(){
    cout<<boolalpha;
    cout << stype << ":  var= "<< variable <<", value= "<< value << endl;
    cout<<boolalpha;
}
