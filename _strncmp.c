#include "main.h"

int _strncmp(char *str1, char *str2, int n)
{
	int i = 0;

	while (i < n && str1[i] && str2 [i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
