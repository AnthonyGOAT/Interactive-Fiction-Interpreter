#ifndef __TEXT_H__
#define __TEXT_H__

#include <string>
#include <iostream>
#include <sstream>
#include "part.h"

class Text : public Part{

    public:

    Text(PartToken& in);

    virtual void print();

    virtual void play();

};


#endif
