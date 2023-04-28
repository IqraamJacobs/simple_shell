#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

<<<<<<< HEAD
	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));
=======
	if (ac != 1)
	{
		printf("Usage: ./shell");
		return (-1);
	}
	if (argv[0] == NULL)
	{
		perror("empty input"); return (-1);
	}
	prog_name = argv[0];
	while (loop)
	{
		if (isatty(fileno(stdin)))
			printf("#cisfun~$ "); /* shell promt */
		nchar = getline(&user_inp, &inp_size, stdin); /* get user input from the input stream */
		if (nchar == -1)
		{
			free(user_inp); return (-1);
		}
		cmd_cp = malloc(sizeof(char) * nchar); /* alloc mem for manipulating the input */
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
			if (strcmp(cmd_arr[0], "exit") == 0) /* checks if input is exit */
			{
				free_cmd_arr(cmd_arr); free(cmd_cp); free(user_inp); exit(98);
			}
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
	const char *delim = " \n";
	int i = 0;
>>>>>>> main

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
