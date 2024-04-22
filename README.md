# mini~~s~~hell

Allowed functions and usage examples: [Functions.md](/docs/Functions.md)

A shell implementation is divided into two main parts: **The parser** and **the executor**.

---
## The parser

**Lexer** (**Lexical Analysis**) - breaks down the user input into tokens.
**Parser** (**Syntax Analysis**) - checks if the tokens form a valid command structure.

1. Get input as string (e.g. `ls -l *.c`)
2. Tokenization of input
	`ls -l *.c`  splited into tokens like `['ls', '-l', '*.c']`.
3. Validate tokens.
4. Prepare a _Command Table_ for future executing.

---
## The executor

 Need to come up with some good _Command Table_ (list of `command` structs?) implementation.
 _Command Table_ will serve as a data-bridge between parsing and executing parts.
 The parser will put all information about what should be executed along with some instructions about how command should be executed.

> [!NOTE]
 > Each command should be executed in separate child process and exit status should be handled appropriately.
 > Exception: some built-ins (e.g. `cd`, `export`, `unset` etc.)

1. Get a command from _Command Table_.
2. Check if it's a built-in command (execute appropriate function if `true`).
3. Check if the command provided is not a _path_.
	1. If it is not a _path_ look in `$PATH`
	2. Otherwise check if provided _path_ leads to existing executable (check permissions).
4. If executable is in `$PATH` replace initial command string with path to this executable (e.g. `ls` -> `/bin/ls`)
5. Try to `execve(exe_path, args, environ)`
6. Save exit status

---
## Built-ins

A **struct** that consists of two elements, the name of the command (_builtin_) and **a pointer to the appropriate function.** (?)

1. `echo` with `-n` support (maybe some other arguments)
2. `cd` (only relative or absolute path)
3. `pwd`
4. `export`
5. `unset`
6. `env`
7. `exit`

## Bonuses

`&&` and `||` are logical operators used for control flow by combining commands.
They're called "AND" and "OR" operators, respectively, and they allow for conditional execution of commands based on the success or failure of previous commands.

#### `&&` (AND Operator)

The `&&` operator allows to **execute a command or series of commands only if the preceding command succeeds** (i.e., exits with a status of 0, which signals success in Unix/Linux environments).

**Syntax:**

```shell
command1 && command2
```

**Explanation:** `command2` is executed if, **and only if**, `command1` **returns an exit status of 0** (success).

**Example:**

```shell
mkdir new_directory && cd new_directory
```

In this example, `cd new_directory` is executed only if `mkdir new_directory` successfully creates the directory.

#### `||` (OR Operator)

Conversely, the `||` operator allows to **execute a command or series of commands only if the preceding command fails** (i.e., exits with a non-zero status, which signals an error or failure).

**Syntax:**

```shell
command1 || command2
```

**Explanation:** `command2` is **executed if** `command1` **returns a non-zero exit status** (indicating failure).

**Example:**

```shell
gcc program.c || echo "Compilation failed."
```

In this example, `"Compilation failed."` is printed to the console only if `gcc program.c` (the attempt to compile `program.c`) fails.

#### `*` Wildcards

Shell wildcards, also known as _globbing_ patterns, are special characters used in the Linux shell to match multiple filenames or paths based on a specific pattern. They offer a powerful way to avoid listing every filename individually when working with the shell.

**Common Wildcards:**
- **Asterisk (\*):** Represents zero or more characters.
	- Example: `ls *txt` - Lists all files ending with ".txt".
- **Question mark (?):** Represents a single character.
	- Example: `cp f?le.txt backup` - Copies all files starting with "f" and ending with ".txt" to "backup" directory (assuming only one character between 'f' and '.txt').
- **Square brackets (\[\]):** Enclose a set of characters for matching one character within the brackets.
	- Example: `mv [0-9]*.txt documents` - Moves all files starting with a number (0-9) and ending with ".txt" to the "documents" directory.

**Things to know about shell wildcards:**
- **Order matters:** Wildcards are expanded from left to right.
- **Escaping:** Use a backslash () before a special character to treat it literally. For example, `\*` matches the literal character "\*".
- **Quotes:** Enclosing the pattern in single quotes preserves the literal meaning of all characters, including wildcards. This is useful when the filename itself contains wildcard characters.

## Useful resources

[Chapter5-WritingYourOwnShell](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)

[`> file` vs `>& file`](https://g.co/gemini/share/18247f4d0570)

