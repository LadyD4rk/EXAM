#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rotone(char *str)
{
	int		i;

	i = 0;
	while(str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'y')
			|| (str[i] >= 'A' && str[i] <= 'Y'))
			str[i] = str[i] + 1;
		else if (str[i] == 'z' || str[i] == 'Z')
			str[i] = str[i] - 25;
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rotone(av[1]);
	ft_putchar('\n');
	return (0);
}
