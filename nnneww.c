#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
        int i;
        pid_t child_pid;
        char *input;
        size_t input_size = 10;
        int input_lenght;
        char **argv;


        while (1)
        {
                child_pid = fork();
                if(child_pid != 0)
                {
                        wait(NULL);
                }
                if ( child_pid == -1)
                {
                        perror("fork");
                        return 1;
                }
                else if ( child_pid == 0)
                {

                        argv = (char **)malloc(input_size * sizeof(char *));
                        input =  (char *) malloc(input_size);
                        printf("#cisfun$ ");
                        input_lenght = getline(&input, &input_size , stdin);
                //      if(input_lenght != '\0'){}
                        if(input_lenght == EOF){printf("\n");break;exit(1);input = NULL;}
                        char *d = " ";
                        int i = 0;
                        char *separator = strtok(input, d);

                        while ( separator != NULL)
                        {
                                size_t token_length = strlen(separator);
                                if (token_length > 0 && separator[token_length - 1] == '\n')
                                {
                                        separator[token_length - 1] = '\0';
                                }
                                argv[i] =strdup(separator);
                                i++;
                                separator = strtok(NULL, d);

                        }
                        argv[i] = NULL;
                        if (execve(argv[0], argv, NULL) == -1)
                        {
                                perror("./shell");
                                exit(1);
                        }
                }

//              wait(NULL);
        }
}
