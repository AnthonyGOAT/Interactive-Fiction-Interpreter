#ifndef __SET_H__
#define __SET_H__

#include <string>
#include <iostream>
#include <sstream>
#include "part.h"

class Set : public Part{

    private:
     string variable;
     bool value;

    public:

    Set(PartToken& in);

    virtual string getVariable() const {return variable;}
    virtual bool getValue() const { return value;}

    virtual void print();

};


#endif
