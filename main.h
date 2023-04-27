#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>

#define PROMPT_MSG "dali<3 "

#define UNUSED attribute((unused))

#define BUFFER_SIZE 1024

#define HELP_CD_MSG "cd=\n"
"cd:\tcd [dir]\n\n"
" Change the shell working directory.\n\n"
" If no argument is given to cd the command will be interpreted\n"
" as cd $HOME.\n"
" if the argumenthelp is - (cd -), the command will be interpreted\n"
" as cd $OLDPWD.\n\n"

#define HELP_EXIT_MSG "exit=\n"
"exit:\texit [STATUS]\n\n"
" Exit of the simple-shell.\n\n"
" Exits the shell with a status of N. If N is omitted, the exit status\n"
" is that of the last command executed.\n\n"

#define HELP_ENV_MSG "env=\n"
"env:\tenv \n\n"
" Print environment.\n\n"
" The env command will be print a complete list of enviroment variables.\n\n"

#define HELP_SETENV_MSG "setenv=\n"
"setenv:\tsetenv VARIABLE VALUE\n\n"
" Change or add an environment variable.\n\n"
" initialize a new environment variable, or modify an existing one\n"
" When there are not correct numbers of arguments print error message.\n\n"

#define HELP_UNSETENV_MSG "unsetenv=\n"
"unsetenv:\tunsetenv VARIABLE\n\n"
" The unsetenv function deletes one variable from the environment.\n\n"
" Wen there are not correct numbers of arguments print error message.\n\n"

#define HELP_MSG "help=\n"
"help:\thelp [BUILTIN_NAME]\n\n"
" Display information about builtin commands.\n\n"
" Displays brief summaries of builtin commands. If BUILTIN_NAME is\n"
" specified, gives detailed help on all commands matching BUILTIN_NAME,\n"
" otherwise the list of help topics is printed BUILTIN_NAME list.\n"
" Arguments:\n\n"
" BUILTIN_NAME specifiying a help topic.\n\n"
" cd\t[dir]\n"
" exit\t[status]\n"
" env\n"
" setenv\t[variable value]\n"
" unset\t[variable]\n"
" help\t[built_name]\n\n"


typedef struct info
{
char *program_name;
char *input_line;
char *command_name;
int exec_counter;
int file_descriptor;
char **tokens;
char **env;
char **alias_list;
} data_of_program;

typedef struct builtins
{
char *builtin;
int (*function)(data_of_program *data);
} builtins;

void inicialize_data(data_of_program *data, int arc, char *argv[], char **env);
void sisifo(char *prompt, data_of_program *data);
void handle_ctrl_c(int opr UNUSED);

int _getline(data_of_program *data);
int check_logic_ops(char *array_commands[], int i, char array_operators[]);

void expand_variables(data_of_program *data);
void expand_alias(data_of_program *data);
int buffer_add(char *buffer, char *str_to_add);

void tokenize(data_of_program *data);
char *_strtok(char *line, char *delim);

int execute(data_of_program *data);

int builtins_list(data_of_program *data);

char **tokenize_path(data_of_program *data);
int find_program(data_of_program *data);

void free_array_of_pointers(char **directories);
void free_recurrent_data(data_of_program *data);
void free_all_data(data_of_program *data);

int builtin_exit(data_of_program *data);
int builtin_cd(data_of_program *data);
int set_work_directory(data_of_program *data, char *new_dir);
int builtin_help(data_of_program *data);
int builtin_alias(data_of_program *data);

int builtin_env(data_of_program *data);
int builtin_set_env(data_of_program *data);
int builtin_unset_env(data_of_program *data);

char *env_get_key(char *name, data_of_program *data);
int env_set_key(char *key, char *value, data_of_program *data);
int env_remove_key(char *key, data_of_program *data);
void print_environ(data_of_program *data);

int _print(char *string);
int _printe(char *string);
int _print_error(int errorcode, data_of_program *data);

int str_length(char *string);
char *str_duplicate(char *string);
int str_compare(char *s1, char *s2);

#endif
