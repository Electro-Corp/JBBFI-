#include <iostream>
#include <iterator>
#include <string>
#include <regex>
char* rawDataTypes[3] = {"int","float","double"};

char* buffer;
struct opcode{
  char type;
  char* code;
  char value;
};
void usage();
int main(int args, char** argv){
  FILE* fp = fopen(argv[1],"r");
  if(!fp){
    usage();
  }
  fseek(fp, 0L, SEEK_END);
  int s = ftell(fp);
  buffer = (char*)malloc(sizeof(char)*ftell(fp));
  rewind(fp);
  fread(buffer,sizeof(char)*s,1,fp);
  int pos = 0, c = 0;
  // start parsing, we do a quick pass for dayouttatypes
  while(1){
    c = 0; // theres a more optimized way to to this, but for right now imma not do it. 
    char line[256];
    // parse until ";"
    line[c++] = buffer[pos];
    while(buffer[pos++] != ';'){
        line[c++] = buffer[pos];
    }
    std::string strline = line;
    std::cout << strline << "\n";
    // parse the line
    struct opcode tmp = {'0',"noop",'3'};
    // FOR THE basic data types
    for(int i = 0; i < sizeof(rawDataTypes)/sizeof(rawDataTypes[0]); i++){
      if(std::regex_search(strline,std::regex(rawDataTypes[i]))){
        tmp.type = rawDataTypes[i][0];
        tmp.code = "const";
      }else{
        
      }
    }
    printf("%c%s\n",tmp.type,tmp.code);
    
    if(!buffer[pos])break;
  }
}

void usage(){
  printf("Java But Better Compiler\n");
  printf("USAGE:\n");
  printf("./jbb [filename] [flags]\n");
  printf("Flags:\n");
  exit(1);
}