#include "shell.h"
#include "helper.h"

void print_prompt() {
    printf("$ ");
    fflush(stdout);
}

void helper(char input[])
{
        int i=0;
        char **argv;
        argv = (char **)malloc(MAX_INPUT_SIZE * sizeof(char *));
        input[strlen(input) - 1] = '\0';
         if (strcmp(input, "exit") == 0)
         {
                  exit(0);
          }
        char *seprator = strtok(input, " ");
        while(seprator != NULL)
        {
                if(seprator[strlen(seprator)-1] == '\0')
                {
                        seprator[strlen(seprator) -1] =='\0';
                }
                argv[i] = strdup(seprator);
                i++;
                seprator = strtok(NULL, " ");
        }
        argv[i] = NULL;
        pid_t child_pid = fork();

        if (child_pid == -1)
        {
            perror("fork");
        }
        else if (child_pid == 0)
        {

                   if (execve(argv[0], argv, NULL) == -1)
                         {
                                 if(execvp(argv[0], argv) == -1)
                                 {
                                perror("./shell");
                                exit(1);
                        }


                perror("./shell");
                exit(EXIT_FAILURE);
            }
        }
        else {
            int status;
            if (wait(&status) == -1) {
                perror("wait");
            }
     }

}
