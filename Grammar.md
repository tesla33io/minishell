# Grammar

 - A grammar is a way to **express the syntactic structure** of a (programming/natural) language formally
 - It will **identify the different components** of Bash, such as commands, variables, control structures and built-ins 
 &rarr; structured framework
 - By parsing according to a grammar, you can **validate** whether **the input** conforms to the defined syntax 
 &rarr; error checking/syntax validation will be based on the grammar
 
 
 

# Terminology

 1.  **Constants/Terminals/Terminal Symbols**
> Terminals are the **base tokens** of a language. They are the **smallest unit of meaning** that cannot be further divided within the context of the grammar. For a programming language that might be: Keywords, Operators and other symbols, the characters that can be used in identifiers, numbers, or other program elements.
> An Example in the English language could be: `I`, `am`, `an`, `Example` (&rarr; the actual words themself).
>
> Examples for bash:
> 
> &rarr; **Keywords**, such as: `if`, `else`, `elif`, `fi`, `for`, `while`, `do`, `done`, `case`, `esac`, `function`
> 
> &rarr; **Arithmetic operators**: `+`, `-`, `*`, `/`, `%`
>
> &rarr; **Comparison operators**: `==`, `!=`, `-eq`, `-ne`, `-lt`, `-le`, `-gt`, `-ge` (equality, inequality, numeric equality, numeric inequality, less than, less than or equal, greater than, greater than or equal)
>
> &rarr; **Literals**: numeric literals `123`, `-5`, `3.14`, string literals `"hello"`, `'world'` and special literals `true`, `false`, `null`
>
> &rarr; **Special characters**: `$` (variable expansion), `#` (comment), `;` (command separator), `,` (list separator), `(` and `)` (grouping), `[` and `]` (test command), `{` and `}` (command grouping), `"` and `'` (quoting)
 

 2. **Variables/Nonterminals/Nonterminal Symbols**
    
> A symbol in a formal grammar that cannot appear in sentences of the grammar but may eventually be resolved into a sequence of terminal symbols. Basically nonterminals are categories of the grammar for which rules will be defined. An example in the english language for nonterminals could be: `Noun`, `Verb`, `Sentence`, `Verb phrase` etc.
> 
>**Command**: Represents a single executable command that can be invoked on the command line. This could include built-in commands like `echo`, `cd`, `pwd`, or external commands like `ls`, `grep`, `cat`, etc.
> 
>**Argument**: Represents an argument provided to a command on the command line. Arguments can be options, flags, filenames, or any other data required by the command.
> 
>**Option**: Represents an option or flag that modifies the behavior of a command. Options are typically preceded by a dash (`-`) or a double dash (`--`).
> 
> **Pipeline**: Represents a sequence of commands connected by pipe (`|`) operators. A pipeline allows the output of one command to be used as the input for another command.
> 
>**Redirection**: Represents the redirection of input or output streams for a command. This could include symbols like `<` (input redirection), `>` (output redirection), `>>` (append output redirection), or `|` (pipe redirection).
> 
>**Variable Expansion**: Represents the expansion of variables within command arguments or strings. This could include constructs like `$variable` or `${variable}` used to access the value of a variable.
> 
>**Command Substitution**: Represents the substitution of command output into a command line. This could include constructs like `$(command)` or `` `command` `` used to execute a command and replace it with its output.
> 
>**Quoting**: Represents the quoting of characters to prevent their special interpretation by the shell. This could include single quotes (`'`) or double quotes (`"`) used to enclose strings.

3. **Production/Production Rules**
> These are the rules that make up the grammar. They connect the nonterminals and terminals. Each rule is going to translate a nonterminal into a sequence of one or more nonterminals or terminals. Example with the english language:
> 
> &rarr; `A sentence is a noun phrase followed by a verb phrase`
> 
> &rarr; `A verb phrase is a verb or a verb followed by a noun phrase`
> 
> &rarr; `A verb is one of a list of words (the terminals that can be used as verbs`

# Backus-Naur Form
BNF is a **notation technique** used to describe the syntax of programming languages and other formal languages. It consists of a set of production rules that **define how valid language constructs can be formed**. 

 How its done:

**&rarr; Nonterminals are enclosed in angle brackets ( `<command>`).**

**&rarr; Terminals are simply written out (`"hello world"`)**

**&rarr; Productions are in the form: `<nonterminal> : : = <sequence of terminals or nonterminals>`**

**&rarr; We can use `|` ro represent or**

---
Simple example:

`<digit> : : = 0 |1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9`

`<integer> : : = <digit> | <digit><integer>`

`<floating point> : : = <integer>.<integer>`

---


---
(Incomplete) example based on bash:


`<command_line> ::= <command> | <pipeline>`

> &rarr;   `<command_line>` represents a single command or pipeline of commands.

`<command> ::= <simple_command> | <compound_command>`

> &rarr;  `<command>` can be either a simple command (e.g., `ls -l`) or a compound command (e.g., `if`, `while`, `for`).

`<simple_command> ::= <command_name> [<arguments>]`

> &rarr;   `<simple_command>` consists of a command name followed by optional arguments.

`<compound_command> ::= <if_statement> | <while_loop> | <for_loop> | ...`

> &rarr;   `<compound_command>` represents more complex command constructs like `if` statements, `while` loops, `for` loops, etc.

`<arguments> ::= <argument> [<arguments>]`

> &rarr;   `<arguments>` represents a list of command arguments.

`<argument> ::= <string_literal> | <variable_expansion> | ...`

> &rarr;   `<argument>` can be a string literal, a variable expansion, or other possible types of arguments.

`<pipeline> ::= <command> "|" <command> ...`

---


Grammars in general tend to be inherently recursive. This is true about our natural language as well as programming languages. 
[Bash Grammar](https://cmdse.github.io/pages/appendix/bash-grammar.html)
# Lexical vs. phrase structure
1.  **Lexical Grammar**: This defines the basic tokens or lexemes of the language. In the context of a shell, these might include things like commands (`ls`, `cd`, etc.), arguments (file names, options like `-l`, etc.), special characters (like `>`, `<`, `|` for redirection and piping), and others.
    
2.  **Phrase Grammar (Syntactic Grammar)**: This defines the structure of valid statements or commands in the language. It describes how these tokens from the lexical grammar can be combined to form meaningful statements. For a shell, this would involve rules for constructing commands, handling arguments, managing redirections, and piping.
    
Separating lexical and phrase grammars allows for a more modular approach to parsing, they are commonly seperated because grammars for both get very complex. 

&rarr; The lexical analysis phase breaks down the input into tokens, and the phrase analysis phase constructs the hierarchical structure of the input based on those tokens. 

&rarr; For minishell, defining both lexical and phrase grammars will be crucial for implementing the parser that interprets user commands.
