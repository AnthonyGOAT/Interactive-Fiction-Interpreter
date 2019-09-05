#ifndef __ELSECOMM_H__
#define __ELSECOMM_H__

#include <string>
#include <iostream>
#include <sstream>
#include "part.h"

class ElseComm : public Part{

    public:

    ElseComm(PartToken& in);
    virtual void print();
};


#endif
