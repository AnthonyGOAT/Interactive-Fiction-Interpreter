#ifndef __GOTOCOMM_H__
#define __GOTOCOMM_H__

#include <string>
#include <iostream>
#include <sstream>
#include "part.h"

class GoToComm : public Part{

    private:
     string target;

    public:

    GoToComm(PartToken& in);

    virtual void print();

    virtual string getTarget() const {return target;}

};


#endif
