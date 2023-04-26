#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdarg.h>

#define MAX_LENGTH 1024
#define MAX_ARGS 100

/* prototypes */

int mystrcmp(const char *str1, const char *str2);
size_t mystrcspn(const char *str1, const char *str2);
void myprintf(const char *format, ...);
int myputchar(char c);
char *read_input(void);
void execute_command(char *input);

#endif
