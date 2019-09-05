#include "IFInterpreter.h"
#include <fstream>
using namespace std;

IFInterpreter::IFInterpreter(string fn){
  fname = fn;
  string line, text;
  ifstream in(fname);

  //Read in the story from input.txt
  getline(in, line);
  while (in && line != "</html>")
  {
    text += line + '\n';
    getline(in, line);
  }

  //Construct the Story object
  activeStory = Story(text);
}

void IFInterpreter::print(){
  //invoke the story's print function
  activeStory.print();
}

void IFInterpreter::play(){
  //invoke the story's play function
  activeStory.play();
}
