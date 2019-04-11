#include "headers.h"

/**
 * _strncpy - return the copie of one string in another
 * @dest: destiny
 * @src:source
 * @n: limit
 * Return: a string copy
*/

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
