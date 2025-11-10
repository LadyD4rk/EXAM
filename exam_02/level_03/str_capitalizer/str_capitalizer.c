#include <unistd.h>

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

void	str_capitalizer(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
			i++;
		}
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			i++;
		while (str[i] == ' ' || str[i] == '\t')
			i++;
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
			str_capitalizer(av[i]);
			i++;
		}
	}
	else
		ft_putchar('\n');
	return (0);
}
