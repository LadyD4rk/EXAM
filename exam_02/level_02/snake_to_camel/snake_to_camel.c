#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	snake_to_camel(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '_')
		{
			i++;
			str[i] = str[i] - 32;
		}
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		snake_to_camel(av[1]);
	ft_putchar('\n');
	return (0);
}
