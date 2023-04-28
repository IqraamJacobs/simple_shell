#include "shell.h"

/**
 * get_full_path - loops through the path env
 * gets each path_dir, addeds the cmd passed and checks if a full path;
 * @cmd: the cmd passed in to be refined to full path
 *
 * Return: returns a pointer to the refined cmd full path
 */
char *get_full_path(char *cmd)
{
	char *path, *path_cp, *path_dir, *new_cmd;
	int dir_len, new_cmd_len;
	struct stat st_buffer;

	path = getenv("PATH");
	path_cp = strdup(path);
	if (path != NULL)
	{
		path_dir = strtok(path_cp, ":");
		while (path_dir != NULL)
		{
			dir_len = strlen(path_dir);
			new_cmd_len = dir_len + strlen(cmd);
			new_cmd = malloc(sizeof(char) * new_cmd_len);
			if (new_cmd == NULL)
			{
				free(path_cp);
				free(new_cmd);
				return (NULL);
			}
			strcpy(new_cmd, path_dir);
			strcat(new_cmd, "/");
			strcat(new_cmd, cmd);
			strcat(new_cmd, "\0");

			if (stat(new_cmd, &st_buffer) == 0)
			{
				free(path_cp);
				return (new_cmd);
			}
			else
			{
				free(new_cmd);
				path_dir = strtok(NULL, ":");
			}
		}
	}
	return (NULL);
}
