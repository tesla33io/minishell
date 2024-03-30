# Allowed functions

### Function: `readline`

#### Description:
`readline` function reads a line from the standard input (stdin) and stores it into the buffer pointed to by `buffer`. It stops reading after a newline character or EOF is encountered, or after `n` - 1 bytes have been read. 

#### Prototype:
```c
char *readline(char *buffer, int n);
```

#### Parameters:
- `buffer`: Pointer to the buffer where the line will be stored.
- `n`: Maximum number of characters to be read (including the null terminator).

#### Return Value:
- Returns a pointer to the buffer containing the read line, or `NULL` if an error occurs or if EOF is reached before any characters are read.

#### Example Usage:
```c
#include <stdio.h>

#define MAX_LINE_LENGTH 100

int main() {
    char buffer[MAX_LINE_LENGTH];
    printf("Enter a line: ");
    char *line = readline(buffer, MAX_LINE_LENGTH);
    if (line != NULL) {
        printf("You entered: %s\n", line);
    } else {
        printf("Error reading input.\n");
    }
    return 0;
}
```
---
### Function: `rl_clear_history`

#### Description:
`rl_clear_history` function clears the history list maintained by the GNU Readline library. This list contains previously entered command lines.

#### Prototype:
```c
void rl_clear_history(void);
```

#### Parameters:
- None

#### Return Value:
- Void

#### Example Usage:
```c
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    add_history("command1");
    add_history("command2");
    printf("History before clearing:\n");
    for (int i = 0; i < history_length; i++) {
        printf("%s\n", history_get(i));
    }
    rl_clear_history();
    printf("\nHistory after clearing:\n");
    for (int i = 0; i < history_length; i++) {
        printf("%s\n", history_get(i));
    }
    return 0;
}
```
---
### Function: `rl_on_new_line`

#### Description:
`rl_on_new_line` function notifies the GNU Readline library that the cursor has moved to a new line. This function should be called when the prompt is output to the terminal.

#### Prototype:
```c
void rl_on_new_line(void);
```

#### Parameters:
- None

#### Return Value:
- Void

#### Example Usage:
```c
#include <stdio.h>
#include <readline/readline.h>

int main() {
    // Outputting a prompt
    printf("Prompt: ");
    // Notify readline library of new line
    rl_on_new_line();
    
    // Now, you can use readline to get input
    char *input = readline("");
    if (input != NULL) {
        printf("You entered: %s\n", input);
        free(input);
    }
    return 0;
}
```
---
### Function: `rl_replace_line`

#### Description:
`rl_replace_line` function replaces the current contents of the Readline's line buffer with the given text. This function is useful for updating the line buffer with dynamically generated content.

#### Prototype:
```c
void rl_replace_line(const char *text, int clear_undo);
```

#### Parameters:
- `text`: The text to replace the current line buffer contents with.
- `clear_undo`: If `clear_undo` is non-zero, the undo list will be cleared.

#### Return Value:
- Void

#### Example Usage:
```c
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    // Outputting a prompt
    printf("Enter a sentence: ");
    rl_on_new_line();

    // Get input from user
    char *input = readline("");
    if (input != NULL) {
        // Replace the input with a greeting
        rl_replace_line("Hello, ", 1);
        rl_on_new_line();
        // Print the modified line
        printf("%s%s\n", rl_line_buffer, input);
        free(input);
    }
    return 0;
}
```
---
### Function: `rl_redisplay`

#### Description:
`rl_redisplay` function refreshes the display of the current Readline line buffer. This function is useful when the display needs to be updated without changing the content of the buffer, such as when modifying terminal settings.

#### Prototype:
```c
void rl_redisplay(void);
```

#### Parameters:
- None

#### Return Value:
- Void

#### Example Usage:
```c
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    // Outputting a prompt
    printf("Enter a sentence: ");
    rl_on_new_line();

    // Get input from user
    char *input = readline("");
    if (input != NULL) {
        // Modify the input (e.g., capitalize)
        for (char *ptr = input; *ptr != '\0'; ++ptr) {
            *ptr = toupper(*ptr);
        }
        // Redisplay the modified input
        rl_replace_line(input, 1);
        rl_redisplay();
        rl_on_new_line();
        printf("%s\n", input);
        free(input);
    }
    return 0;
}
```
---
### Function: `add_history`

#### Description:
`add_history` function adds a new entry to the history list maintained by the GNU Readline library. This function allows storing previously entered command lines for future retrieval.

#### Prototype:
```c
void add_history(const char *line);
```

#### Parameters:
- `line`: The command line to be added to the history list.

#### Return Value:
- Void

#### Example Usage:
```c
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    // Outputting a prompt
    printf("Enter a command: ");
    rl_on_new_line();

    // Get input from user
    char *input = readline("");
    if (input != NULL) {
        // Add the input to the history list
        add_history(input);
        // Print the entered command
        printf("Command entered: %s\n", input);
        free(input);
    }
    return 0;
}
```
---
### Function: `wait3`

#### Description:
`wait3` function is used to wait for the termination of a child process and obtain its status. It is a variant of the `waitpid` function.

#### Prototype:
```c
pid_t wait3(int *status, int options, struct rusage *rusage);
```

