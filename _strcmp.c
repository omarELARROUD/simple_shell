#include "main.h"


int _strcmp(char *str1, char *str2)
{
	int i = 0;

	while (*(str1 + i) == *(str2 + i) && *(str1 + i))
		i++;

	if (*(str2 + i))
		return (*(str1 + i) - *(str2 + i));
	else
		return 0;
}
