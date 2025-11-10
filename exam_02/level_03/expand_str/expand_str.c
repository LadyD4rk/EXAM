#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	expand_str(char *str)
{
	int		i;
	int		j;

	j = 0;
	while (str[j])
		j++;
	while (str[j] == ' ' || str[j] == '\t' || str[j] == '\0')
		j--;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (i <= j)
	{
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		{
			ft_putchar(str[i]);
			i++;
		}
		if ((str[i] == ' ' || str[i] == '\t') && i < j)
		{
			ft_putchar(' ');
			ft_putchar(' ');
			ft_putchar(' ');
		}
		while (str[i] == ' ' || str[i] == '\t')
			i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		expand_str(av[1]);
	ft_putchar('\n');
	return (0);
}
