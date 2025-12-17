// ! Allowed functions: puts, write

#include <stdio.h>

void	clear_str(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '(')
		if(str[i] == ')')	
			str[i++] = ' ';
	while (str[i])
		i++;
	i--;
	while (str[i] != ')')
		if (str[i] == '(')
			str[i--] = ' ';
}

char	count_quote(char *str, int *count)
{
	int		i;
	int		open; // '('
	int		close; // ')'

	i = 0;
	open = 0;
	close = 0;
	while (str[i])
	{
		if (str[i] == '(')
			open++;
		if (str[i] == ')')
			close++;
		i++;
	}
	if (open > close)
	{
		*count = open - close;
		return ('(');
	}
	if (close > open)
	{
		*count = close - open;
		return (')');
	}
	return ('\0');
}

int		check_quote(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '(')
	{
		if (str[i] == ')')
			return (0);
		i++;
	}
	while (str[i])
		i++;
	i--;
	while(i > 0 && str[i] != ')')
	{
		if (str[i] == '(')
			return (0);
		i--;
	}
	return (1);
}

int		check_line(char *str)
{
	int		open;
	int		close;
	int 	i;

	i = 0;
	open = 0;
	close = 0;
	while (str[i])
	{
		if (str[i] == '(')
			open++;
		if (str[i] == ')')
			close++;
		if (close > open)
			return (0);
		i++;
	}
	return (1);
}

void	rip(char *str, char quote, int limit, int i)
{
	if (limit == 0 && check_quote(str) && check_line(str))
		puts(str);
	else
	{
		while (str[i])
		{
			if (str[i] == quote)
			{
				str[i] = ' ';
				limit--;
				rip(str, quote, limit, i + 1);
				limit++;
				str[i] = quote;
			}
			i++;
		}
	}
}

int main(int ac, char **av)
{
	char	quote;
	int		count;
	
	if (ac != 2)
		return (1);
	clear_str(av[1]);
	count = 0;
	quote = count_quote(av[1], &count);
	if (quote == '\0')
		puts(av[1]);
	rip(av[1], quote, count, 0);
	return (0);
}
