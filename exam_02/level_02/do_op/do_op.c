#include <stdio.h>
#include <stdlib.h>

void	do_op(int num1, char *sig, int num2)
{
	int		res;

	res = 0;
	if (sig[0] == '+')
		res = num1 + num2;
	else if (sig[0] == '-')
		res = num1 - num2;
	else if (sig[0] == '*')
		res = num1 * num2;
	else if (sig[0] == '/')
		res = num1 / num2; 
	else if (sig[0] == '%')
		res = num1 % num2;
	printf("%i", res);
}

int	main(int ac, char **av)
{
	if (ac == 4)
		do_op(atoi(av[1]), av[2], atoi(av[3]));
	printf("\n");
	return (0);
}
