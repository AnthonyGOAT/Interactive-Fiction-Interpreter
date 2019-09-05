#include <string>
#include "passagetokenizer.h"
using namespace std;

bool PassageTokenizer::hasNextPart() const{
  if(psText!="\0") return true;
  else return false;
}

PartToken PassageTokenizer::nextPart(){
  string link, cmdgoto, cmdset, cmdif, cmdelseif, cmdelse, block, text;
  size_t foundLink = psText.find("[[");
  if(psText[foundLink+2]=='[')  foundLink=foundLink+1;
  size_t firstFound= foundLink;
  if(foundLink!=string::npos){
    size_t found = psText.find("]]",foundLink);
    if(found!= string::npos){
      link = psText.substr(foundLink,found+1-foundLink+1);
    }
    if(foundLink==0){
      psText = psText.substr(found+2);
      previousPart = LINK;
      return PartToken(link,LINK);
    }
  }
  size_t foundSet = psText.find("(set:");
  if(firstFound>foundSet) firstFound=foundSet;
  if(foundSet!=string::npos){
    size_t found = psText.find(")",foundSet);
    if(found!=string::npos){
      cmdset=psText.substr(foundSet,found-foundSet+1);
    }
    if(foundSet==0){
      psText = psText.substr(found+1);
      previousPart = SET;
      return PartToken(cmdset,SET);
    }
  }
  size_t foundGoto = psText.find("(go-to:");
  if(firstFound>foundGoto) firstFound=foundGoto;
  if(foundGoto!=string::npos){
    size_t found = psText.find(")",foundGoto);
    if(found!=string::npos){
      cmdgoto=psText.substr(foundGoto,found-foundGoto+1);
    }
    if(foundGoto==0){
      psText = psText.substr(found+1);
      previousPart = GOTO;
      return PartToken(cmdgoto,GOTO);
    }
  }
  size_t foundIf = psText.find("(if:");
  if(firstFound>foundIf) firstFound=foundIf;
  if(foundIf!=string::npos){
    size_t found = psText.find(")",foundIf);
    if(found!=string::npos){
      cmdif=psText.substr(foundIf,found-foundIf+1);
    }
    if(foundIf==0){
      psText = psText.substr(found+1);
      previousPart = IF;
      return PartToken(cmdif,IF);
    }
  }
  size_t foundElse = psText.find("(else:");
  if(firstFound>foundElse) firstFound=foundElse;
  if(foundElse!=string::npos){
    size_t found = psText.find(")",foundElse);
    if(found!=string::npos){
      cmdelse=psText.substr(foundElse,found-foundElse+1);
    }
    if(foundElse==0){
      psText = psText.substr(found+1);
      previousPart = ELSE;
      return PartToken(cmdelse,ELSE);
    }
  }
  size_t foundElseif = psText.find("(else-if:");
  if(firstFound>foundElseif) firstFound=foundElseif;
  if(foundElseif!=string::npos){
    size_t found = psText.find(")",foundElseif);
    if(found!=string::npos){
      cmdelseif=psText.substr(foundElseif,found-foundElseif+1);
    }
    if(foundElseif==0){
      psText = psText.substr(found+1);
      previousPart = ELSEIF;
      return PartToken(cmdelseif,ELSEIF);
    }
  }

  if(previousPart != IF && previousPart != ELSE && previousPart != ELSEIF){
    if(firstFound==string::npos){
      text = psText;
      psText ="\0";
    }
    else{
      text= psText.substr(0,firstFound);
      psText= psText.substr(firstFound);
    }
    previousPart=TEXT;
    return PartToken(text,TEXT);
  }
  else{
    size_t foundBlock = psText.find("[");
    int i;
    int timesFound =1;
    for(i=foundBlock+1;timesFound!=0;i++){
      if(psText[i]=='[')  timesFound++;
      if(psText[i]==']')  timesFound--;
    }
    size_t foundBlockEnd= i;
    block=psText.substr(foundBlock, foundBlockEnd-foundBlock);
    psText=psText.substr(foundBlockEnd);
    previousPart=BLOCK;
    return PartToken(block,BLOCK);
  }
}

string PartToken::getText() const{
  return part;
}

part_t PartToken::getType() const{
  return type;
}
