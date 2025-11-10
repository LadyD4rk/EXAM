#include <stdio.h>
#include <stdlib.h>

void	fprime(int num)
{
	int		div;

	if (num == 1)
	{
		printf("1");
		return ;
	}
	div = 2;
	while (num >= div)
	{
		while (num % div == 0)
		{
			num = num / div;
			printf("%i", div);
			if (num > div)
				printf("*");
			if (num % div != 0)
				break;
		}
		div++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		fprime(atoi(av[1]));
	printf("\n");
	return (0);
}