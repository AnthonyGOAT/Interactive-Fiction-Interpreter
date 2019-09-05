#include "story.h"
#include <iostream>
#include <vector>
using namespace std;

Story::Story(){
  text = "";
}
Story::Story(string& text){

  this->text = text;

  //create a storytokenizer object to break the story into passages
  StoryTokenizer st(text);


  while (st.hasNextPassage())
  {

    //Use the PassageToken to construct the passage vector and the passage unordered map
    PassageToken ptok = st.nextPassage();

    //insert the passage into the vector of passages
    passageL.emplace_back(Passage(ptok));

  }
  for(int i=0;i<passageL.size();i++){
    passageList[passageL[i].getName()] = &passageL[i];
  }
}

void Story::print(){
  //iterate through all the passages and invoke their print function
  for(int i=0; i< passageL.size(); i++){
    passageL[i].print();
  }
}
void Story::play(){
  //play the story by invoking the first passage's play function
  string nextPassage = passageList[passageL[0].getName()]->play(*this);
  while(nextPassage != ""){
    nextPassage = passageList[nextPassage]->play(*this);
  }
}

/*void Story::playPassage(string name){
  //play a specific passage by the requested name
  passageList[name]->play();
}*/

void Story::modifyVariable(string name, bool condition){
  //modify the valuable by name
  variableList[name] = condition;
}

bool Story::getVariable(string name){
  //get the value of the variable by name
  return variableList[name];
}
