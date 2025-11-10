void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				tem;

	if (size < 2)
		return ;
	while (size > 0)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tem = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tem;
			}
			i++;
		}
		size--;
	}
}
