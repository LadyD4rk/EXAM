#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	alpha_mirror(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'm')
			str[i] = ('m' - str[i]) + 'n';
		else if (str[i] >= 'A' && str[i] <= 'M')
			str[i] = ('M' - str[i]) + 'N';
		else if (str[i] >= 'n' && str[i] <= 'z')
			str[i] = ('z' - str[i]) + 'a';
		else if (str[i] >= 'N' && str[i] <= 'Z')
			str[i] = ('Z' - str[i]) + 'A';
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		alpha_mirror(av[1]);
	ft_putchar('\n');
	return (0);
}
