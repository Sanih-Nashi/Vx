#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <vector>
#include <string>

#include "init.h"


void InitTermianal()
{
  write(STDOUT_FILENO, "\033[H\033[2J", 7); //clears screen and puts cursor on top

#ifdef __unix__
  User = getenv("USER");
#elif defined(WIN32) || defined(WIN64)
  User = getenv("USERNAME");
#endif


  if (getcwd(CWD, MAX_INPUT) == nullptr)
  {
    perror("Vx: Cannot access the the Current Directory");
    sleep(1);
    perror("\n    Exiting with the code 1");
    sleep(1);
    exit(1);
  }
}

void PrintPrompt()
{
//   printf(
//   "\n\033[38;2;128;250;52m \u0332 \u0332 \u0332 \u0332 \u0332 \u0332 \u0332 \u0332\033[32m%s\033[38;2;128;250;52m\u0332 \u0332 \u0332 \u0332 \u0332 \u0332 \u0332 \u0332 \033[0m:\033[32;1m%s\033[0m->", User, CWD
// );
  // printf("\n\033[38;2;128;250;52m%s\033[0m&\033[38;2;128;250;52mVx\033[0m::\n::\033[35m", User);
  printf("\n\033[34m%s\033[0m&\033[34mVx\033[0m::\n::\033[32m", User);

  for (int i = 0; CWD[i] != '\0'; i++)
  {

#ifdef __unix__
    if (CWD[i] == '/')
    {
      printf("\033[0m/\033[32m");
      continue;
    }


#elif defined(WIN32) || defined(WIN64)
    if (CWD[i] == '\\')
    {
      printf("\033[0m\\\033[35m");
      continue;
    }
#endif

    printf("%c", CWD[i]);
  }
  printf("\033[0m->");
  fflush(stdout);
  
}

void ReadInput(char* Input, const int& Length)
{
  if (fgets(Input, Length, stdin) == nullptr)
  {
    perror("\nVx: Interrupt, exited with error code 1");
    sleep(1);
    exit(1);
  }
  
}

std::vector<std::string> Parse(char* Input)
{    
  std::vector<std::string> ParsedTokens;
  char* token = strtok(Input, " ");
  while (token != NULL)
  {
    ParsedTokens.push_back(token);
    token = strtok(NULL, " ");
  }
  return ParsedTokens;
}