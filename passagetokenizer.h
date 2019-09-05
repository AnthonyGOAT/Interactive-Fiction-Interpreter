#ifndef __PASSAGETOKENIZER_H__
#define __PASSAGETOKENIZER_H__
#include <string>
using namespace std;
enum part_t{LINK, GOTO, SET, IF, ELSEIF, ELSE, BLOCK, TEXT};


class PartToken{
private:
  string part;
  part_t type;
public:
  PartToken(string part,part_t type){this->part = part; this->type=type;}
  PartToken(const PartToken &in) {this->part = in.getText(); this->type=in.getType();}
  PartToken(const PartToken &&in) {this->part = part; this->type=type;}
  string getText() const;
  part_t getType() const;
};

class PassageTokenizer{
private:
  string psText;
  part_t previousPart;
public:
  PassageTokenizer(string text){this->psText = text;}
  bool hasNextPart() const;
  PartToken nextPart();
};


#endif
