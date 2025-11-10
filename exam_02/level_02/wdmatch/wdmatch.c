#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	wdmatch(char *str, char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i])
	{
		if (str[j] ==src[i])
		{
			j++;
			i++;
		}
		else
			i++;
	}
	if (str[j] == '\0')
	{
		j = 0;
		while (str[j])
		{
			ft_putchar(str[j]);
			j++;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		wdmatch(av[1], av[2]);
	ft_putchar('\n');
	return (0);
}
