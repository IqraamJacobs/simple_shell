#ifndef SHELL_H
#define SHELL_H

/* usefull header files for the shell */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* environment */
extern char **environ;

/* functions prototypes used for the shell */
char **parse_cmd(char *user_cmd, int num_tokens, char *prog_name);
void free_cmd_arr(char **cmd_arr);
void execute_cmd(char **cmd, char *prog_name);
char *_strcpy(char *dest, char *src);
char *_getenv(const char *name);
char *get_full_path(char *cmd);

#endif#ifndef SHELL_H
#define SHELL_H

/* usefull header files for the shell */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* environment */
extern char **environ;

/* functions prototypes used for the shell */
char **parse_cmd(char *user_cmd, int num_tokens, char *prog_name);
void free_cmd_arr(char **cmd_arr);
void execute_cmd(char **cmd, char *prog_name);
char *_strcpy(char *dest, char *src);
char *_getenv(const char *name);
char *get_full_path(char *cmd);

#endif
