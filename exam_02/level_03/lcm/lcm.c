#include <stdio.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int	div;
	int		res;

	div = 2;
	res = 1;
	if (a == 0 || b == 0)
		return (0);
	while (a >= div && b >= div)
	{
		while (a % div == 0 && b % div == 0)
		{
			a = a / div;
			b = b / div;
			res = div * res;
			if (a % div != 0 || b % div != 0)
				break;
		}
		div++;
	}
	div = 2;
	while (a >= div)
	{
		while (a % div == 0)
		{
			a = a / div;
			res = res * div;
			if (a % div != 0)
				break;
		}
		div++;
	}
	div = 2;
	while (b >= div)
	{
		while (b % div == 0)
		{
			b = b / div;
			res = res * div;
			if (b % div != 0)
				break;
		}
		div++;
	}
	return (res);
}

int main(void)
{
    // Casos básicos
    printf("lcm(2, 3) = %u (esperado: 6)\n", lcm(2, 3));
    printf("lcm(4, 6) = %u (esperado: 12)\n", lcm(4, 6));
    printf("lcm(5, 10) = %u (esperado: 10)\n", lcm(5, 10));

    // Casos iguais
    printf("lcm(7, 7) = %u (esperado: 7)\n", lcm(7, 7));
    printf("lcm(12, 12) = %u (esperado: 12)\n", lcm(12, 12));

    // Caso com número primo
    printf("lcm(13, 17) = %u (esperado: 221)\n", lcm(13, 17));

    // Casos com zero
    printf("lcm(0, 5) = %u (esperado: 0)\n", lcm(0, 5));
    printf("lcm(7, 0) = %u (esperado: 0)\n", lcm(7, 0));
    printf("lcm(0, 0) = %u (esperado: 0)\n", lcm(0, 0));

    // Casos maiores
    printf("lcm(21, 6) = %u (esperado: 42)\n", lcm(21, 6));
    printf("lcm(100, 25) = %u (esperado: 100)\n", lcm(100, 25));
    printf("lcm(72, 120) = %u (esperado: 360)\n", lcm(72, 120));

    return 0;
}
