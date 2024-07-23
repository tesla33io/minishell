#ifndef GRAMMAR_H
#define GRAMMAR_H

# define COMPLETE_COMMAND "pipe_sequence |pipe_sequence AND complete_command |pipe_sequence OR complete_command |"

# define PIPE_SEQUENCE "command |command PIPE pipe_sequence |"

# define CMD "simple_command |L_BRACE complete_command R_BRACE |"

# define SIMPLE_COMMAND "STR |HEREDOC STR |APPEND STR |IN_REDIRECT STR |OUT_REDIRECT STR |STR simple_command |HEREDOC STR simple_command |APPEND STR simple_command |IN_REDIRECT STR simple_command |OUT_REDIRECT STR simple_command |"


//TODO see if grammar handles weird thingie lap didnt handle before
//TODO handle empty cmd line outside of parsing algo
//TODO build in braces special matching
#endif
