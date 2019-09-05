#include "part.h"
#include <iostream>


Part::Part(PartToken& in){

    type = in.getType();
    text = in.getText();

    switch(type){
        case 0:
            stype = "LINK";
            break;
        case 1:
            stype = "GOTO";
            break;
        case 2:
            stype = "SET";
            break;
        case 3:
            stype = "IF";
            break;
        case 4:
            stype = "ELSEIF";
            break;
        case 5:
            stype = "ELSE";
            break;
        case 6:
            stype = "BLOCK";
            break;
        case 7:
            stype = "TEXT";
            break;
        default:
            stype = "ERROR";
            break;
    }

}

void Part::print(){
    cout << stype << ": " << text << endl;
}
