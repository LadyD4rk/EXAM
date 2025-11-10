#include <stdlib.h>

int		ft_len_num(int num)
{
	int		i;

	if (num == 0)
		return (1);
	i = 0;
	if (num < 0)
	{
		i++;
		num *= -1;
	}
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		i;

	i = ft_len_num(nbr);
	if (nbr == -2147483648)
		return ("-2147483648");
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	str[i] = '\0';
	i--;
	while(nbr > 0)
	{
		str[i] = (nbr % 10) + '0';
		nbr /= 10;
		i--;
	}
	return (str);
}
