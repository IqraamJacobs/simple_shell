#include "shell.h"

/**
 * main - entry point of the program
 * @ac: argument count
 * @argv: argument vectors
 *
 * Return: 0 success
 * On error -1 is returned
 */
int main(__attribute__((unused)) int ac, char **argv)
{
	char *user_inp, *cmd_cp, *token, *prog_name = NULL, **cmd_arr;
	size_t inp_size = 0, num_tokens, loop = 1;
	ssize_t nchar;
	const char *delim = " \t\r\n\a";

	prog_name = argv[0];
	while (loop)
	{
		if (isatty(fileno(stdin)))
			printf("#cisfun~$ "); /* shell promt */
		nchar = getline(&user_inp, &inp_size, stdin);
		if (nchar == -1)
		{
			free(user_inp);
			return (-1);
		}
		cmd_cp = malloc(sizeof(char) * nchar);
		_strcpy(cmd_cp, user_inp); /* copy the input into the new mem space */
		token = strtok(user_inp, delim); /* tokenize to get number of input */
		if (token != NULL)
		{
			num_tokens = 0; /* Updates the num of tokens to 0 */
			while (token != NULL)
			{
				num_tokens++;
				token = strtok(NULL, delim);
			}
			cmd_arr = parse_cmd(cmd_cp, num_tokens, prog_name);/* get full arr */
			execute_cmd(cmd_arr, prog_name); /* excute the command */
			free_cmd_arr(cmd_arr); /* free cmd_arr allocated memory to prevent leaks */
		}
		free(cmd_cp);/* free the input copy memory */
	}
	free(user_inp); /* free the input buffer */ return (0);
}
/**
 * parse_cmd - gets the array used
 * for execve
 * @user_cmd: input from user
 * @num_tokens: number of strings in the array
 * @prog_name: used for printing the error messages
 *
 * Return: the array containing the pathname to be used by execve
 */
char **parse_cmd(char *user_cmd, int num_tokens, char *prog_name)
{
	char **argv, *token;
	const char *delim = " \n\t\r\a";
	int i = 0;

	argv = malloc(sizeof(char *) * num_tokens + 1);
	if (argv == NULL)
	{
		perror(prog_name);
		return (NULL);
	}
	token = strtok((user_cmd), delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		if (argv == NULL)
		{
			perror(prog_name);
			return (NULL);
		}
		_strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	return (argv);
}

/**
 * free_cmd_arr - frees the allocated
 * memory of the cmd_arr
 * @cmd_arr: pointer to the arr of strings
 *
 * Return: Void functions return no value
 */
void free_cmd_arr(char **cmd_arr)
{
	int i = 0;

	while (cmd_arr[i])
		free(cmd_arr[i++]);
	free(cmd_arr);
}

/**
 * execute_cmd - executes the cmd passed in by the user
 * @cmd: a pointer to an array of strings containing the cmd
 * @prog_name: the programe passed into the function to be
 * able to print the proper error message
 *
 * Return: Void functions have no return value
 */
void execute_cmd(char **cmd, char *prog_name)
{
	char **env = environ, *new_cmd;
	pid_t pid;
	struct stat st_buffer;
	int child_pid_status;

	if (stat(cmd[0], &st_buffer) == 0)
	{
		new_cmd = strdup(cmd[0]);
	}
	else
		new_cmd = get_full_path(cmd[0]);
	if (stat(new_cmd, &st_buffer) == 0 && new_cmd != NULL)
	{
		pid = fork();
		if (pid < 0)
		{
			perror(prog_name);
			return;
		}
		else if (pid == 0)
		{
			if (execve(new_cmd, cmd, env) == -1)
			{
				perror(prog_name);
				return;
			}
		}
		else
			wait(&child_pid_status);
	}
	else
		perror(prog_name);
	if (new_cmd != NULL)
		free(new_cmd);
}
