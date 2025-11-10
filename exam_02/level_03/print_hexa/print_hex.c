#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while(str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
}

void	print_hexa(int num)
{
	if (num > 15)
		print_hexa(num / 16);
	write(1, &"0123456789abcdef"[num % 16], 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		print_hexa(ft_atoi(av[1]));
	ft_putchar('\n');
	return (0);
}
