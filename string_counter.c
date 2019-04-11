#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headers.h"

char** space_organizer(char *string)
{
	char *temp, *token, **arguments;
	const char *delim = " \t\r\n\f\v";
	int i = 0;

	for (; string[i]; i++)
		;
	temp = malloc(sizeof(char) * i);
	for (i = 0; string[i]; i++)
		temp[i] = string[i];
	i = 0;
	token = strtok(temp, delim);

	while (token != NULL)
	{
		token = strtok(NULL, delim);
		i++;
	}

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
