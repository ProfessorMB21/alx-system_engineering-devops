#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * endless_while - Run an indefinite while loop
 *
 * Return: 0
 */
int endless_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - Program entry point
 * Creates five zombie processes
 *
 * Return: 0
 */
int main(void)
{
	pid_t pid;
	char count = 0;

	while (count < 5)
	{
		pid = fork();
		if (pid > 0)
		{
			printf("Zombie process created, PID: %d\n", pid);
			sleep(1);
			count++;
		} else
			exit(0);
	}
	endless_while();

	return (EXIT_SUCCESS);
}

