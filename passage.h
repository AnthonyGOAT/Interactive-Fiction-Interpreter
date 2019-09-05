#ifndef __PASSAGE_H__
#define __PASSAGE_H__
#include <string>
#include <unordered_map>
#include <vector>
#include "part.h"
#include "set.h"
#include "text.h"
#include "link.h"
#include "ifcomm.h"
#include "elsecomm.h"
#include "elseifcomm.h"
#include "gotocomm.h"
#include "block.h"
#include "storytokenizer.h"
#include "passagetokenizer.h"

class Story;
class Passage{
private:
  string name;
  string text;
  vector<Part*> partL;

public:
  Passage();
  Passage(PassageToken& ptok);
  string getName();
  void print();
  string play(Story& theStory);
};

#endif
