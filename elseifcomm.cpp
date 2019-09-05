#include "elseifcomm.h"
using namespace std;

ElseIfComm::ElseIfComm(PartToken& in){

        type = in.getType();
        stype = "Else-If";

        istringstream iss(in.getText());
        iss.ignore(10, ':');
        iss >> variable;

        string temp;
        iss >> temp; //temp should now be "is"
        if(temp == "is")
        iss >> temp; //temp should now be true or false

        if(temp.find("true") != string::npos)
            value = true;
        else
            value = false;
}

void ElseIfComm::print(){
      cout<<boolalpha;
      cout << stype << ":  var= "<< variable <<", value= "<< value << endl;
      cout<<boolalpha;
}
