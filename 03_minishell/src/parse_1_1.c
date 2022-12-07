#include "minishell.h"

static int	check_quotes(char *line, char quote, int *i)
{
	while (line[*i] != '\0')
	{
		if (line[*i] == quote)
			return (EXIT_SUCCESS);
		(*i)++;
	}
	token_error("ppsh: syntax error near unexpected token", quote);
	g_data.exit_status = 2;
	return (EXIT_FAILURE);
}

int	add_quote_str(t_lst **line_lst, char *line, int *i)
{
	char	quote;
	int		tmp;
	char	*str;

	quote = line[(*i)++];
	tmp = *i;
	if (check_quotes(line, quote, i))
		return (EXIT_FAILURE);
	if ((*i - tmp) != 0)
	{
		str = ft_substr(line, tmp, *i - tmp);
		if (quote == '"')
			pp_lstadd_back(line_lst, pp_lstnew(str, D_QUOTE));
		else
			pp_lstadd_back(line_lst, pp_lstnew(str, S_QUOTE));
	}
	return (EXIT_SUCCESS);
}

void	add_redir_pipe(t_lst **line_lst, char *line, int *i)
{
	if (line[*i] == '<' && line[(*i) + 1] == '<')
	{
		(*i)++;
		pp_lstadd_back(line_lst, pp_lstnew(ft_strdup("<<"), HEREDOC));
	}
	else if (line[*i] == '>' && line[(*i) + 1] == '>')
	{
		(*i)++;
		pp_lstadd_back(line_lst, pp_lstnew(ft_strdup(">>"), APPEND));
	}
	else if (line[*i] == '<')
		pp_lstadd_back(line_lst, pp_lstnew(ft_strdup("<"), REDIRIN));
	else if (line[*i] == '>')
		pp_lstadd_back(line_lst, pp_lstnew(ft_strdup(">"), REDIROUT));
	else if (line[*i] == '|')
		pp_lstadd_back(line_lst, pp_lstnew(ft_strdup("|"), PIP));
}

void	add_arg(t_lst **line_lst, char *line, int *i)
{
	char	*str;
	int		tmp;

	tmp = *i;
	while (line[*i] != '\0')
	{
		if (line[*i] == ' ' || line[*i] == '\\' || line[*i] == ';' \
		|| line[*i] == '"' || line[*i] == '\'' \
		|| line[*i] == '<' || line[*i] == '>' || line[*i] == '|')
			break ;
		(*i)++;
	}
	if ((*i - tmp) != 0)
	{
		str = ft_substr(line, tmp, (*i) - tmp);
		pp_lstadd_back(line_lst, pp_lstnew(str, ARG));
	}
	(*i)--;
}
