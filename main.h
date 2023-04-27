#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/* prototypes */

void pipe_in(void);
void delete_commands(char **argv);
void myprintf(int fd, char *str);
int string_length(char *str);
int mystrcmp(char *str1, char *str2);
char *combine_strings(char *st1, char *st2, char c);
void show_error(char *msg, char **buffer, size_t *length, char **argv);
int execute_program(char *buffer, char **argv, size_t *length, char **envp);
int newproc(char *buffer, char **argv, size_t *len, char **envp, char *path);
int mysetenv(char **argv);
int strarr_count(char **argv);
char *findpath(char *cmd);

#endif
