#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#define MAX_CMD_LENGTH 256
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments to be passed
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	char cmd[MAX_CMD_LENGTH];
	int status;
	pid_t pid;
	pid_t waitpid(pid_t pid, int *wstatus, int options);
	int execve(const char *pathname, char *const argv[], char *const envp[]);
	extern char **environ;

	while (1)
	{
		printf("$ ");

		if (fgets(cmd, MAX_CMD_LENGTH, stdin) == NULL)
		{

			printf("\n");
			exit(EXIT_SUCCESS);
		}

		cmd[strcspn(cmd, "\n")] = '\0';

		pid = fork();

		if (pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			char *args[] = {cmd, NULL};

			execve(cmd, args, environ);
			perror(cmd);
			exit(EXIT_FAILURE);
		}
		else
		{
			do {
				waitpid(pid, &status, WUNTRACED);
			}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
	return (0);
}
