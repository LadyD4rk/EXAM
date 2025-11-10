#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		chech_char(char *str, char c, int loc)
{
	int		i;

	i = 0;
	while (i < loc)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	union_(char *str, char *src)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		if (chech_char(str, str[i], i) == 0)
			ft_putchar(str[i]);
		i++;
	}
	j = 0;
	while (src[j])
	{
		if (chech_char(str, src[j], i) == 0 
			&& chech_char(src, src[j], j) == 0)
			ft_putchar(src[j]);
		j++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		union_(av[1], av[2]);
	ft_putchar('\n');
	return (0);
}
