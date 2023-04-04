#include <iostream>
#include <vector>
#include <cstdio>

template <typename gen>

class Jbbvm{
private:
public:
  //std::vector<std::string> opCodes;
  char** opcodes = {"const"};
  char* buffer;

  Jbbvm(char* fileName){
    FILE* fp = fopen(fileName,"r");
    fseek(fp, 0L, SEEK_END);
    int s = ftell(fp);
    buffer = (char*)malloc(sizeof(char)*ftell(fp));
    rewind(fp);
    fread(buffer,sizeof(char)*s,1,fp);
  }

  struct {
    char pre;
    char* type;
    <class T> goofy;
  } opcode;
  // void initOpCodes(){
  //   opCodes.push_back("const");
  // }

  
}