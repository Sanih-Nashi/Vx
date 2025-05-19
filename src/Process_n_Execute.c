#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#include <sys/wait.h>
#include <unistd.h>


#include "Process_n_Execute.h"


char* argv[MAX_INPUT];
int argc;



void Parse(char* Input)
{
  Input[strcspn(Input, "\n")] = '\0';
    if (Input == NULL)
        return;

    argc = 0;
    argv[argc] = strtok(Input, " ");
    while (argv[argc] != NULL && argc < MAX_INPUT - 1)
    {
        argc++;
        argv[argc] = strtok(NULL, " ");
    }
    argv[argc] = NULL;
}

void Execute()
{

  if (argv[0] == NULL)
  return;

  else if (strcmp(argv[0], "exit") == 0)
    exit(1);

  else if (strcmp(argv[0], "cd") == 0)
  {

    if (argv[1] == NULL)
      fprintf(stderr, "Vx: NO file name mentioned for cd");

    else if (chdir(argv[1]) != 0)
      fprintf(stderr, "Vx: cannot cd into %s\n", argv[1]);
      
    return;

  }


  pid_t pid = fork();

  if (pid < 0)
    perror("Vx: Error, resource unavailable currently");

  else if (pid == 0) {

    execvp(argv[0], argv);

    char str[MAX_INPUT];
    sprintf(str, "Vx: %s", argv[0]);
    perror(str);
    exit(EXIT_FAILURE);
  } 
  else {
      // Parent process
      int status;
      waitpid(pid, &status, 0);
  }


}
