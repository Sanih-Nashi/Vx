#include "init.h"
#include "Process_n_Execute.h"

int main()
{
  char Input[MAX_INPUT];
  InitTermianal();
  while(true)
  { 
    PrintPrompt();
    ReadInput(Input, MAX_INPUT);
    Parse(Input);
    Execute();
  }
}