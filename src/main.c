#include "init.h"
#include "process_n_execute.h"
#include "definitions.h"
#include "input.h"

#include <stdlib.h>
#include <string.h>

int main()
{
  char Input[MAX_INPUT];
  InitTermianal();
  while(true)
  { 
    PrintPrompt();
    if (ReadInput(Input, MAX_INPUT) == EXIT_FAILURE)
      continue;
    Parse(Input);
    Execute();
  }
}