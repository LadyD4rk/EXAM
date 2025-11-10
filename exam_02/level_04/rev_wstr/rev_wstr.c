#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rev_wstr(char *str)
{
	int		i;
	int		j;
	int		m;

	j = 0;
	while (str[j])
		j++;
	j--;
	while (j > 0)
	{
		i = j;
		while (str[i] != ' ' && i > 0)
			i--;
		m = i - 1;
		if (str[i] == ' ')
			i++;
		while (i <= j && str[i] != '\0')
		{
			ft_putchar(str[i]);
			i++;
		}
		j = m;
		if (j > 0)
			ft_putchar(' ');
	}
/* 	printf("i: '%c'\n", str[i]);
	printf("j :'%c'\n", str[j]);
	printf("m :'%c'\n", str[m]); */
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	ft_putchar('\n');
	return (0);
}
