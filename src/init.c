#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/wait.h>


#include "init.h"
#include "userdata.h"



// extern from userdata.h
char* User;
char CWD[MAX_INPUT];



void InitTermianal()
{
  printf("\033[H\033[2J"); //clears screen and puts cursor on top

  User = getenv("USER");
  

  if (getcwd(CWD, MAX_INPUT) == nullptr)
  {
    perror("Vx: Cannot access the the Current Directory");
    perror("\n    Exiting with the code 1");
    exit(1);
  }

}

void PrintPrompt()
{

    

  if (getcwd(CWD, MAX_INPUT) == nullptr)
  {
    perror("Vx: Cannot access the the Current Directory");
    perror("\n    Exiting with the code 1");
    exit(1);
  }


  printf("\n\033[34m%s\033[0m&\033[34mVx\033[0m::\n::\033[32m", User);

  for (int i = 0; CWD[i] != '\0'; i++)
  {

    if (CWD[i] == '/')
    {
      printf("\033[0m/\033[32m");
      continue;
    }


    printf("%c", CWD[i]);
  }
  printf("\033[0m->");
  fflush(stdout);
  
}

void ReadInput(char* Input, int Length)
{
  if (fgets(Input, Length, stdin) == nullptr)
  {
    perror("\nVx: Interrupt, exited with error code 1");
    exit(1);
  }
  
}

