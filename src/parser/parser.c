#include "minishell.h"

//TODO handle pair terminals
//split up/shorten ft 

char *match_alternative(t_lex *lexer, char *production, char *alternative, int *non_terminals) //alternative is null at first, wont change in case of no match
{
	int i;
	char *tmp;
	char *symbol; //the non-terminals and terminals within an alternative are called symbols, basically it is an umbrella term for terminals and non-terminals
	t_token *travel;

	i = -1;
	tmp = ft_strdup(production);
	symbol = NULL;
	while (contains_c(tmp, ' ')) //how will this be fucked with pair terminals?
	{
		symbol = ft_chop(tmp, ' ');
		if (contains_non_terminal(symbol))
			(*non_terminals)++; 
		else if (contains_terminal(symbol)) 
		{
			travel = lexer->head;
			while (++i < lexer->tkn_count)
			{
				if (travel->token == (t_tkntype)symbol && lexer->unmatched-- && ++travel->matched)
					break ;
				travel = travel->next;
			}
			if (travel->token != (t_tkntype)symbol)
				return (alternative);
		}	
	}
	if (*non_terminals > lexer->unmatched)
		return (alternative);
	else if (!contains_terminal(production) || travel->token == (t_tkntype)symbol)
		return (production);
}

//TODO
//init ast in init ft
//split up ft

void	terminal_to_leaf(t_ast *ast, t_leaf *parent, t_token *token_stream) //problem with looping, yeah i have pointer to from where to loop but then its a bit fucked bc the actual thing is the tkn finding for terminal
{
	t_token *travel;
	t_token *ret;

	travel = token_stream;
	ret = NULL;
	while (travel)
	{
		if (travel->matched)
			if (!parent)
			{
				ast->root = malloc(sizeof(*t_leaf))
				ast->root->token = travel->token;
				ast->root->terminal = travel->lexeme;
				ast->root->parent = NULL;
				ast->root->left = NULL;
				ast->root->right = NULL;
				ret = ast->root;

			}
			else if (!parent->left)
			{
				parent->left = malloc(sizeof(*t_leaf));
				parent->left->token = travel->token;
				parent->left->terminal = travel->lexeme;
				parent->left->parent = parent;
				parent->left->left = NULL;
				parent->left->right = NULL;
				ret = parent->left;

			}
			else
			{
				parent->right = malloc(sizeof(*t_leaf));
				parent->right->token = travel->token;
				parent->right->terminal = travel->lexeme;
				parent->right->parent = parent;
				parent->right->left = NULL;
				parent->right->right = NULL;
				ret = parent->right;
			}
			travel->token = TRASH;
		}
		travel = travel->next;
	}
	take_out_trash(token_stream);
	return (ret);
}

//input for token stream is head of lexer, parent input is null at first

t_token *split_stream(t_token **token_stream)
{
	t_token *travel;
	t_token *ret;

	travel = *(tokenstream);
	while (travel->token && travel->token == TRASH)
		travel = travel->next;
	ret = travel;
	*token_stream = travel;
	while (travel && travel->next != TRASH)
		travel = travel->next;
	*token_stream = travel;
	while (*token_stream && *token_stream == TRASH)
		*token_stream == *token_stream->next;
	travel->next = NULL;
	return (ret);
}

int	ft_parse(t_shell_data *shell_data, char *production, t_leaf *parent, t_token *token_stream)
{
	char *alternative;	//within a production rule, when theres multiple possibilities that are valid for a production rule, they are called alternatives
	int *non_terminals;
	char *symbol;

	alternative = NULL;
	if (!production) //condition to end recursion
		return ;
	while (contains_c(production, '|')) // keep launching match on next part of grammar
		alternative = match_alternative(lexer, ft_chop(production, '|'), alternative, non_terminals); //return valid alternative
	if (!alternative) 
	{
		if (parent == shell_data->ast->root)
			printf("Syntax Error\n"); 
		else
			print("Syntax Error near token "%s"\n", parent->terminal);
	}
	parent = terminal_to_leaf(shell_data->ast, parent, token_stream);
	while (*non_terminals-- && contains_c(alternative, ' '))
	{
		symbol = ft_chop(alternative, ' ');
		if (contains_non_terminal(symbol))
			return (ft_parse(shell_data, str_capitalize(symbol), parent, split_stream(&token_stream)));
	}
}