#### Parameters:
- `status`: Pointer to an integer where the exit status of the terminated child process will be stored.
- `options`: Options for the wait operation.
- `rusage`: Pointer to a structure where resource usage information about the terminated process will be stored.

#### Return Value:
- On success, returns the process ID of the terminated child process.
- On error, returns -1, and `errno` is set to indicate the error.

#### Example Usage:
```c
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {  // Child process
        // Perform some tasks in the child process
        printf("Child process running...\n");
        sleep(2);  // Simulating some task
        _exit(42); // Exit with status 42
    } else if (pid > 0) { // Parent process
        printf("Parent process waiting for child...\n");
        pid_t terminated_pid = wait3(&status, 0, NULL);
        if (terminated_pid == -1) {
            perror("wait3");
            return 1;
        }
        if (WIFEXITED(status)) {
            printf("Child process with PID %d terminated with status %d\n", terminated_pid, WEXITSTATUS(status));
        }
    } else { // Fork failed
        perror("fork");
        return 1;
    }

    return 0;
}
```
---
### Function: `wait4`

#### Description:
`wait4` function is used to wait for the termination of a specific child process and obtain its status. It is a variant of the `waitpid` function.

#### Prototype:
```c
pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage);
```

#### Parameters:
- `pid`: Process ID of the child process to wait for. Use `-1` to wait for any child process.
- `status`: Pointer to an integer where the exit status of the terminated child process will be stored.
- `options`: Options for the wait operation.
- `rusage`: Pointer to a structure where resource usage information about the terminated process will be stored.

#### Return Value:
- On success, returns the process ID of the terminated child process.
- On error, returns -1, and `errno` is set to indicate the error.

#### Example Usage:
```c
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {  // Child process
        // Perform some tasks in the child process
        printf("Child process running...\n");
        sleep(2);  // Simulating some task
        _exit(42); // Exit with status 42
    } else if (pid > 0) { // Parent process
        printf("Parent process waiting for child...\n");
        pid_t terminated_pid = wait4(pid, &status, 0, NULL);
        if (terminated_pid == -1) {
            perror("wait4");
            return 1;
        }
        if (WIFEXITED(status)) {
            printf("Child process with PID %d terminated with status %d\n", terminated_pid, WEXITSTATUS(status));
        }
    } else { // Fork failed
        perror("fork");
        return 1;
    }

    return 0;
}
```
---
### Function: `signal`

#### Description:
`signal` function sets the disposition of the signal specified by `signum` to the function pointed to by `handler`. It allows custom signal handling for various signals.

#### Prototype:
```c
void (*signal(int signum, void (*handler)(int)))(int);
```

#### Parameters:
- `signum`: The signal number to set the disposition for.
- `handler`: Pointer to the function to be called when the specified signal occurs. It can be either a pointer to a function or one of the predefined signal handling macros like `SIG_DFL` (default action) or `SIG_IGN` (ignore the signal).

#### Return Value:
- Returns the previous handler function for the specified signal.

#### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Custom signal handler
void sigint_handler(int signum) {
    printf("Caught SIGINT signal\n");
}

int main() {
    // Set custom handler for SIGINT
    signal(SIGINT, sigint_handler);

    // Infinite loop to demonstrate signal handling
    printf("Send SIGINT (Ctrl+C) to trigger the custom handler...\n");
    while (1) {
        // Do nothing
    }

    return 0;
}
```
In this example, when the program receives the SIGINT signal (generated by pressing Ctrl+C), it calls the `sigint_handler` function to handle the signal.

---
### Function: `sigaction`

#### Description:
`sigaction` function allows the manipulation of signal action. It provides a more flexible and portable way to handle signals compared to `signal` function, especially when dealing with complex signal handling scenarios or needing finer control over signal behavior.

#### Prototype:
```c
int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
```

#### Parameters:
- `signum`: The signal number to set the action for.
- `act`: Pointer to a `struct sigaction` object specifying the new action to be taken for the specified signal.
- `oldact`: Pointer to a `struct sigaction` object where the old action for the specified signal will be stored.

#### Return Value:
- Returns 0 on success.
- Returns -1 on error, and `errno` is set to indicate the error.

#### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Custom signal handler
void sigint_handler(int signum) {
    printf("Caught SIGINT signal\n");
}

int main() {
    // Set up the sigaction structure
    struct sigaction new_action, old_action;
    new_action.sa_handler = sigint_handler;
    sigemptyset(&new_action.sa_mask);
    new_action.sa_flags = 0;

    // Set the new action for SIGINT
    if (sigaction(SIGINT, &new_action, &old_action) == -1) {
        perror("sigaction");
        return 1;
    }

    // Infinite loop to demonstrate signal handling
    printf("Send SIGINT (Ctrl+C) to trigger the custom handler...\n");
    while (1) {
        // Do nothing
    }

    return 0;
}
```
In this example, the `sigaction` function is used to set up a custom handler (`sigint_handler`) for the SIGINT signal (generated by pressing Ctrl+C). The old action for SIGINT is stored in `old_action`, but it is not used in this example.

---
### Function: `sigemptyset`

#### Description:
`sigemptyset` function initializes a signal set to empty, meaning it clears all signals from the set.

