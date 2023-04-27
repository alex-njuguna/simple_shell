
<h1 align ="center">simple_shell :shell:</h1><br>
<p align="center">
<img src="https://cdn.shopify.com/s/files/1/0204/4104/products/20180517-20180517-P1260614_600x.jpg?v=1528506358">
</p>
<hr /> 

## Repository Description

This repository contains the files to simulate a basic **Unix Shell** with its respective commands. It uses the POSIX API to implement many of the same functionalities of the first Ken Thompson's Shell and It is made to carry out the  **0x16. C - Simple Shell** project at [ALX Africa.](https://www.alxafrica.com/ "ALX Africa.")

The predominantly used calls are **read**, **write**, **open**, **execve**, **exit**, **fflush**, **fork**, **free**, **malloc**, **getline**, **isatty**, **perror**, **strtok**, **wait**, and **waitpid**.

This simple shell is a Shell interface written in C programming language that gives to the user a prompt *Hell_Shell>> *, after it accepts, it executes a user inputted command in a separate process called child process.

![C logo](https://seeklogo.com/images/C/c-programming-language-logo-9B32D017B1-seeklogo.com.png)

## Acknowledgments

- ALX Community
- Hat tip to anyone whose code was used

## General.

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 14.04 LTS
- Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project is mandatory
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl "betty-doc.pl")
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded

## Requirements:

