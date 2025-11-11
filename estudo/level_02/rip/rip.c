#include <unistd.h>
#include <stdio.h>

void	ft_clean(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ')')
	{
		str[i] = ' ';
		i++;
	}
	while (str[i])
		i++;
	i--;
	while (str[i] == '(')
	{
		str[i] = ' ';
		i--;
	}
}

char	char_check(char *str, int *dif)
{
	int		l_count;
	int		e_count;
	int		i;

	i = 0;
	l_count = 0;
	e_count = 0;
	while (str[i])
	{
		if (str[i] == '(')
			l_count++;
		if (str[i] == ')')
			e_count++;
		i++;
	}
	if (l_count > e_count)
	{
		*dif = l_count - e_count;
		return ('(');
	}
	else if (e_count > l_count)
	{
		*dif = e_count - l_count;
		return (')');
	}
	return ('\0');
}

int	check_print(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '(')
	{
		if (str[i] == ')')
			return (0);
		i++;
	}
	while (str[i])
		i++;
	while (str[i] != ')')
	{
		if (str[i] == '(')
			return (0);
		i--;
	}
	return (1);
}

void	recursive(char *str, char c, int loc, int dif)
{
	if (dif == 0 && check_print(str))
		puts(str);
	while (str[loc])
	{
		if (str[loc] == c)
		{
			str[loc] = ' ';
			dif--;
			recursive(str, c, loc + 1, dif);
			str[loc] = c;
			dif++;
		}
		loc++;
	
	}
}

int	main(int ac, char **av)
{
	int		dif;
	char	c;
	
	if (ac != 2)
		return (1);
	ft_clean(av[1]);
	dif = 0;
	c = char_check(av[1], &dif);
	if (c == '\0')
		puts(av[1]);
	else
		recursive(av[1], c, 0, dif);
	return (0);
}