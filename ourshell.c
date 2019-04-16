#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

#define UNUSED(x) (void)(x)

/**
 * main - Entry point.
 * Description: Program to interpret adn execute programs defined of the $PATH.
 * @argc: UNUSED.
 * @argv: UNUSED.
 * @envp: environment of the executed current program.
 * Return: (EXIT_SUCCESS)
 */

int main(int argc, char **argv, char **envp)
{
	char *line = NULL, **aop, *_exit = "exit";
	size_t len = 0;
	ssize_t readcount;
	int strcount = 0;

	UNUSED(argc);
	UNUSED(argv);

	while ((readcount = getline(&line, &len, stdin)) != EOF)
	{
		if (line && (_strcmp(line, _exit)) != 0)
		{
			strcount = 0;
			aop = space_organizer(line, " \t\r\n\f\v", readcount, &strcount);
			if (aop[0] != NULL)
			{
				decision_taker(aop, strcount, envp);
			}
			else
				free(aop);
		}
		else if ((_strcmp(line, _exit)) == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("Error, unable to allocate buffer\n");
		}
	}
	free(line);
	exit(EXIT_SUCCESS);
}
