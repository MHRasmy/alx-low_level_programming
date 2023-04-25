#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char* args[] = {"ls", "-l", "/tmp", NULL}; // command to execute
    int i;
    for (i = 0; i < 5; i++) {
        pid_t pid = fork(); // create a new child process
        if (pid == 0) {
            // this is the child process
            printf("Child %d executing command...\n", i+1);
            execve("/bin/ls", args, NULL); // execute the command
            perror("execve"); // execve only returns if an error occurred
            exit(1); // exit with error
        } else if (pid < 0) {
            perror("fork"); // fork failed
            exit(1); // exit with error
        } else {
            // this is the parent process
            wait(NULL); // wait for child to finish
        }
    }
    printf("All child processes have finished.\n");
    return 0;
}

