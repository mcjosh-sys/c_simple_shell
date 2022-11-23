#include "shell.h"

/**
 * _getline - reads a single line of input from stdin
 * Return: returns input string
 */
char *_getline()
{
	int buffsize = 1024;
	int position = 0;
	char *buffer = malloc(sizeof(char) * buffsize);
	int c;

	if (!buffer)
		exit(1);

	while (1)
	{
		c = getchar();
		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
			buffer[position] = c;

	position++;

	if (position >= buffsize)
	{
		buffsize += 1024;
		buffer = realloc(buffer, buffsize);
		if (!buffer)
		exit(1);
	}
	}
}
