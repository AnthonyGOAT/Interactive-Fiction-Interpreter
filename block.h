#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <string>
#include <iostream>
#include <vector>
#include "part.h"
#include "story.h"
#include "set.h"
#include "text.h"
#include "link.h"
#include "ifcomm.h"
#include "elsecomm.h"
#include "elseifcomm.h"
#include "gotocomm.h"

class Block : public Part{

    private:
    vector<Part*> blockComponents;

    public:

    Block(PartToken& in);
    virtual void print();
    virtual string play(Story& theStory, vector<Part*>& vec);
    virtual void play(){}
    virtual part_t getType(){return type;}
    virtual string getVariable() const {return "";}
    virtual bool getValue() const {return true;}
    virtual bool getCondition() const {return true;}
    virtual void setCondition(bool in){}
    virtual string getDisplay() const{return "";}
    virtual string getTarget() const{return "";}
};


#endif
