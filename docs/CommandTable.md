# Command Table Docs

## Command Tree
---
- ### e\_Type
#### Description
`e_Type` - is an enum of different types of operations.
#### Definition
```C
enum    e_Type
{
	NONE, /* No operator */
	PIPE, /* Pipe (|) */
	AND,  /* Logical AND (&&) */
	OR,   /* Logical OR (||) */
	CMD,  /* COMMAND */
};
```
---
- ### s\_CommandNode
#### Description
`CommandNode` - is a base structure of the node of the command tree.

#### Definition
```C
struct    s_CommandNode
{
	e_Type             otype;
	s_SimpleCommand    *cmd;
	s_CommandNode      *left;
	s_CommandNode      *right;
};
```
- _otype_ - Represents the type of operator associated with the node.
- _cmd_ - Pointer to a simple command structure.
- _left_ & _right_ - pointers to the left and right child nodes respectively (if the input is complex command).
---
- ### s\_SimpleCommand
#### Description
This struct represent a simple command. It contains information about name of the executable binary file, as well as a list of arguments passed to the command. In addition it could have information about any IN- or OUT-redirections in form of list of file names and pipe file descriptors if the command is a part of pipe sequence.  
#### Definition
```C
struct s_SimpleCommand
{
	char    *bin;      /* Binary file name (or path) */
	char    **args;    /* List of arguments for command */
	char    **in_fs;   /* List of IN-redirections */
	char    **out_fs;  /* List of OUT-redirections */
	int     pipefd[2]; /* FD's in case of pipe */
};
```

- _bin_ - Name of (or path to) the executable binary file.
- _args_ - List of arguments (_NULL terminated_) in the following format:
```C
**args = {<bin_name>, <arg_1>, ..., <arg_n>, NULL};
/* If no arguments specified */
**args = {<bin_name>, NULL};
```

- _in\_fs_ - List of file names (_NULL terminated_) for IN-redirection in the following format:
```C
**in_fs = {<in_file_1>, ..., <in_file_n>, NULL};
/* If no redirections */
**in_fs = {NULL};
```
- _out\_fs_ - List of file names (_NULL terminated_) for OUT-redirections in the same format as _in\_fs_.
- _pipefd\[2\]_ - A pipe fd's array create with [`pipe()`](https://www.gnu.org/software/libc/manual/html_node/Creating-a-Pipe.html) function.
```C
/* If command is not a part of a pipe sequence */
pipefd[2] = {-1, -1};
```
#### Example
```C
#include <stdio.h>
#include <stdlib.h>

struct s_SimpleCommand
{
    char *bin;
    char **args;
    char **in_fs;
    char **out_fs;
    int pipefd[2];
};

int main() {
    // Example initialization and usage of s_SimpleCommand
    // Initialize a SimpleCommand struct
    struct s_SimpleCommand cmd;
    cmd.bin = "ls";
    cmd.args = (char *[]){"ls", "-l", NULL}; // NULL terminated array
    cmd.in_fs = NULL; // No input redirections
    cmd.out_fs = (char *[]){"output.txt", NULL}; // Output redirection to a file
    cmd.pipefd[0] = -1;
    cmd.pipefd[1] = -1;
    // Display information
    printf("Command: %s\n", cmd.bin);
    printf("Arguments: ");
    for (char **arg = cmd.args; *arg != NULL; arg++) {
        printf("%s ", *arg);
    }
    printf("\nOutput redirections: ");
    if (cmd.out_fs != NULL) {
        for (char **out = cmd.out_fs; *out != NULL; out++) {
            printf("%s ", *out);
        }
    } else {
        printf("None");
    }
    printf("\n");
    return 0;
}
```
