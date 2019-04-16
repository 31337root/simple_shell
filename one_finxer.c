#include "headers.h"

#define UNUSED(x) (void)(x)

/**
 * one_finxer - function to find and execute the requested program.
 * @arguments: Arrays of pointers where find the program arguments to execute.
 * @path: Path where the program to execute is.
 * @size0: Size of array (arguments).
 * @size1: Size of array (path).
 * Return: (0) Succes, the path was found and the program executed.
 */

int one_finxer(char **arguments, char **path, int size0, int size1)
{
	char *pathfile = NULL, _cwd[1024];
	int result = 0, i = 0;

	UNUSED(pathfile);
	UNUSED(result);
	getcwd(_cwd, sizeof(_cwd));

	while (path && path[i] && arguments && size0 != 0 && size1 != 0)
	{
		if ((chdir(path[i])) < 0)
			return (-1);

		if ((access(arguments[0], F_OK)) == 0)
		{
			pathfile = _strcat(arguments[0], path[i]);
			if (pathfile)
			{
				if ((chdir(_cwd)) < 0)
					return (-1);
				result = executor(arguments, pathfile, size0);

				if (result < 0)
				{
					return (-1);
				}
				else
				{
					free(pathfile);
					return (0);
				}
			}
		}
		i++;
	}
	if ((chdir(_cwd)) < 0)
		return (-1);

	free(pathfile);
	printf("ourshell: %d: %s: not found\n", errno, arguments[0]);
	return (-1);
}
