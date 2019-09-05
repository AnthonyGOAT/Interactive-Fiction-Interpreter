#include "passage.h"

#include <iostream>
using namespace std;

Passage::Passage(){
  name = "";
  text = "";
}
Passage::Passage(PassageToken& ptok){
  name = ptok.getName();
  text = ptok.getText();

  //create a passagetokenizer object to break the passage into parts
  PassageTokenizer ps(this->text);
  while(ps.hasNextPart())
  {
    PartToken tok = ps.nextPart();

    //constructed the vector of parts by the passageToken
    switch(tok.getType()){
        case LINK:  partL.emplace_back(new Link(tok));
                    break;
        case IF:    partL.emplace_back(new IfComm(tok));
                    break;
        case ELSE:  partL.emplace_back(new ElseComm(tok));
                    break;
        case GOTO:  partL.emplace_back(new GoToComm(tok));
                    break;
        case SET:   partL.emplace_back(new Set(tok));
                    break;
        case ELSEIF:partL.emplace_back(new ElseIfComm(tok));
                    break;
        case BLOCK: partL.emplace_back(new Block(tok));
                    break;
        case TEXT:  partL.emplace_back(new Text(tok));
                    break;
    }
  }
}

string Passage::getName(){
  return name;
}

void Passage::print(){
  cout<<"Passage "<< name<<":"<<endl;

  //iterate through the parts within a passage
  for(int i=0;i<partL.size();i++){
    partL[i]->print();
  }
}

string Passage::play(Story& theStory){
  int lastIf;
  string blockReturn;
  vector<Part*> vec;
  for(int i=0;i<partL.size();i++){
    switch(partL[i]->getType()){
      case LINK:  vec.push_back(partL[i]);
                  cout<<partL[i]->getDisplay();
                  break;

      case IF:    lastIf = i;
                  if(theStory.getVariable(partL[i]->getVariable()) != partL[i]->getValue()){
                    partL[i]->setCondition(false);
                    i++;
                  }
                  else partL[i]->setCondition(true);
                  break;

      case ELSE:  for(int j=i-2; j>=lastIf; j = j-2){
                    if(partL[j]->getCondition() == true){
                      i++;
                      break;
                    }
                  }
                  break;

      case GOTO:  return partL[i]->getTarget();

      case SET:   theStory.modifyVariable(partL[i]->getVariable(),partL[i]->getValue());
                  break;

      case ELSEIF:partL[i]->setCondition(true);
                  for(int j=i-2;j>=lastIf; j=j-2){
                    if(partL[j]->getCondition() == true){
                      partL[i]->setCondition(false);
                      i++;
                      break;
                    }
                  }
                  if(partL[i]->getCondition() == true){
                    if(theStory.getVariable(partL[i]->getVariable()) != partL[i]->getValue()){
                      partL[i]->setCondition(false);
                      i++;
                    }
                  }
                  break;

      case BLOCK: blockReturn = partL[i]->play(theStory,vec);
                  if(blockReturn != "") return blockReturn;
                  break;

      case TEXT:  partL[i]->play();
                  break;
    }
  }

  //if there is no link, stop playing the whole story by return an empty string
  if(vec.size() == 0)
    return "";

  cout<<endl;
  for(int j=0; j< vec.size();j++){
    cout << j+1 << ": " <<vec[j]->getDisplay()<<endl;
  }

  int decision;
  cout<<"Please select one option: ";
  cin>>decision;

  //return the user's choice of passge
  return vec[decision-1]->getTarget();
}
