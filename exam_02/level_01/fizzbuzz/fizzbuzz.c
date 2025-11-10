#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

void	fizzbuzz(int n)
{
	if (n % 3 == 0 && n % 5 == 0)
		write(1, "fizzbuzz", 8);
	else if (n % 3 == 0)
		write(1, "fizz", 4);
	else if (n % 5 == 0)
		write(1, "buzz", 4);
	else
		ft_putnbr(n);
	ft_putchar('\n');
}

int main(void)
{
	int		i;

	i = 1;
	while (i <= 100)
	{
		fizzbuzz(i);
		i++;
	}
}