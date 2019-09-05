#ifndef __LINK_H__
#define __LINK_H__

#include <string>
#include <iostream>
#include <sstream>
#include "part.h"

class Link : public Part{

    private:
     string display;
     string target;

    public:

    Link(PartToken& in);

    virtual string getDisplay() const{ return display; }
    virtual string getTarget()  const{ return target; }

    virtual void print();

};


#endif
