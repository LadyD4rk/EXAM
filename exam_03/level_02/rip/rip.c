#include <stdio.h>
#include <unistd.h>

void	clear_str(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '(')
	{
		str[i] = ' ';
		i++;
	}
	while (str[i] != '\0')
		i++;
	i--;
	while (i > 0 && str[i] != ')')
	{
		str[i] = ' ';
		i--;
	}
}

char	check_quote(char *str, int *count)
{
	int		left; // (
	int		right; // )
	int		i;

	i = 0;
	left = 0;
	right = 0;
	while(str[i])
	{
		if (str[i] == '(')
			left++;
		else if (str[i] == ')')
			right++;
		i++;
	}
	if (left > right)
	{
		*count = left - right;
		return ('(');
	}
	else if (right > left)
	{
		*count = right - left;
		return (')');
	}
	return ('\0');
}

int		check_line(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '(' && str[i])
	{
		if (str[i] == ')')
			return (0);
		i++;
	}
	while (str[i])
		i++;
	i--;
	while (i > 0 && str[i] != ')')
	{
		if (str[i] == '(')
			return (0);
		i--;
	}
	int		left; // (
	int		right; // (((((())(((())(())))

	i = 0;
	left = 0;
	right = 0;
	while(str[i])
	{
		if (str[i] == '(')
			left++;
		else if (str[i] == ')')
			right++;
		else if (right > left)
			return (0);
		i++;
	}
	return (1);
}

void	rip(char *str, char quote, int loc, int dif)
{
	if (dif == 0 && check_line(str))
		puts(str);
	while (str[loc])
	{
		if (str[loc] == quote)
		{
			str[loc] = ' ';
			dif--;
			rip(str, quote, loc + 1, dif);
			str[loc] = quote;
			dif++;
		}
		loc++;
	}
}

int	main(int ac, char **av)
{	
	char	quote;
	int		count_pair;
	
	if (ac != 2)
		return (1);
	clear_str(av[1]);
	count_pair = 0;
	quote = check_quote(av[1], &count_pair);
	if (quote == '\0')
		puts(av[1]);
	else
		rip(av[1], quote, 0, count_pair);
	return (0);
}
