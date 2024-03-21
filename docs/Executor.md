# Plan

### 1. Check executable
Check if the received information about a command is valid.

Check whether the command is **shell built-in**, an **absolute/relative path to the executable** or an **executable in the `$PATH`**.

> **Q**: _does shell execute built-ins the same way as other commands?_
> **A**: [Link_1](https://unix.stackexchange.com/a/11465), 

### 2. Check I/O redirection's
If a command has any I/O redirection's, that means that output goes to the file and not to the pipe or `stdout`.

If there are multiple OUT-redirection's shell should create all files but the output is written only in the last.

If there are multiple IN-redirection's shell should ignore all redirection's except the last one (`bash` behavior, in `zsh` all files goes to the command), the content of the last redirection goes to the command.
If the input file is invalid (wrong permission, non-existing, etc.) an error is displayed.

### 3. Check pipes
In case the command is a part of the pipeline, executor should setup an inter-process communication (IPC).
Each part of the pipeline will be executed in a separate child process (except built-ins ?).
All parts of the pipeline will be executed simultaneously.
If one of the pipeline parts fails, ignore and execute everything else.
According to `bash`, the exit code of a pipeline should be an exit code of the last (right-most) command ([link](https://unix.stackexchange.com/a/14276)).