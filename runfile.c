#include "shell.h"

/**
* runfile - runs commands from a file
* @file: input file
* @line: single line from file
* @tokens: tokens
*/

void runfile(char *file, char *line, char **tokens)
{
	FILE *fp;
	ssize_t read;
	size_t len = 0;
	char *temp = NULL;
	char *buf = NULL;

	fp = fopen(file, "r");
	if (fp == NULL)
		exit(1);
	while ((read = getline(&line, &len, fp)) != -1)
	{
		tokens = split_line(line);
		if (tokens[0] != NULL)
		{
			if (!_strchr(tokens[0], '/'))
			{
				buf = get_path_buff_size(tokens[0]);
				temp = find_path(tokens[0], buf);
				if (temp)
					tokens[0] = temp;
			}
			execute(tokens);
		}
	}
	fclose(fp);
	if (line)
		free(line);
	if (tokens)
		free(tokens);
}
