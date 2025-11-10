int		check_char(char c, int base)
{
	char	*low;
	char	*upper;
	int		i;

	low = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	i = 0;
	while (i < base)
	{
		if (c == low[i] || c == upper[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int		i;
	int		res;
	char	*num;
	int		sig;

	i = 0;
	num = (char *)str;
	res = 0;
	sig = 1;
	while ((num[i] >= 9 && num[i] <= 13) || str[i] == ' ')
		i++;
	if (num[i] == '-' || num[i] == '+')
	{
		if (num[i] == '-')
			sig *= -1;
		i++;
	}
	while (num[i])
	{
		if (check_char(num[i], str_base) == 0)	
			break;
		if (num[i] >= '0' && num[i] <= '9')
			res = (res * str_base) + (num[i] -'0');
		else if (num[i] >= 'a' && num[i] <= 'f')
			res = (res * str_base) + (10 + num[i] - 'a');
		else if (num[i] >= 'A' && num[i] <= 'F')
			res = (res * str_base) * (10 + num[i] - 'A');
		else
			break;
		i++;
	}
	return(res * sig);
}
