#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	rstr_capitalizer(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	i = ft_strlen(str) - 1;
	while (i > 0)
	{
		while (str[i] == ' ' || str[i] == '\t')
			i--;
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			i--;
	}
	ft_putstr(str);
	ft_putchar('\n');
}

int	main(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac > 0)
	{
		while (i < ac)
		{
			rstr_capitalizer(av[i]);
			i++;
		}
	}
	else
		ft_putchar('\n');
	return (0);
}
