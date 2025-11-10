#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	hidenp(char *str, char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && src[j])
	{
		if (str[i] == src[j])
		{
			i++;
			j++;
		}
		else
			j++;
	}
	if (str[i] == '\0')
		ft_putchar('1');
	else
		ft_putchar('0');
}

int	main(int ac, char **av)
{
	if (ac == 3)
		hidenp(av[1], av[2]);
	ft_putchar('\n');
	return (0);
}
