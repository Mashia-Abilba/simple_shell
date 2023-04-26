#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
/**
 * main - wait system call
 * Return: Always 0.
 */
int main(void)
{
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("unsuccessful\n");
		return (1);
	}
	if (pid == 0)
	{
		printf("child process\n");
	}
	else
	{
		sleep(30);
		printf("parent process\n");
	}

	return (0);
}
