#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headers.h"

char** space_organizer(char *string, const char *delim, int len)
{
	char *temp = malloc(sizeof(char) * len), *token, **arguments;
	int i = 0;

	temp = _strncpy(temp, string, len);
	token = strtok(temp, delim);

	while (token != NULL)
	{
		token = strtok(NULL, delim);
		i++;
	}

	free(temp);
	arguments = malloc(sizeof(char*) * (i + 1));
	i = 0;
	arguments[i] = strtok(string, delim);

	while (arguments[i] != NULL)
	{
		i++;
		arguments[i] = strtok(NULL, delim);
	}
	return (arguments);
}
