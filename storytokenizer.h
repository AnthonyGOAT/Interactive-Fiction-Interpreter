#ifndef __STORYTOKENIZER_H__
#define __STORYTOKENIZER_H__
#include <string>
#include "passagetokenizer.h"
using namespace std;

class PassageToken{
private:
  string passage;
public:
  PassageToken(string passage){this->passage = passage;}
  string getName() const;
  string getText() const;
};


class StoryTokenizer{
private:
  string story;
public:
  StoryTokenizer(string story){this->story = story;}
  bool hasNextPassage() const;
  PassageToken nextPassage();
};

#endif
