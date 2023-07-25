#include "main.h"

/**
 * _strcat - joins two strings together
 * @dest: destination string
 * @src: source string
 * Return: pointer
 */
char  *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	while (*dest)
		dest++;

	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';

	return (ptr);
}
