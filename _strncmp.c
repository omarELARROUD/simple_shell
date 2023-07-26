#include "main.h"

/**
 * _strncmp - compares 'n' bytes between two strings
 * @str1: string 1
 * @str2: string 2
 * @n: number of bytes
 *
 * Return: difference between str1 & str2 or 0
 */
int _strncmp(char *str1, char *str2, int n)
{
	int i = 0;

	while (i < n && str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
