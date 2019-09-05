#include "elsecomm.h"
using namespace std;

ElseComm::ElseComm(PartToken& in){
  type = in.getType();
  stype = text = "Else";
}

void ElseComm::print(){
    cout<<text<<endl;
}
