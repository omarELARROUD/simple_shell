/**
 * check_path - checks for PATH in input
 * @command_path: command
 * @paths: holds paths
 * @args: hold for tokens
 * @path_index: index count for path
 * @cmd_found: check for commands found in PATH
 *
 * Return: number of cmd_found
 */
int check_path(char *command_path, char *paths[], char *args[],
		int path_index, int cmd_found)
{
	int i;

	if (args[0][0] != '/')
	{
		for (i = 0; i < path_index; i++)
		{
			/*Concatenate the command with the path*/
			_strcpy(command_path, paths[i]);
			_strcat(command_path, "/");
			_strcat(command_path, args[0]);

			if (access(command_path, X_OK) == 0)
			{
				cmd_found = 1;
				break;
			}
		}
	}
	else
	{
		cmd_found = 1;
		_strcpy(command_path, args[0]);
	}

	return (cmd_found);
}
