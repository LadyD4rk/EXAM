#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		check_char(char *str, char c, int loc)
{
	int		i;

	i = 0;
	while(i < loc)
	{
		if(str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	inter(char *str, char *src)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (src[j])
		{
			if (str[i] == src[j] && check_char(str, str[i], i) == 0)
			{
				ft_putchar(str[i]);
				break;
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		inter(av[1], av[2]);
	ft_putchar('\n');
	return (0);
}