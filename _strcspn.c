#include "main.h"

/**
 * _strcspn - removes a char from string
 * @str: string arg
 * @rem: char to remove
 * Return: number of data type size_t
 */
size_t _strcspn(const char *str, const char *rem)
{
	const char *ptr;
	size_t i = 0;

	while (*str)
	{
		ptr = rem;

		while (*ptr)
		{
			if (*str == *ptr)
				return (i);
			ptr++;
		}
		i++;
		str++;
	}

	return (i);
}

