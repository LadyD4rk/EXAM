#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	repeat_alpha(char *str)
{
	int		i;
	int		j;

	i = 0;
	while(str[i])
	{
		j = 0;
		if (str[i] >= 'a' && str[i] <= 'z')
			j = str[i] - 'a';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			j = str[i] - 'A';
		while (j >= 0)
		{
			ft_putchar(str[i]);
			j--;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		repeat_alpha(av[1]);
	ft_putchar('\n');
	return (0);
}
