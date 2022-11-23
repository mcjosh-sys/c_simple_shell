#include "shell.h"

/**
* _myexit - exits the shell
* @args: arguement
*/
void _myexit(char **args)
{
	if (args[1])
		exit(_atoi(args[1]));
	exit(0);
}

/**
* _mycd - chenges directory
* @args: arguement
*/
void _mycd(char **args)
{
	if (args[1] == NULL)
		fprintf(stderr, "cd: missing argument\n");
	else
		if (chdir(args[1]) != 0)
			perror("cd");
}
