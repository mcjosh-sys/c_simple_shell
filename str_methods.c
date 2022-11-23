#include "shell.h"

/**
 * _strlen - Function to print string lenght
 * @s: Parameter for the string
 *
 * Return: the value i
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i])
	{
		i++;
	}
	return (i);
}

/**
 * _strcmp -  function to compare to strings and return
 * @s1: Parameter to pass string 1
 * @s2: Parameter to pass string 2
 *
 * Return: return the value
 */

int _strcmp(char *s1, char *s2)
{
	int val, i, l1, l2, lenght;

	for (l1 = 0; s1[l1] != '\0'; l1++)
	for (l2 = 0; s2[l2] != '\0'; l2++)

	if (l1 > l2)
		lenght = l1;
	else
		lenght = l2;

	for (i = 0; i < lenght; i++)
	{
		if (s1[i] != s2[i])
		{
			val = s1[i] - s2[i];
			break;
		}
		else
			val = 0;
	}
	return (val);
}

/**
 * _memcpy - Function to replace memory area with a constant
 * @dest: parameter of destination memory area
 * @n: parameter to hold number of bytes to alter
 * @src: parameter of source memory area
 *
 * Return: the copied values
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	int j;
	int i = n;

	/* { */
		for (j = 0; j < i; j++)
		{
			dest[j] = src[j];
		}
	/* } */
	return (dest);
}

/**
 * _strchr - locates a character in a string
 * @s: string parameter
 * @c: character parameter
 *
 * Return: the pointer to the first occurrence of the character c
 */

char *_strchr(char *s, char c)
{
	unsigned int j = 0;

	for (j = 0; s[j] != '\0'; j++)
		if (s[j] == c)
			return (s + j);
	if (s[j] == c)
		return (s + j);
	return ('\0');
}