#### Prototype:
```c
int sigemptyset(sigset_t *set);
```

#### Parameters:
- `set`: Pointer to the signal set to be initialized.

#### Return Value:
- Returns 0 on success.
- Returns -1 on error, and `errno` is set to indicate the error.

#### Example Usage:
```c
#include <stdio.h>
#include <signal.h>

int main() {
    // Declare a signal set
    sigset_t my_set;

    // Initialize the signal set to empty
    if (sigemptyset(&my_set) == -1) {
        perror("sigemptyset");
        return 1;
    }

    // Now my_set is an empty set with no signals in it

    return 0;
}
```
In this example, `sigemptyset` initializes the `my_set` signal set to an empty set with no signals included.

---
### Function: `sigaddset`

#### Description:
`sigaddset` function adds the specified signal to the given signal set.

#### Prototype:
```c
int sigaddset(sigset_t *set, int signum);
```

#### Parameters:
- `set`: Pointer to the signal set to which the signal will be added.
- `signum`: The signal number to be added to the signal set.

#### Return Value:
- Returns 0 on success.
- Returns -1 on error, and `errno` is set to indicate the error.

#### Example Usage:
```c
#include <stdio.h>
#include <signal.h>

int main() {
    // Declare a signal set
    sigset_t my_set;

    // Initialize the signal set to empty
    if (sigemptyset(&my_set) == -1) {
        perror("sigemptyset");
        return 1;
    }

    // Add SIGINT (Ctrl+C) to the signal set
    if (sigaddset(&my_set, SIGINT) == -1) {
        perror("sigaddset");
        return 1;
    }

    // Now my_set contains SIGINT signal

    return 0;
}
```
In this example, `sigaddset` is used to add the SIGINT signal (Ctrl+C) to the `my_set` signal set.

---
### Function: `getcwd`

#### Description:
`getcwd` function gets the current working directory pathname.

#### Prototype:
```c
char *getcwd(char *buf, size_t size);
```

#### Parameters:
- `buf`: Pointer to the buffer where the current working directory pathname will be stored.
- `size`: Maximum number of characters that can be stored in the buffer pointed to by `buf`.

#### Return Value:
- Returns a pointer to the buffer `buf` on success.
- Returns `NULL` on failure, and `errno` is set to indicate the error.

#### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);
    } else {
        perror("getcwd");
        return 1;
    }
    return 0;
}
```
In this example, `getcwd` is used to retrieve the current working directory pathname and store it in the `cwd` buffer. The current working directory pathname is then printed.

---
### Function: `chdir`

#### Description:
`chdir` function changes the current working directory of the calling process to the directory specified by the pathname.

#### Prototype:
```c
int chdir(const char *path);
```

#### Parameters:
- `path`: Pointer to a null-terminated string containing the pathname of the directory to change to.

#### Return Value:
- Returns 0 on success.
- Returns -1 on failure, and `errno` is set to indicate the error.

#### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Change the current working directory to "/tmp"
    if (chdir("/tmp") == -1) {
        perror("chdir");
        return 1;
    }
    printf("Current working directory changed to /tmp\n");

    return 0;
}
```
In this example, `chdir` is used to change the current working directory to "/tmp". If successful, it prints a message indicating the change; otherwise, it prints an error message using `perror`.

---
### Function: `stat`

#### Description:
`stat` function retrieves information about a file specified by its pathname and stores it in a `struct stat`.

#### Prototype:
```c
int stat(const char *pathname, struct stat *statbuf);
```

#### Parameters:
- `pathname`: Pointer to a null-terminated string containing the pathname of the file to retrieve information about.
- `statbuf`: Pointer to a `struct stat` where the retrieved information will be stored.

#### Return Value:
- Returns 0 on success.
- Returns -1 on failure, and `errno` is set to indicate the error.

#### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    const char *filename = "example.txt";
    struct stat file_stat;

    // Retrieve information about the file
    if (stat(filename, &file_stat) == -1) {
        perror("stat");
        return 1;
    }

    // Print information about the file
    printf("File size: %ld bytes\n", file_stat.st_size);
    printf("File permissions: %o\n", file_stat.st_mode & 0777);
    printf("Last accessed: %s", ctime(&file_stat.st_atime));
    printf("Last modified: %s", ctime(&file_stat.st_mtime));

    return 0;
}
```
In this example, `stat` is used to retrieve information about the file "example.txt". The retrieved information is then printed, including file size, permissions, last access time, and last modification time.

---
### Function: `lstat`

#### Description:
`lstat` function retrieves information about a file specified by its pathname, similar to the `stat` function. However, `lstat` does not follow symbolic links; instead, it retrieves information about the link itself.

#### Prototype:
```c
int lstat(const char *pathname, struct stat *statbuf);
```

#### Parameters:
- `pathname`: Pointer to a null-terminated string containing the pathname of the file or symbolic link to retrieve information about.
- `statbuf`: Pointer to a `struct stat` where the retrieved information will be stored.

#### Return Value:
- Returns 0 on success.
- Returns -1 on failure, and `errno` is set to indicate the error.

#### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    const char *symlink_name = "symbolic_link";
    struct stat symlink_stat;

    // Retrieve information about the symbolic link
    if (lstat(symlink_name, &symlink_stat) == -1) {
        perror("lstat");
        return 1;
    }

    // Print information about the symbolic link
    printf("Symbolic link size: %ld bytes\n", symlink_stat.st_size);
    printf("Symbolic link permissions: %o\n", symlink_stat.st_mode & 0777);
    printf("Symbolic link last accessed: %s", ctime(&symlink_stat.st_atime));
    printf("Symbolic link last modified: %s", ctime(&symlink_stat.st_mtime));

    return 0;
}
```
In this example, `lstat` is used to retrieve information about the symbolic link "symbolic_link". The retrieved information is then printed, including the size, permissions, last access time, and last modification time of the symbolic link.

