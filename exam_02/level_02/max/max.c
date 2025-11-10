int		max(int* tab, unsigned int len)
{
	int		res;
	unsigned int		i;

	i = 0;
	res = tab[i];
	if (len == 0)
		return (0);
	while (i <= len)
	{
		if (tab[i] > res)
			res = tab[i];
		i++;
	}
	return (res);
}
