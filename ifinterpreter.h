#ifndef __IFINTERPRETER_H__
#define __IFINTERPRETER_H__
#include <string>
#include "story.h"

class IFInterpreter{
private:
  string fname;
  Story activeStory;
public:
  IFInterpreter(string fn);
  void print();
  void play();
};

#endif
