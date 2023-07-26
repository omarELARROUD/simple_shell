#include "main.h"

/**
 * _strcpy - copies one string to another
 * @dest: string to be overwritten
 * @src: source string
 * Return: pointer to string
 */
char  *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';

	return (ptr);
}

