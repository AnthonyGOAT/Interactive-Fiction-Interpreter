#include <string>
#include "storytokenizer.h"
using namespace std;

string PassageToken::getName() const{
  string name;
  size_t found = passage.find("name=");
  if(found != string::npos){
    size_t found_2 = passage.find("\"",found+5);
    size_t found_3 = passage.find("\"",found_2+1);
    name = passage.substr(found_2+1, found_3 - found_2-1);
    return name;
  }
  else return "";
}

string PassageToken::getText() const{
  string text;
  size_t found = passage.find(">");
  if(found != string::npos){
    size_t found_2 = passage.find("</tw-passagedata>");
    text = passage.substr(found+1, found_2 - found-1);
    return text;
  }
  else return "";
}

bool StoryTokenizer::hasNextPassage() const{
  size_t found = story.find("<tw-passagedata");
  if(found != string::npos) return true;
  else return false;
}

PassageToken StoryTokenizer::nextPassage(){
  string temp;
  size_t found = story.find("<tw-passagedata");
  size_t found_2 = story.find("</tw-passagedata>");
  temp = story.substr(found,found_2+17-found);
  story = story.substr(found_2+17);
  return PassageToken(temp);
}