---
### Function: `fstat`

#### Description:
`fstat` function retrieves information about an open file descriptor and stores it in a `struct stat`.

#### Prototype:
```c
int fstat(int fd, struct stat *statbuf);
```

#### Parameters:
- `fd`: The file descriptor for the open file.
- `statbuf`: Pointer to a `struct stat` where the retrieved information will be stored.

#### Return Value:
- Returns 0 on success.
- Returns -1 on failure, and `errno` is set to indicate the error.

#### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    const char *filename = "example.txt";
    int fd;
    struct stat file_stat;

    // Open the file
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Retrieve information about the file descriptor
    if (fstat(fd, &file_stat) == -1) {
        perror("fstat");
        close(fd);
        return 1;
    }

    // Print information about the file descriptor
    printf("File size: %ld bytes\n", file_stat.st_size);
    printf("File permissions: %o\n", file_stat.st_mode & 0777);
    printf("Last accessed: %s", ctime(&file_stat.st_atime));
    printf("Last modified: %s", ctime(&file_stat.st_mtime));

    // Close the file
    close(fd);

    return 0;
}
```
In this example, `fstat` is used to retrieve information about the open file descriptor returned by `open` for the file "example.txt". The retrieved information is then printed, including file size, permissions, last access time, and last modification time.

---
### Function: `unlink`

#### Description:
`unlink` function deletes a name from the filesystem. If that name was the last link to the file and no process has the file open, the file is deleted and the space it was using is made available for reuse.

#### Prototype:
```c
int unlink(const char *pathname);
```

#### Parameters:
- `pathname`: Pointer to a null-terminated string containing the pathname of the file to be deleted.

#### Return Value:
- Returns 0 on success.
- Returns -1 on failure, and `errno` is set to indicate the error.

#### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    const char *filename = "example.txt";

    // Delete the file
    if (unlink(filename) == -1) {
        perror("unlink");
        return 1;
    }
    printf("File '%s' deleted successfully.\n", filename);

    return 0;
}
```
In this example, `unlink` is used to delete the file "example.txt" from the filesystem. If successful, it prints a message indicating the deletion; otherwise, it prints an error message using `perror`.

---
### Function: `execve`

#### Description:
`execve` function executes a program, replacing the current process image with a new process image. It loads the program into the current process space and starts its execution.

#### Prototype:
```c
int execve(const char *pathname, char *const argv[], char *const envp[]);
```

#### Parameters:
- `pathname`: Pointer to a null-terminated string containing the pathname of the file to be executed.
- `argv`: Pointer to an array of null-terminated strings representing the argument vector. The first element should be the filename of the program being executed.
- `envp`: Pointer to an array of null-terminated strings representing the environment variables. Each string has the form "name=value".

#### Return Value:
- Returns -1 on failure, and `errno` is set to indicate the error.
- Returns only if an error occurs.

#### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *const argv[] = {"/bin/ls", "-l", NULL};
    char *const envp[] = {NULL};  // Empty environment variables array

    // Execute the "ls -l" command
    if (execve("/bin/ls", argv, envp) == -1) {
        perror("execve");
        return 1;
    }

    // This code won't be reached if execve is successful
    printf("This won't be printed because execve replaced the process image.\n");

    return 0;
}
```
In this example, `execve` is used to execute the "ls -l" command. The `argv` array contains the program name ("/bin/ls") and its argument ("-l"). The `envp` array is empty because no environment variables are needed. If `execve` is successful, the current process image is replaced by the "ls -l" command, and the code after `execve` won't be executed. If `execve` fails, an error message is printed using `perror`.

---
### Function: `dup`

#### Description:
`dup` function duplicates an open file descriptor. It creates a new file descriptor that refers to the same file or pipe as the original file descriptor.

#### Prototype:
```c
int dup(int oldfd);
```

#### Parameters:
- `oldfd`: The file descriptor to be duplicated.

#### Return Value:
- Returns a new file descriptor on success, which is the lowest-numbered unused file descriptor greater than or equal to `0`.
- Returns -1 on failure, and `errno` is set to indicate the error.

#### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd, new_fd;
    const char *filename = "example.txt";

    // Open the file
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Duplicate the file descriptor
    new_fd = dup(fd);
    if (new_fd == -1) {
        perror("dup");
        close(fd);
        return 1;
    }

    printf("File descriptor %d duplicated to %d.\n", fd, new_fd);

    // Close the original file descriptor
    close(fd);

    return 0;
}
```
In this example, `dup` is used to duplicate the file descriptor `fd`. If successful, it prints a message indicating the duplication; otherwise, it prints an error message using `perror`. The duplicated file descriptor `new_fd` can be used independently of the original file descriptor `fd`.

