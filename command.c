#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void)
{
	char buffer[1024];

	while (1)
	{
		printf("$ ");
		if (!fgets(buffer, sizeof(buffer), stdin))
		{
			printf("\n");
			exit(0);
		}
		buffer[strlen(buffer) - 1] = '\0';
		char *args[1024];
		int i = 0;
		char *token = strtok(buffer, " ");

		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[i] = NULL;
		pid_t pid = fork();

		if (pid == -1)

		{
			perror("fork");
			continue;
		}
		if (pid == 0)
		{
			if (execvp(args[0], args) == -1)
			{
				perror(args[0]);
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
