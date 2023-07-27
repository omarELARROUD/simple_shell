#ifndef MAIN_H
#define MAIN_H

/*header files needed*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

/*function prototypes*/
int sum(int x, int y);
void tokenize_str(char *str, char *args[]);
void fork_call(char *args[], char *command_path);
void prompt(char **input, size_t *n);
int _strcmp(char *str1, char *str2);
int _strncmp(char *str1, char *str2, int n);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
size_t _strcspn(const char *str, const char *rem);

#endif