---
### Function: `dup2`

#### Description:
`dup2` function duplicates an open file descriptor to a specific file descriptor number. If the target file descriptor is already open, it is closed before the duplication.

#### Prototype:
```c
int dup2(int oldfd, int newfd);
```

#### Parameters:
- `oldfd`: The file descriptor to be duplicated.
- `newfd`: The desired file descriptor number for the duplication.

#### Return Value:
- Returns the new file descriptor (which is `newfd`) on success.
- Returns -1 on failure, and `errno` is set to indicate the error.

#### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd, new_fd;
    const char *filename = "example.txt";

    // Open the file
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Duplicate the file descriptor to file descriptor 10
    new_fd = dup2(fd, 10);
    if (new_fd == -1) {
        perror("dup2");
        close(fd);
        return 1;
    }

    printf("File descriptor %d duplicated to %d.\n", fd, new_fd);

    // Close the original file descriptor
    close(fd);

    return 0;
}
```
In this example, `dup2` is used to duplicate the file descriptor `fd` to file descriptor `10`. If successful, it prints a message indicating the duplication; otherwise, it prints an error message using `perror`. The original file descriptor `fd` is closed afterward.

---
### Function: `pipe`

#### Description:
`pipe` function creates a pipe, a unidirectional communication channel. It creates a pipe and sets up two file descriptors: one for reading from the pipe (`fd[0]`) and one for writing to the pipe (`fd[1]`).

#### Prototype:
```c
int pipe(int pipefd[2]);
```

#### Parameters:
- `pipefd`: An array of two integers where the file descriptors for the pipe are stored. `pipefd[0]` is for reading, and `pipefd[1]` is for writing.

#### Return Value:
- Returns 0 on success.
- Returns -1 on failure, and `errno` is set to indicate the error.

#### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    char buffer[256];
    ssize_t num_read;

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    // Write data into the pipe
    const char *message = "Hello, Pipe!";
    if (write(pipefd[1], message, strlen(message)) == -1) {
        perror("write");
        return 1;
    }

    // Read data from the pipe
    num_read = read(pipefd[0], buffer, sizeof(buffer));
    if (num_read == -1) {
        perror("read");
        return 1;
    }

    // Null-terminate the buffer
    buffer[num_read] = '\0';

    // Print the data read from the pipe
    printf("Data read from the pipe: %s\n", buffer);

    return 0;
}
```
In this example, `pipe` is used to create a pipe. Data is written into the pipe using the file descriptor `pipefd[1]`, and then read from the pipe using the file descriptor `pipefd[0]`. Finally, the data read from the pipe is printed.

---
### Function: `opendir`

#### Description:
`opendir` function opens a directory stream corresponding to the directory specified by the pathname.

#### Prototype:
```c
DIR *opendir(const char *pathname);
```

#### Parameters:
- `pathname`: Pointer to a null-terminated string containing the pathname of the directory to be opened.

#### Return Value:
- Returns a pointer to a `DIR` structure representing the directory stream on success.
- Returns `NULL` on failure, and `errno` is set to indicate the error.

#### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    const char *dirname = ".";  // Current directory

    // Open the directory stream
    DIR *dir = opendir(dirname);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    // Read and print directory entries
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Close the directory stream
    closedir(dir);

    return 0;
}
```
In this example, `opendir` is used to open the current directory (`"."`). If successful, it prints the names of all entries in the directory. Finally, the directory stream is closed using `closedir`.

---
### Function: `readdir`

#### Description:
`readdir` function reads the next directory entry from the directory stream opened with `opendir`.

#### Prototype:
```c
struct dirent *readdir(DIR *dir);
```

#### Parameters:
- `dir`: Pointer to a `DIR` structure representing the directory stream.

#### Return Value:
- Returns a pointer to a `struct dirent` structure representing the next directory entry on success.
- Returns `NULL` when reaching the end of the directory stream or on error, and `errno` is set to indicate the error.

#### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    const char *dirname = ".";  // Current directory

    // Open the directory stream
    DIR *dir = opendir(dirname);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    // Read and print directory entries
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Close the directory stream
    closedir(dir);

    return 0;
}
```
In this example, `readdir` is used to read directory entries from the directory stream opened with `opendir`. It prints the names of all directory entries. When `readdir` returns `NULL`, it indicates the end of the directory stream or an error.

---
### Function: `closedir`

#### Description:
`closedir` function closes the directory stream opened with `opendir`.

#### Prototype:
```c
int closedir(DIR *dir);
```

#### Parameters:
- `dir`: Pointer to a `DIR` structure representing the directory stream to be closed.

#### Return Value:
- Returns 0 on success.
- Returns -1 on failure, and `errno` is set to indicate the error.

#### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    const char *dirname = ".";  // Current directory

    // Open the directory stream
    DIR *dir = opendir(dirname);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    // Read and print directory entries
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Close the directory stream
    if (closedir(dir) == -1) {
        perror("closedir");
        return 1;
    }

    return 0;
}
```
In this example, `closedir` is used to close the directory stream opened with `opendir`. If successful, it returns 0; otherwise, it returns -1, indicating an error, and prints an error message using `perror`.

---
### Function: `isatty`

#### Description:
`isatty` function checks whether the given file descriptor refers to a terminal device.

#### Prototype:
```c
int isatty(int fd);
```

#### Parameters:
- `fd`: The file descriptor to be checked.

#### Return Value:
- Returns 1 if the file descriptor refers to a terminal device (TTY).
- Returns 0 if the file descriptor does not refer to a terminal device.
- Returns -1 on error, and `errno` is set to indicate the error.

#### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Check if file descriptor 0 (stdin) is a TTY
    if (isatty(0) == 1) {
        printf("stdin is a TTY.\n");
    } else if (isatty(0) == 0) {
        printf("stdin is not a TTY.\n");
    } else {
        perror("isatty");
        return 1;
    }

    return 0;
}
```
In this example, `isatty` is used to check if stdin (file descriptor 0) is a terminal device (TTY). Depending on the return value, it prints whether stdin is a TTY or not. If `isatty` encounters an error, it prints an error message using `perror`.

---
### Function: `ttyname`

#### Description:
`ttyname` function returns the name of the terminal device associated with the given file descriptor.

#### Prototype:
```c
char *ttyname(int fd);
```

#### Parameters:
- `fd`: The file descriptor for which to get the terminal device name.

#### Return Value:
- Returns a pointer to a null-terminated string containing the name of the terminal device associated with the file descriptor.
- Returns `NULL` if the file descriptor is not associated with a terminal device or on error, and `errno` is set to indicate the error.

#### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Get the name of the terminal associated with stdout (file descriptor 1)
    char *terminal = ttyname(1);
    if (terminal != NULL) {
        printf("Terminal device associated with stdout: %s\n", terminal);
    } else {
        perror("ttyname");
        return 1;
    }

    return 0;
}
```
In this example, `ttyname` is used to get the name of the terminal device associated with stdout (file descriptor 1). If successful, it prints the terminal device name; otherwise, it prints an error message using `perror`.

---
### Function: `ttyslot`

#### Description:
The `ttyslot` function returns the slot number of the user's terminal in the system's tty file.

#### Prototype:
```c
int ttyslot(void);
```

#### Return Value:
- Returns the slot number of the user's terminal in the tty file.
- Returns -1 on failure, and `errno` is set to indicate the error.

#### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int slot = ttyslot();
    if (slot != -1) {
        printf("Terminal slot number: %d\n", slot);
    } else {
        perror("ttyslot");
        return 1;
    }

    return 0;
}
```

In this example, `ttyslot` is used to get the slot number of the user's terminal in the tty file. If successful, it prints the slot number; otherwise, it prints an error message using `perror`.

---
### Function: `ioctl`

#### Description:
`ioctl` function performs device-specific I/O control operations on a file descriptor.

#### Prototype:
```c
int ioctl(int fd, unsigned long request, ...);
```

#### Parameters:
- `fd`: The file descriptor on which the operation is to be performed.
- `request`: The request code specifying the operation to be performed.
- `...`: Additional arguments depending on the request code.

#### Return Value:
- Returns 0 on success.
- Returns -1 on failure, and `errno` is set to indicate the error.

#### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

