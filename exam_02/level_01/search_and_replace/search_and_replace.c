#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	search_and_replace(char *str, char *a, char *x)
{
	int		i;

	i = 0;
	if (a[1] != '\0' || x[1] != '\0')
		return ;
	while(str[i])
	{
		if (str[i] == a[0])
			str[i] = x[0];
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 4)
		search_and_replace(av[1], av[2], av[3]);
	ft_putchar('\n');
	return (0);
}
