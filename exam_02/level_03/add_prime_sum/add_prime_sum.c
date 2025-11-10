#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int num)
{
	if (num > 9)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + '0');
}

int		ft_atoi(char *str)
{
	int		i;
	int		sig;
	int		res;

	i = 0;
	res = 0;
	sig = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sig);
}

int		prime(int num)
{
	int		div;
	int		res;

	div = 2;
	res = 1;
	while (div <= num)
	{
		if (num % div == 0)
			res++;
		div++;
	}
	if (res == 2)
		return (1);
	return (0);
}

void	add_prime_sum(int num)
{
	int		res;

	if (num <= 0)
	{
		ft_putnbr(0);
		return ;
	}
	res = 0;
	while (num > 1)
	{
		if (prime(num) == 1)
			res = res + num;
		num--;
	}
	ft_putnbr(res);
}

int	main(int ac, char **av)
{
	int		num;

	if (ac == 2)
	{
		num = ft_atoi(av[1]);
		add_prime_sum(num);
		ft_putchar('\n');
	}
	else
	{
		ft_putchar('0');
		ft_putchar('\n');
	}
	return (0);
}
