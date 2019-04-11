#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

/**
 *
 *
 *
 *
 *
*/

int main(void)
{
	char *line = NULL, **arguments, *_exit = "exit";
	size_t len = 0;
	ssize_t readcount;
	int i;

	printf("$ ");
	while ((readcount = getline(&line, &len, stdin)) != EOF)
	{
		if (line && *line != *_exit)
		{
			arguments = space_organizer(line, " \t\r\n\f\v", len);
			i = 0;

			while (arguments[i] != NULL)
			{
				printf("%s\n", arguments[i]);
				i++;
			}
			printf("$ ");
		}
		else if (*line == *_exit)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			printf("Error, unable to allocate buffer\n");
			exit(1);
		}
	}
	free(line);
	exit(EXIT_SUCCESS);
}
