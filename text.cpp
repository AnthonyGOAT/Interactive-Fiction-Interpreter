#include "text.h"
using namespace std;

Text::Text(PartToken& in){

    type = in.getType();
    stype = "Text";
    text = in.getText();
}

void Text::print(){
    cout << "\""<<text<<"\""<<endl;
}

void Text::play(){
    cout<<text;
}
