#ifndef SHELL_H
#define SEHLL_H

#define MAX_COMMAND_LENGTH 100
#define MAX_NUMBER_OF_PARAMS 10


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

extern char **environ;

struct builtin
{
    char *name;
    void (*func)(char **args);
};


char *read_line();
char **split_line(char *line);
char *get_path_buff_size(char *file);
char *find_path(char* file, char *buff);
int execute(char **args);
char *_getline();
void runfile(char *file, char *line, char **tokens);

void _myexit(char **args);
void _mycd(char **args);
int num_builtins(void);

int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strchr(char *s, char c);
char *_memcpy(char *dest, char *src, unsigned int n);
int _atoi(char *s);




#endif
