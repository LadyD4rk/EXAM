#include <stdio.h>
#include <stdlib.h>

void	pgcd(int num1, int num2)
{
	int		div;
	int		res;

	div = 2;
	res = 1;
	while (num1 >= div && num2 >= div)
	{
		while (num1 % div == 0 && num2 % div == 0)
		{
			num1 = num1 / div;
			num2 = num2 / div;
			res = res * div;
			if (num1 % div != 0 || num2 % div != 0)
				break;
		}
		div++;
	}
	printf("%i", res);
}

int	main(int ac, char **av)
{
	if (ac == 3)
		pgcd(atoi(av[1]), atoi(av[2]));
	printf("\n");
	return (0);
}