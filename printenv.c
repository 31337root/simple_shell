#include "headers.h"

/**
 * printenv - Function to print the current program environment.
 * @envp: Pointers array where are stored all the environment variables.
 * Return - void.
 */

void printenv(char **envp)
{
	int i = 0;

	if (envp)
	{
		while (envp[i])
			printf("%s\n", envp[i++]);
		return;
	}
	perror("Unable to find envp.");
}
