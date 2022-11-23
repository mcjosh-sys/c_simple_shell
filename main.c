#include "shell.h"

/**
 * main - executes shell loop
 * @argc: number of command line arguments
 * @argv: the program command line arguments
 * Return: exits with status 0
 */

int main(int argc, char *argv[])
{
	char *line = NULL;
	char **tokens = NULL;
	char *buff = NULL;
	char *tmp = NULL;

	if (argc == 2)
	{
		runfile(argv[1], line, tokens);
		exit(0);
	}
	while (1)
	{
		printf("$ ");
		line = _getline();
		tokens = split_line(line);

		if (tokens[0] != NULL)
		{
			if (!_strchr(tokens[0], '/'))
			{
				buff = get_path_buff_size(tokens[0]);
				tmp = find_path(tokens[0], buff);
				if (tmp)
					tokens[0] = tmp;
			}
			execute(tokens);
		}
		free(buff);
		free(tokens);
		free(line);
	}
	return (0);
}
