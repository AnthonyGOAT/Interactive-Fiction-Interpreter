#include "block.h"
using namespace std;

Block::Block(PartToken& in){

        type = in.getType();
        stype = "Block";
        text = in.getText().substr(1 , in.getText().length()-2);

        PassageTokenizer pt(text);

        while (pt.hasNextPart())
        {
            PartToken* a = new PartToken(pt.nextPart());

            switch (a->getType())
            {
                case SET:
                {
                    Set* mySet = new Set(*a);
                    blockComponents.push_back(mySet);
                }
                    break;
                case TEXT:
                {
                    Text* myText = new Text(*a);
                    blockComponents.push_back(myText);
                }
                    break;
                case LINK:
                {
                    Link* myLink = new Link(*a);
                    blockComponents.push_back(myLink);
                }
                    break;
                case IF:
                {
                    IfComm* myIf = new IfComm(*a);
                    blockComponents.push_back(myIf);
                }
                    break;
                case ELSE:
                {
                    ElseComm* myIf = new ElseComm(*a);
                    blockComponents.push_back(myIf);
                }
                    break;
                case ELSEIF:
                {
                    ElseIfComm* myElseIf = new ElseIfComm(*a);
                    blockComponents.push_back(myElseIf);
                }
                    break;
                case GOTO:
                {
                    GoToComm* myGoTo = new GoToComm(*a);
                    blockComponents.push_back(myGoTo);
                }
                    break;
                case BLOCK:
                {
                    Block* myBlock = new Block(*a);
                    blockComponents.push_back(myBlock);
                }
                    break;


                default:
                {
                    Part* myPart = new Part(*a);
                    blockComponents.push_back(myPart);
                }
                    break;

            }

            delete a;

        }
    }

void Block::print(){
  cout <<"START BLOCK"<<endl;

  for(auto a : blockComponents)
  a->print();

  cout<<"END BLOCK"<<endl;
}


string Block::play(Story& theStory,vector<Part*> &vec){
  int lastIf;
  string blockReturn;
  for(int i=0;i<blockComponents.size();i++){
    switch(blockComponents[i]->getType()){
      case LINK:  vec.push_back(blockComponents[i]);
                  cout<<blockComponents[i]->getDisplay();
                  break;

      case IF:    lastIf = i;
                  if(theStory.getVariable(blockComponents[i]->getVariable()) != blockComponents[i]->getValue()){
                    blockComponents[i]->setCondition(false);
                    i++;
                  }
                  else blockComponents[i]->setCondition(true);
                  break;

      case ELSE:  for(int j=i-2; j>=lastIf; j = j-2){
                    if(blockComponents[j]->getCondition() == true){
                      i++;
                      break;
                    }
                  }
                  break;

      case GOTO:  return blockComponents[i]->getTarget();

      case SET:   theStory.modifyVariable(blockComponents[i]->getVariable(),blockComponents[i]->getValue());
                  break;

      case ELSEIF:blockComponents[i]->setCondition(true);
                  for(int j=i-2;j>=lastIf; j=j-2){
                    if(blockComponents[j]->getCondition() == true){
                      blockComponents[i]->setCondition(false);
                      i++;
                      break;
                    }
                  }
                  if(blockComponents[i]->getCondition() == true){
                    if(theStory.getVariable(blockComponents[i]->getVariable()) != blockComponents[i]->getValue()){
                      blockComponents[i]->setCondition(false);
                      i++;
                    }
                  }
                  break;

      case BLOCK: blockReturn = blockComponents[i]->play(theStory,vec);
                  if(blockReturn != "") return blockReturn;
                  break;

      case TEXT:  blockComponents[i]->play();
                  break;
    }
  }
  return "";
}
