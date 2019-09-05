#ifndef __ELSEIFCOMM_H__
#define __ELSEIFCOMM_H__

#include <string>
#include <iostream>
#include <sstream>
#include "part.h"

class ElseIfComm : public Part{

    private:
     string variable;
     bool value;
     bool isTrue;

    public:

    ElseIfComm(PartToken& in);

    virtual void print();

    virtual string getVariable() const { return variable;}
    virtual bool getValue() const { return value;}
    virtual bool getCondition() const {return isTrue;}

    virtual void setCondition(bool in) { isTrue = in;}

};


#endif
