#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
/**
 * main - fork system call
 * Return: Always 0.
 */
int main(void)
{
	pid_t pid;
	pid_t ppid;

	pid = fork();

	fork();

	if (pid == -1)
	{
		perror("unsuccessful\n");
		return (1);
	}

	if (pid == 0)
	{
		sleep(40);
		printf("i am the child\n");
	}
	else
	{
		ppid = getppid();
		printf("parent pid is %u\n", ppid);
	}
	return (0);
}
