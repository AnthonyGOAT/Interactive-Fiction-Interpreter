#ifndef __STORY_H__
#define __STORY_H__
#include <string>
#include <unordered_map>
#include <vector>
#include "passage.h"
#include "storytokenizer.h"


class Passage;
class Story{
private:
  string text;
  vector<Passage>  passageL;
  unordered_map<string, bool> variableList;
  unordered_map<string, Passage*> passageList;
public:
  Story();
  Story(string& text);
  void print();
  void play();
  void modifyVariable(string name, bool condition);
  bool getVariable(string name);
};
#endif
