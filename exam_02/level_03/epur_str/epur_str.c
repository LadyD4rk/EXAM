#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	eput_str(char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	j = ft_strlen(str);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\0')
		j--;
	while (i < j)
	{
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		{
			ft_putchar(str[i]);
			i++;
		}
		if ((str[i] == ' ' || str[i] == '\t') && i < j - 1)
			ft_putchar(' ');
		while(str[i] == ' ' || str[i] == '\t')
			i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		eput_str(av[1]);
	ft_putchar('\n');
	return (0);
}
