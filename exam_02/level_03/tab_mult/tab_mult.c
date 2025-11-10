#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_atoi(char *str)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
}

void	ft_putnbr(int num)
{
	if (num > 9)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + '0');
}

void	tab_mult(int num)
{
	int		i;

	i = 1;
	while (i <= 9)
	{
		ft_putnbr(i);
		ft_putchar(' ');
		ft_putchar('x');
		ft_putchar(' ');
		ft_putnbr(num);
		ft_putchar(' ');
		ft_putchar('=');
		ft_putchar(' ');
		ft_putnbr(num * i);
		ft_putchar('\n');
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		tab_mult(ft_atoi(av[1]));
	else
		ft_putchar('\n');
	return (0);
}
