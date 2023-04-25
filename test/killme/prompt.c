#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	char *line = NULL;
	size_t buffersize = 0;
	//char *word = NULL;
	int n = 1;
	char **args = malloc(sizeof(char *));
	int i;

	pid_t pid;

	if (args == NULL) {
		perror("malloc failed");
		return (1);
	}

	printf("$ ");
	if (getline(&line, &buffersize, stdin) == -1){
		printf("ERROR");
		return (1);
	}
	printf("%s", line);
	args[n-1] = strtok(line, " ");
	while (args[n-1] != NULL)
	{
		printf("%s\n", args[n-1]);
		args = realloc(args, ++n);
		args[n-1] = strtok(NULL, " ");
	}
	for (i = 0; i < n; i++)
	{
		printf("arr[%d]: %s\n", i, args[i]);
	}

	/*Exercise: fork + wait + execve*/
	for (i = 0; i < 5; i++) {
		pid = fork(); // create a new child process
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

	free(args);
	free(line);
	return (0);
}
