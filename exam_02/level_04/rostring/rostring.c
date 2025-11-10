#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rostring(char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != ' ' && str[i] != '\t' && str[i] && str[i] != '\0')
		i++;
	j = i;
	while (str[j] == ' ' || str[j] == '\t')
		j++;
	while (str[j])
	{
		while(str[j] != ' ' && str[j] != '\t' && str[j] != '\0')
		{
			ft_putchar(str[j]);
			j++;
		}
		ft_putchar(' ');
		while (str[j] == ' ' || str[j] == '\t')
			j++;
	}
	j = 0;
	while (str[j] == ' ' || str[j] == '\t')
		j++;
	while (j < i)
	{
		ft_putchar(str[j]);
		j++;
	}
}

int	main(int ac, char **av)
{
	if (ac > 1)
		rostring(av[1]);
	ft_putchar('\n');
	return (0);
}