* Operating System: [Ubuntu 14.04 LTS](http://releases.ubuntu.com/14.04/)

* Compiler: [GCC 4.8.4](https://gcc.gnu.org/gcc-4.8/)

## Features:
* This program displays a prompt and waits that the user types a command. A command line always ends with a new line (when user push *ENTER* key).
* The prompt is displayed again each time a command has been executed.
* When the user enters exit, *Hell shell* will end and returns the status 0.
* When the user enters exit *[status]*, *Hell Shell* will end and returns the inputted status, where *status* is a value from 0 to 255. 
* The user could stop the program using *Ctrl+D* (end of file).
* The shell handles the command lines with arguments and pathways.
* The program does not quit when the user imputs ^C (Ctrl+C).
* The program prints the current enviroment when the user types *env*.
* This program executes the most common shell commands as *ls*, *grep*, *find*, *pwd*, *rm*, *cp*, *mv*, *exit*, *env*, *history*, etc... with arguments.
* If an executable cannot be found, It prints an error message and displays the prompt again.
* This Shell supports commentaries using *#*, 
* The *Hell Shell* does NOT support wildcard characters such as ls \*.dat in parameters (or commands).
* This shell does NOT support pipes *|*, shell logical operators as *&& or ||*, neither commands separator *;*.

### Allowed functions: 
-   `access` (man 2 access)
-   `chdir` (man 2 chdir)
-   `close` (man 2 close)
-   `closedir` (man 3 closedir)
-   `execve` (man 2 execve)
-   `exit` (man 3 exit)
-   `_exit` (man 2 _exit)
-   `fflush` (man 3 fflush)
-   `fork` (man 2 fork)
-   `free` (man 3 free)
-   `getcwd` (man 3 getcwd)
-   `getline` (man 3 getline)
-   `getpid` (man 2 getpid)
-   `isatty` (man 3 isatty)
-   `kill` (man 2 kill)
-   `malloc` (man 3 malloc)
-   `open` (man 2 open)
-   `opendir` (man 3 opendir)
-   `perror` (man 3 perror)
-   `read` (man 2 read)
-   `readdir` (man 3 readdir)
-   `signal` (man 2 signal)
-   `stat` (__xstat) (man 2 stat)
-   `lstat` (__lxstat) (man 2 lstat)
-   `fstat` (__fxstat) (man 2 fstat)
-   `strtok` (man 3 strtok)
-   `wait` (man 2 wait)
-   `waitpid` (man 2 waitpid)
-   `wait3` (man 2 wait3)
-   `wait4` (man 2 wait4)
-   `write` (man 2 write)





## Process Description

The next steps are a brief description about how the shell works:

1. First, the parent process is created when the user run the program.
2. Then, the *isatty()* function using *STDIN_FILENO* file descriptor -fd- to tests if there is an open file descriptor referring to a terminal. If *isatty()* returns 1, the prompt is showed using *write()* with *STDOUT_FILENO* as fd and waits for an input user command line.
3. When the user types a command, *getline()* function reads an entire line from the stream and *strtok()* function breaks the inputted command into a sequence of non-empty tokens.
4. Next, it creates a separate child process suing *fork()* that performs the inputted command. Unless otherwise is specified, the parent process waits for the child to exit before continuing.
5. After tokening the command, *execve()* function brings and executes it, the it frees all allocated memory with *free()*.
6. Finally, the program returns to main process: prints the prompt, and waits for another user input.
<p align="center">
  <img  style="width: 100%; height: 900px"  src="https://user-images.githubusercontent.com/47532674/79399623-79bd2300-7f49-11ea-82b6-7d4f7576318d.png">
</p>




## Basic beggining

To run this shell with its respective commands its necessary to clone this reposotory in your terminal. Do it like this:
- HTTPS:

```c
git clone https://github.com/Parsankamusa/simple_shell.git
```

- SSH:

```
git clone git@github.com:Parsankamusa/simple_shell.git
```

## Compiling, Debugging and Runing

- All of your and our programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`

- To **compile** your functions use: `

```
gcc -Wall -Wextra -Werror -pedantic -Wno-format -g *.c -o Hell_Shell
```
- If you want to **debugging** the shell, use valgrind:
```
valgrind --leak-check=full ./Hell_Shell
```
- Or just **run** and try this shell using:
```
./Hell_Shell
```
- This program provides a simple manual to know and get familiar with the shell. Open it by typing: 
```
man ./man_1_simple_shell
```

## Examples

Here are shown some examples of the usage of the Shell:

- ls

```shell
Hell_Shell>> ls
AUTHORS  Hell_Shell  README.md auxiliar_functions.c  create_child.c  dir  execute.c  free_mem.c  generateAUTHORS  man_1_simple_shell  shell.h shell_init.c  tokening.c
```

```shell
Hell_Shell>> /bin/ls
AUTHORS  Hell_Shell  README.md	auxiliar_functions.c  create_child.c  dir  execute.c  free_mem.c  generateAUTHORS  man_1_simple_shell  shell.h shell_init.c  tokening.c
```

```shell
Hell_Shell>> ls -lat
total 88
drwxrwxr-x 4 vagrant vagrant  4096 Apr 16 17:04 .
-rw-rw-r-- 1 vagrant vagrant  5502 Apr 16 17:04 README.md
drwxrwxr-x 2 vagrant vagrant  4096 Apr 16 12:15 dir
drwxrwxr-x 8 vagrant vagrant  4096 Apr 16 00:20 .git
-rw-rw-r-- 1 vagrant vagrant  1964 Apr 15 23:17 shell_init.c
-rw-rw-r-- 1 vagrant vagrant   821 Apr 15 23:17 tokening.c
-rw-rw-r-- 1 vagrant vagrant   756 Apr 15 23:17 free_mem.c
-rw-rw-r-- 1 vagrant vagrant  1911 Apr 15 23:17 shell.h
-rw-rw-r-- 1 vagrant vagrant   702 Apr 15 23:17 create_child.c
-rw-rw-r-- 1 vagrant vagrant  2364 Apr 15 23:17 execute.c
-rwxrwxr-x 1 vagrant vagrant 21729 Apr 15 23:17 Hell_Shell
-rw-rw-r-- 1 vagrant vagrant  1682 Apr 15 23:17 auxiliar_functions.c
-rw-rw-r-- 1 vagrant vagrant  2600 Apr 14 18:25 man_1_simple_shell
-rwxrwxr-x 1 vagrant vagrant   392 Apr 13 14:46 generateAUTHORS
-rw-rw-r-- 1 vagrant vagrant   156 Apr 13 14:46 AUTHORS
drwxrwxr-x 7 vagrant vagrant  4096 Apr  6 18:22 ..
```
- pwd

```shell
Hell_Shell>> pwd
/home/vagrant/HOLBERTON/simple_shell
```
- echo

```shell
Hell_Shell>> echo Hello World
Hello World
```
- *Ctrl+D*  and  *Ctrl+C* 

```shell
Hell_Shell>> ^C
Hell_Shell>> 
vagrant@vagrant-ubuntu-trusty-64:~/HOLBERTON/simple_shell$ 
```
Node that in the second line the *Ctrl+C*  is typed
## 🤝 Contributing

Contributions, issues, and feature requests are welcome!

Feel free to check the [issues page](../../issues/).

## Disclaimer
if you happen to use these repo for ALX we got `198%`

## Show your support

Give a ⭐️ if you like this project!

## Known Bugs
Currently no known bugs.


## Authors:

- *Musa Parsanka* - [@pasankamusa](https://github.com/pasankamusa) 
- *Nicholas Gitobu*  - [@nickssilver](https://github.com/nickssilver)

<p align="center">
  <img src="https://assets.imaginablefutures.com/media/images/ALX_Logo.max-200x150.png" alt="ALX|Holberton School logo">
</p>

