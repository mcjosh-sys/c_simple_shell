#include "shell.h"

/**
* struct builtin - contains the list of builting commands
*/
struct builtin builtins[] = {
	{"exit", _myexit},
	{"cd", _mycd},
	};

/**
* num_builtins - returns the number of builtin functions
* Return: no of builtins
*/

int num_builtins(void)
{
	return (sizeof(builtins) / sizeof(struct builtin));
}

/**
* split_line - split thr input string into an array of individual tokens
* @line: input string
* Return: returns tokens
*/
char **split_line(char *line)
{
	int len = 0;
	int buffsize = 16;
	char **tokens = malloc(buffsize * sizeof(char *));
	char *delim = " \t\r\n";
	char *token =  strtok(line, delim);

	while (token != NULL)
	{
		tokens[len] = token;
		len++;

		if (len >= buffsize)
		{
			buffsize = (int) (buffsize * 1.5);
			tokens = realloc(tokens, buffsize * sizeof(char *));
		}
		token = strtok(NULL, delim);
	}
	tokens[len] = NULL;
	return (tokens);
}
/**
* get_path_buff_size - gets the buffer size of path
* @file: input file
* Return: buffer size
*/
char *get_path_buff_size(char *file)
{
	char *path = getenv("PATH");
	size_t pathlen = strlen(path);
	size_t len = strlen(file);
	int max_len = pathlen + len;
	char *buff = malloc(sizeof(char) * max_len);

	if (path == NULL)
		return (NULL);
	return (buff);
}

/**
* find_path - finds the absolute path of a cmd
* @file: input cmd
* @buff: buffer size of path
* Return: path
*/
char *find_path(char *file, char *buff)
{
	char *path = getenv("PATH");
	char *name, *p;
	size_t pathlen = strlen(path);
	size_t len = strlen(file);

	if (path == NULL)
		return (NULL);
	if (*file == '\0')
		return (NULL);

	name = _memcpy(buff + pathlen + 1, file, len);
	*--name = '/';
	p = path;
	do {
		char *startp;

		path = p;
		p = _strchr(path, ':');
		if (!p)
			p = _strchr(path, '\0');
		if (p == path)
			startp = name + 1;
		else
			startp = _memcpy(name - (p - path), path, p - path);
		if (!access(startp, X_OK))
			return (startp);
	} while (*p++ != '\0');

	return (NULL);
}

/**
 * execute - executes commands
 * @args: arguments
 * Return: 1 if error encountered 0 otherwise
 */
int execute(char **args)
{
	pid_t child_pid;
	int i;

	for (i = 0; i < num_builtins(); i++)
	{
		if (_strcmp(args[0], builtins[i].name) == 0)
		{
			builtins[i].func(args);
			return (0);
		}
	}

	child_pid = fork();
	if (child_pid == 0)
	{
		execve(args[0], args, environ);
		perror(args[0]);
		exit(1);
	}
	else if (child_pid > 0)
	{
		int child_status;

		do {
			waitpid(child_pid, &child_status, WUNTRACED);
		} while (!WIFEXITED(child_status) && !WIFSIGNALED(child_status));
	}
	else
	{
		perror("$");
	}
	return (0);
}

