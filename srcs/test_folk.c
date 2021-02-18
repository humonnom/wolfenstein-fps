#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int pid;
	int i;

	pid = -1;
	pid = fork();
	if (pid == 0)
	{
		i = 0;
		while (i < 2)
		{
			i++;
			printf("child...(pid:%d)\n", getpid());
		}
	}
	if (pid > 0)
	{
		i = 0;
		while (i < 2)
		{
			i++;
			printf("parents...(pid:%d)\n", getpid());
		}
		kill(getpid() + 1, SIGKILL);
		exit(0);
	}
	return (1);
}
