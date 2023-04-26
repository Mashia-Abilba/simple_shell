#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
/**
 * main - command line interpreter
 * Return: Always 0
 */
int main(void)
{
	char buffer[1024];
	pid_t pid = fork();

	while (1)
	{
		printf("$ ");
		if (!fgets(buffer, sizeof(buffer), stdin))
		{
			printf("\n");
			exit(0);
		}
		buffer[strlen(buffer) - 1] = '\0';

		if (pid == -1)
		{
			perror("fork");
			continue;
		}
		if (pid == 0)
		{
			if (execlp(buffer, buffer, NULL) == -1)
			{
				perror(buffer);
				exit(1);
			}
		exit(0);
		}
		if (waitpid(pid, NULL, 0) == -1)
		{
			perror("waitpid");
			exit(1);
		}
	}
	return (0);
}
