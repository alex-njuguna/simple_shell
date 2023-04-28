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

#include "helpers.h"

/**
 * struct info - structure
 * @program_name: par 1
 * @input_line: par 2
 * @command_name: par 3
 * @exec_counter: par 4
 * @file_descriptor: par 5
 * @tokens: par 6
 * @env: par 7
 * @alias_list: par 8
 */
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

/**
 * struct builtins - structure
 * @builtin: par 1
 * @function: par 2
 */
typedef struct builtins
{
char *builtin;
int (*function)(data_of_program *data);
} builtins;

/* prototypes */
int display_alias(data_of_program *data, char *alias);
char *retrieve_alias(data_of_program *data, char *name);
int put_alias(char *alias_string, data_of_program *data);

int builtins1(data_of_program *data);

int myexit(data_of_program *data);
int mycd(data_of_program *data);
int mymkdir(data_of_program *data, char *new_dir);
int myhelp(data_of_program *data);
int another_alias(data_of_program *data);

int show_env(data_of_program *data);
int create_env(data_of_program *data);
int destroy_env(data_of_program *data);

char *get_env_var(char *env_var, data_of_program *data);
int env_set_key(char *key, char *value, data_of_program *data);
int env_delete_key(char *key, data_of_program *data);
void show_environ(data_of_program *data);

int run_prog(data_of_program *data);

void expand_variables(data_of_program *data);
void more_alias(data_of_program *data);
int append_str(char *buffer, char *str);

int locate_program(data_of_program *data);
char **split_path(data_of_program *data);
int ascertain_file(char *file_path);

void free_recurrent_data(data_of_program *data);
void free_data(data_of_program *data);
void free_pointers_array(char **myarray);

void num_to_str(long num, char *str, int base);
int _atoi(char *str);
int count_char(char *str, char *chars);

int _print(char *str);
int _printe(char *str);
int _print_error(int errorcode, data_of_program *data);

int str_len(char *str);
char *str_dup(char *str);
int str_compare(char *str1, char *str2, int number);
char *str_join(char *str1, char *str2);
void str_rev(char *str);

int mygetline(data_of_program *data);
int check_logic_ops(char *array_commands[], int i, char array_operators[]);

char *_strtok(char *line, char *delimator);

void split_str(data_of_program *data);

void prompter(char *prompt, data_of_program *data);
void process_data(data_of_program *data, int argc, char *argv[], char **env);
void handle_ctrl_c(int opr UNUSED);

#endif
