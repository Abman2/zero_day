#include <string.h>
#include <unistd.h>
#include <stdlib.h>




int  main() {
        printf("$ ");

        char *input;
        size_t input_size = 10;
        int input_lenght;

        input =  (char *) malloc(input_size);

        input_lenght = getline(&input, &input_size , stdin);

        puts(input);

        char *d = " ";

        char *seprator = strtok(input, d);
        while ( seprator != NULL)
        {
                printf("%s\n", seprator);
                seprator = strtok(NULL, d);
        }

   return 0;
}
