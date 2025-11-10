#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	last_word(char *str)
{
	int		i;

	i = 0;
	while(str[i])
		i++;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\0')
		i--;
	while (str[i] != ' ' && str[i] != '\t')
		i--;
	i++;
	while (str[i] != ' ' && str[i] != '\t' && str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		last_word(av[1]);
	ft_putchar('\n');
	return (0);
}