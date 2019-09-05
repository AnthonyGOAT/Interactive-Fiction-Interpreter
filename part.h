#ifndef __PART_H__
#define __PART_H__

#include <string>
#include <iostream>
#include <vector>
#include "passagetokenizer.h"


class Story;

class Part{

    protected:
        part_t type;
        string stype;
        string text;

    public:
        Part(){type = TEXT; stype = "DEFAULT"; text = "";}
        Part(PartToken& in);
        virtual void play(){}
        virtual string play(Story& theStory,vector<Part*>& vec){return "";}
        virtual void print();
        part_t getType(){return type;}
        virtual string getVariable() const {return "";}
        virtual bool getValue() const {return true;}
        virtual bool getCondition() const {return true;}
        virtual void setCondition(bool in){}
        virtual string getDisplay() const{return "";}
        virtual string getTarget() const{return "";}


};



#endif
