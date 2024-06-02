#ifndef GRAMMAR_H
#define GRAMMAR_H

#define COMPLETE_COMMAND "pipe_sequence | pipe_sequence AND complete_command | pipe_sequence OR complete_command"
#define PIPE_SEQUENCE "command | command PIPE pipesequence"
#define COMMAND "simple_command | L_BRACE complete_command R_BRACE"
#define SIMPLE_COMMAND* "WORD | HEREDOC WORD | APPEND WORD | IN_REDIRECT WORD | OUT_REDIRECT WORD | WORD simple_command| HEREDOC WORD simple_command | APPEND WORD simple_command| IN_REDIRECT WORD simple_command | OUT_REDIRECT WORD simple_command"

#endif
