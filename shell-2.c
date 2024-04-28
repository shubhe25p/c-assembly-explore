#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char* command = "cat";
    char* argument_list[] = {
        "cat",
        "length.c",
        NULL};

    printf("Before calling execvp()\n");

    printf("Creating another process using fork()...\n");

    if (fork() == 0) {
        // Newly spawned child Process. This will be taken over by "ls -l"
        int status_code = execvp(command, argument_list);

        printf("ls -l has taken control of this child process. This won't execute unless it terminates abnormally!\n");

        if (status_code == -1) {
            printf("Terminated Incorrectly\n");
            return 1;
        }
        else{
            exit(0);
        }
    }
    else {
        // Old Parent process. The C program will come here
        printf("This line will be printed\n");
    }

    return 0;
}