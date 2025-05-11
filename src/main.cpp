#include "init.h"
#include <stdio.h>
#include <string>
#include <vector>


int main()
{
  char Input[MAX_INPUT];
  std::vector<std::string> ParsedTokens;
  InitTermianal();
  while(true)
  {
    PrintPrompt();
    ReadInput(Input, MAX_INPUT);
    ParsedTokens = Parse(Input);
    for (std::string& ref: ParsedTokens)
      printf("%s ", ref.c_str());
  }
}