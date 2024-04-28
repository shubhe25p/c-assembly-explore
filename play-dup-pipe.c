#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
       
int main(int argc, char *argv[])
{
    int pipe0[2];
    int pipe1[2];
    int pipe2[2];

    pipe(pipe0);
    pipe(pipe1);
    pipe(pipe2);
    int c1pid = fork();
    if(c1pid==0){
        close(pipe0[1]);
        close(pipe1[0]);
        close(pipe2[0]);
        close(pipe2[1]);
        dup2(pipe0[0],0);
        dup2(pipe1[1],1);
        char buffer[9];
        read(0, buffer, strlen(argv[1]));
        buffer[8]='\0';
        char *argv[] = {"echo", buffer, NULL};
        execvp(argv[0], argv);
        close(pipe0[0]);
        close(pipe1[1]);
    }
    int c2pid=fork();
    if(c2pid==0){
        close(pipe0[0]);
        close(pipe0[1]);
        close(pipe1[1]);
        close(pipe2[0]);
        dup2(pipe1[0],0);
        dup2(pipe2[1],1);
        char buffer[9];
        read(0, buffer, strlen(argv[1]));
        buffer[8]='\0';
        char *argv[] = {"echo", buffer, NULL};
        execvp(argv[0], argv);
        close(pipe1[0]);
        close(pipe2[1]);
    }
    int c3pid=fork();
    if(c3pid==0){
        close(pipe0[0]);
        close(pipe0[1]);
        close(pipe1[1]);
        close(pipe1[0]);
        close(pipe2[1]);
        dup2(pipe2[0],0);
        char buffer[9];
        read(0, buffer, strlen(argv[1]));
        buffer[8]='\0';
        char *argv[] = {"cat", buffer, NULL};
        execvp(argv[0], argv);
        close(pipe2[0]);
    }
    else{
        close(pipe0[0]);
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);
        write(pipe0[1], argv[1], strlen(argv[1]));
        close(pipe0[1]);
    }

    waitpid(c1pid, NULL, 0); 
    waitpid(c2pid, NULL, 0);     
}