#include "main.h"

/**
 * fork_call - Example of the fork system call process
 * @args: holds arguments
 * @command_path: holds the path to the command
 * Return: Nothing
 */

void fork_call(char *args[], char *command_path)
{
	pid_t pid = fork();

	/*Error occured during fork call*/
	if (pid == -1)
	{
		perror("Fork System Call Failed");
		exit(EXIT_FAILURE);
	}

	/*Child process*/
	else if (pid == 0)
	{
		execve(command_path, args, NULL);
		perror("./hsh");
		exit(EXIT_FAILURE);
	}

	/*Parent process waits for child*/
	else
	{
		waitpid(pid, NULL, 0);
	}
}