int main() {
    int fd = open("/dev/tty", O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Example: Get terminal window size
    struct winsize ws;
    if (ioctl(fd, TIOCGWINSZ, &ws) == -1) {
        perror("ioctl");
        close(fd);
        return 1;
    }

    printf("Terminal window size: %d rows x %d columns\n", ws.ws_row, ws.ws_col);

    close(fd);
    return 0;
}
```

In this example, `ioctl` is used to get the size of the terminal window. It uses the `TIOCGWINSZ` request code to retrieve the window size information and stores it in a `winsize` structure. If successful, it prints the number of rows and columns in the terminal window; otherwise, it prints an error message using `perror`.

---
### Function: `getenv`

#### Description:
`getenv` function retrieves the value of the environment variable specified by the given name.

#### Prototype:
```c
char *getenv(const char *name);
```

#### Parameters:
- `name`: Pointer to a null-terminated string containing the name of the environment variable.

#### Return Value:
- Returns a pointer to a null-terminated string containing the value of the environment variable.
- Returns `NULL` if the specified environment variable is not found.

#### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Retrieve the value of the environment variable "PATH"
    char *path_value = getenv("PATH");
    if (path_value != NULL) {
        printf("Value of PATH: %s\n", path_value);
    } else {
        printf("Environment variable PATH not found.\n");
    }

    return 0;
}
```

In this example, `getenv` is used to retrieve the value of the environment variable "PATH". If the environment variable is found, it prints its value; otherwise, it prints a message indicating that the environment variable is not found.

---
### Function: `tcsetattr`
#### Description:
The `tcsetattr` function sets the parameters associated with the terminal referred to by the file descriptor `fd` from the `termios` structure pointed to by `termios_p`.

### Prototype:
```c
int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);
```

### Parameters:
- `fd`: The file descriptor associated with the terminal.
- `optional_actions`: The action to be taken. It can be one of the following:
  - `TCSANOW`: Changes occur immediately.
  - `TCSADRAIN`: Changes occur after all output written to the terminal has been transmitted.
  - `TCSAFLUSH`: Changes occur after all output written to the terminal has been transmitted, and the input queue is discarded.
- `termios_p`: Pointer to a `termios` structure containing the terminal attributes to be set.

### Return Value:
- Returns 0 on success.
- Returns -1 on failure, and `errno` is set to indicate the error.

### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

int main() {
    struct termios new_termios;
    int fd = STDIN_FILENO; // Standard input file descriptor

    // Get current terminal attributes
    if (tcgetattr(fd, &new_termios) == -1) {
        perror("tcgetattr");
        return 1;
    }

    // Modify terminal attributes (for example, turn off echo)
    new_termios.c_lflag &= ~(ECHO);

    // Set modified terminal attributes
    if (tcsetattr(fd, TCSANOW, &new_termios) == -1) {
        perror("tcsetattr");
        return 1;
    }

    printf("Terminal attributes modified successfully.\n");

    return 0;
}
```

In this example, `tcgetattr` is used to get the current terminal attributes, and then the `ECHO` flag is turned off in the `c_lflag` member of the `termios` structure. Finally, `tcsetattr` is used to set the modified terminal attributes immediately (`TCSANOW`). If any function call fails, an error message is printed using `perror`.

---
### Function: `tcgetattr`
#### Description:
The `tcgetattr` function gets the parameters associated with the terminal referred to by the file descriptor `fd` and stores them in the `termios` structure pointed to by `termios_p`.

### Prototype:
```c
int tcgetattr(int fd, struct termios *termios_p);
```

### Parameters:
- `fd`: The file descriptor associated with the terminal.
- `termios_p`: Pointer to a `termios` structure where the terminal attributes will be stored.

### Return Value:
- Returns 0 on success.
- Returns -1 on failure, and `errno` is set to indicate the error.

### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

int main() {
    struct termios current_termios;
    int fd = STDIN_FILENO; // Standard input file descriptor

    // Get current terminal attributes
    if (tcgetattr(fd, &current_termios) == -1) {
        perror("tcgetattr");
        return 1;
    }

    printf("Terminal attributes retrieved successfully.\n");

    return 0;
}
```

In this example, `tcgetattr` is used to get the current terminal attributes associated with standard input (`STDIN_FILENO`). If successful, it prints a message indicating that the terminal attributes have been retrieved. If `tcgetattr` encounters an error, it prints an error message using `perror`.

---
### Function: `tgetent`
#### Description:
The `tgetent` function opens the terminal database file and initializes the termcap routines. It retrieves the entry corresponding to the terminal type specified by `term`, and the entry is stored in the buffer pointed to by `bp`.

### Prototype:
```c
int tgetent(char *bp, const char *term);
```

### Parameters:
- `bp`: Pointer to a buffer where the terminal entry will be stored.
- `term`: Pointer to a null-terminated string specifying the terminal type.

### Return Value:
- Returns 1 if the entry is found and successfully retrieved.
- Returns 0 if the entry is not found.
- Returns -1 on error, and `errno` is set to indicate the error.

### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <termcap.h>

int main() {
    char term_buffer[1024]; // Buffer to store terminal entry
    const char *term_type = "xterm"; // Example terminal type

    // Retrieve the terminal entry for the specified terminal type
    int result = tgetent(term_buffer, term_type);
    if (result == 1) {
        printf("Terminal entry for %s retrieved successfully.\n", term_type);
    } else if (result == 0) {
        printf("Terminal entry for %s not found.\n", term_type);
    } else {
        perror("tgetent");
        return 1;
    }

    return 0;
}
```

In this example, `tgetent` is used to retrieve the terminal entry for the specified terminal type ("xterm"). If successful, it prints a message indicating that the terminal entry has been retrieved. If `tgetent` returns 0, it indicates that the terminal entry was not found. If `tgetent` encounters an error, it prints an error message using `perror`.

---
### Function: `tgetflag`
#### Description:
The `tgetflag` function retrieves the boolean value of a capability flag from the terminal database entry.

### Prototype:
```c
int tgetflag(const char *name);
```

### Parameters:
- `name`: Pointer to a null-terminated string containing the name of the capability flag.

### Return Value:
- Returns 1 if the capability flag is set.
- Returns 0 if the capability flag is not set or the capability is not defined.
- Returns -1 on error, and `errno` is set to indicate the error.

### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <termcap.h>

int main() {
    const char *flag_name = "am"; // Example flag name (Auto-margin)

    // Retrieve the boolean value of the specified capability flag
    int flag_value = tgetflag(flag_name);
    if (flag_value == 1) {
        printf("Capability flag %s is set.\n", flag_name);
    } else if (flag_value == 0) {
        printf("Capability flag %s is not set.\n", flag_name);
    } else {
        perror("tgetflag");
        return 1;
    }

    return 0;
}
```

In this example, `tgetflag` is used to retrieve the boolean value of the capability flag named "am" (Auto-margin). If the capability flag is set, it prints a message indicating that the flag is set. If the capability flag is not set or the capability is not defined, it prints a message indicating that the flag is not set. If `tgetflag` encounters an error, it prints an error message using `perror`.

---
### Function: `tgetnum`
#### Description:
The `tgetnum` function retrieves the numeric value of a capability from the terminal database entry.

### Prototype:
```c
int tgetnum(const char *name);
```

### Parameters:
- `name`: Pointer to a null-terminated string containing the name of the capability.

### Return Value:
- Returns the numeric value of the capability.
- Returns -1 if the capability is not defined or has no numeric value.
- Returns -2 on error, and `errno` is set to indicate the error.

### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <termcap.h>

int main() {
    const char *capability_name = "co"; // Example capability name (Number of columns)

    // Retrieve the numeric value of the specified capability
    int capability_value = tgetnum(capability_name);
    if (capability_value != -1 && capability_value != -2) {
        printf("Value of capability %s: %d\n", capability_name, capability_value);
    } else if (capability_value == -1) {
        printf("Capability %s is not defined or has no numeric value.\n", capability_name);
    } else {
        perror("tgetnum");
        return 1;
    }

    return 0;
}
```

In this example, `tgetnum` is used to retrieve the numeric value of the capability named "co" (Number of columns). If the capability is defined and has a numeric value, it prints the value of the capability. If the capability is not defined or has no numeric value, it prints a message indicating that the capability is not defined. If `tgetnum` encounters an error, it prints an error message using `perror`.

---
### Function: `tgetstr`
#### Description:
The `tgetstr` function retrieves the string value of a capability from the terminal database entry.

### Prototype:
```c
char *tgetstr(const char *name, char **area);
```

### Parameters:
- `name`: Pointer to a null-terminated string containing the name of the capability.
- `area`: Double pointer to a null-terminated string containing the buffer area where the capability string will be stored.

### Return Value:
- Returns a pointer to a null-terminated string containing the capability string.
- Returns NULL if the capability is not defined or has no string value.
- Returns (char *) -1 on error, and `errno` is set to indicate the error.

### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <termcap.h>

int main() {
    const char *capability_name = "cm"; // Example capability name (Cursor motion)

    // Retrieve the string value of the specified capability
    char *capability_string = tgetstr(capability_name, NULL);
    if (capability_string != NULL && capability_string != (char *) -1) {
        printf("String value of capability %s: %s\n", capability_name, capability_string);
    } else if (capability_string == NULL) {
        printf("Capability %s is not defined or has no string value.\n", capability_name);
    } else {
        perror("tgetstr");
        return 1;
    }

    return 0;
}
```

In this example, `tgetstr` is used to retrieve the string value of the capability named "cm" (Cursor motion). If the capability is defined and has a string value, it prints the value of the capability. If the capability is not defined or has no string value, it prints a message indicating that the capability is not defined. If `tgetstr` encounters an error, it prints an error message using `perror`.

---
### Function: `tgoto`

#### Description:
The `tgoto` function instantiates a cursor motion string from the given capability string and supplied parameters.

### Prototype:
```c
char *tgoto(const char *cap, int col, int row);
```

### Parameters:
- `cap`: Pointer to a null-terminated string containing the capability string, typically retrieved using `tgetstr`.
- `col`: The column position.
- `row`: The row position.

### Return Value:
- Returns a pointer to a null-terminated string representing the cursor motion string.
- Returns NULL on error.

### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <termcap.h>

int main() {
    const char *capability_name = "cm"; // Cursor motion capability
    int col = 5; // Column position
    int row = 10; // Row position

    // Retrieve the capability string
    char *capability_string = tgetstr(capability_name, NULL);
    if (capability_string == NULL) {
        perror("tgetstr");
        return 1;
    }

    // Instantiate the cursor motion string
    char *cursor_motion = tgoto(capability_string, col, row);
    if (cursor_motion != NULL) {
        printf("Cursor motion string: %s\n", cursor_motion);
    } else {
        perror("tgoto");
        return 1;
    }

    return 0;
}
```

In this example, `tgoto` is used to instantiate a cursor motion string from the capability string "cm" (Cursor motion) and the supplied column and row positions. If successful, it prints the cursor motion string. If `tgoto` encounters an error, it prints an error message using `perror`.

---
### Function: `tputs`

#### Description:
The `tputs` function sends a string to the terminal or other output stream, performing any padding or delays specified by the terminal capabilities.

### Prototype:
```c
int tputs(const char *str, int affcnt, int (*putc)(int));
```

### Parameters:
- `str`: Pointer to a null-terminated string containing the string to be output.
- `affcnt`: The number of lines affected by the operation (unused in modern implementations, typically set to 1).
- `putc`: Pointer to a function that outputs a character to the desired output stream.

### Return Value:
- Returns `OK` (non-negative value) on success.
- Returns `ERR` (-1) on failure.

### Example Usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include <termcap.h>

int main() {
    const char *capability_name = "cl"; // Clear screen capability

    // Retrieve the capability string
    char *capability_string = tgetstr(capability_name, NULL);
    if (capability_string == NULL) {
        perror("tgetstr");
        return 1;
    }

    // Output the capability string
    if (tputs(capability_string, 1, putchar) == ERR) {
        perror("tputs");
        return 1;
    }

    return 0;
}
```

In this example, `tputs` is used to output the capability string retrieved using `tgetstr` (in this case, the capability to clear the screen). The `putchar` function is provided as the output function to write characters to the standard output. If `tputs` encounters an error, it prints an error message using `perror`.